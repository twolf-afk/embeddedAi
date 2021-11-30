/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lsm6dsl.h"
#include "b_l475e_iot01a1_bus.h"
#include "ai_platform.h"
#include "network.h"
#include "network_data.h"

#include "Uart/uart1.h"
#include "CRC/crc.h"
#include "GPIO/gpio.h"
#include "SystemClock/systemclock.h"
#include "commonIncludes.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
LSM6DSL_Object_t MotionSensor;
volatile uint32_t dataRdyIntReceived;

ai_handle network;
float aiInData[AI_NETWORK_IN_1_SIZE];
float aiOutData[AI_NETWORK_OUT_1_SIZE];
uint8_t activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];
const char* activities[AI_NETWORK_OUT_1_SIZE] = {
  "stationary", "walking", "running"
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
static void MEMS_Init(void);

static void AI_Init(ai_handle w_addr, ai_handle act_addr);
static void AI_Run(float *pIn, float *pOut);
static uint32_t argmax(const float * values, uint32_t len);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
//  SystemClock_Config();
  initializeSystemClock();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  initializeGPIOs();
  initializeUart1();
  initializeCRC();
  /* USER CODE BEGIN 2 */
  dataRdyIntReceived = 0;
  MEMS_Init();
  AI_Init(ai_network_data_weights_get(), activations);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  writeLoggingMessage("Start Main");

  uint32_t write_index = 0;
  while (1)
  {
    if (dataRdyIntReceived != 0) {
      dataRdyIntReceived = 0;
      LSM6DSL_Axes_t acc_axes;
      LSM6DSL_ACC_GetAxes(&MotionSensor, &acc_axes);
      // printf("% 5d, % 5d, % 5d\r\n",  (int) acc_axes.x, (int) acc_axes.y, (int) acc_axes.z);

      /* Normalize data to [-1; 1] and accumulate into input buffer */
      /* Note: window overlapping can be managed here */
      aiInData[write_index + 0] = (float) acc_axes.x / 4000.0f;
      aiInData[write_index + 1] = (float) acc_axes.y / 4000.0f;
      aiInData[write_index + 2] = (float) acc_axes.z / 4000.0f;
      write_index += 3;

      if (write_index == AI_NETWORK_IN_1_SIZE) {
        write_index = 0;

//        printf("Running inference\r\n");
        AI_Run(aiInData, aiOutData);

        /* Output results */
        for (uint32_t i = 0; i < AI_NETWORK_OUT_1_SIZE; i++) {
//          printf("%8.6f ", aiOutData[i]);
        }
//        uint32_t class = argmax(aiOutData, AI_NETWORK_OUT_1_SIZE);
//        printf(": %d - %s\r\n", (int) class, activities[class]);
      }
    }
  }
  /* USER CODE END 3 */
}

/* USER CODE BEGIN 4 */
static void MEMS_Init(void)
{
  LSM6DSL_IO_t io_ctx;
  uint8_t id;
  LSM6DSL_AxesRaw_t axes;

  /* Link I2C functions to the LSM6DSL driver */
  io_ctx.BusType     = LSM6DSL_I2C_BUS;
  io_ctx.Address     = LSM6DSL_I2C_ADD_L;
  io_ctx.Init        = BSP_I2C2_Init;
  io_ctx.DeInit      = BSP_I2C2_DeInit;
  io_ctx.ReadReg     = BSP_I2C2_ReadReg;
  io_ctx.WriteReg    = BSP_I2C2_WriteReg;
  io_ctx.GetTick     = BSP_GetTick;
  LSM6DSL_RegisterBusIO(&MotionSensor, &io_ctx);

  /* Read the LSM6DSL WHO_AM_I register */
  LSM6DSL_ReadID(&MotionSensor, &id);
  if (id != LSM6DSL_ID) {
	  errorHandler();
  }

  /* Initialize the LSM6DSL sensor */
  LSM6DSL_Init(&MotionSensor);

  /* Configure the LSM6DSL accelerometer (ODR, scale and interrupt) */
  LSM6DSL_ACC_SetOutputDataRate(&MotionSensor, 26.0f); /* 26 Hz */
  LSM6DSL_ACC_SetFullScale(&MotionSensor, 4);          /* [-4000mg; +4000mg] */
  LSM6DSL_ACC_Set_INT1_DRDY(&MotionSensor, ENABLE);    /* Enable DRDY */
  LSM6DSL_ACC_GetAxesRaw(&MotionSensor, &axes);        /* Clear DRDY */

  /* Start the LSM6DSL accelerometer */
  LSM6DSL_ACC_Enable(&MotionSensor);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == GPIO_PIN_11) {
    dataRdyIntReceived++;
  }
}



static void AI_Init(ai_handle w_addr, ai_handle act_addr)
{
  ai_error err;

  /* 1 - Create an instance of the model */
  err = ai_network_create(&network, AI_NETWORK_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
//    printf("ai_network_create error - type=%d code=%d\r\n", err.type, err.code);
	  errorHandler();
  }

  /* 2 - Initialize the instance */
  const ai_network_params params = AI_NETWORK_PARAMS_INIT(
    AI_NETWORK_DATA_WEIGHTS(w_addr),
    AI_NETWORK_DATA_ACTIVATIONS(act_addr)
  );

  if (!ai_network_init(network, &params)) {
    err = ai_network_get_error(network);
//    printf("ai_network_init error - type=%d code=%d\r\n", err.type, err.code);
	  errorHandler();
  }
}

static void AI_Run(float *pIn, float *pOut)
{
  ai_i32 batch;
  ai_error err;

  /* 1 - Create the AI buffer IO handlers with the default definition */
  ai_buffer ai_input[AI_NETWORK_IN_NUM] = AI_NETWORK_IN;
  ai_buffer ai_output[AI_NETWORK_OUT_NUM] = AI_NETWORK_OUT;

  /* 2 - Update IO handlers with the data payload */
  ai_input[0].n_batches = 1;
  ai_input[0].data = AI_HANDLE_PTR(pIn);
  ai_output[0].n_batches = 1;
  ai_output[0].data = AI_HANDLE_PTR(pOut);

  batch = ai_network_run(network, ai_input, ai_output);
  if (batch != 1) {
    err = ai_network_get_error(network);
//    printf("AI ai_network_run error - type=%d code=%d\r\n", err.type, err.code);
	  errorHandler();
  }
}

//int _write(int fd, char * ptr, int len)
//{
//  HAL_UART_Transmit(&huart1, (uint8_t *)ptr, len, HAL_MAX_DELAY);
//  return len;
//}

static uint32_t argmax(const float * values, uint32_t len)
{
  float max_value = values[0];
  uint32_t max_index = 0;
  for (uint32_t i = 1; i < len; i++) {
    if (values[i] > max_value) {
      max_value = values[i];
      max_index = i;
    }
  }
  return max_index;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
