
/* Includes ------------------------------------------------------------------*/
#include "ErrorHandler/errorHandler.h"

/* Private includes ----------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "commonDefinitions.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/
void errorHandler(void)
{
	__disable_irq();
	// TODO write Log message
	while(1)
	{
		HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
		HAL_Delay(50); /* wait 50 ms */
	}
}
