
/* Includes ------------------------------------------------------------------*/
#include "GPIO/gpio.h"

/* Private includes ----------------------------------------------------------*/
#include "commonDefinitions.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define M24SR64_Y_RF_DISABLE_Pin GPIO_PIN_2
#define M24SR64_Y_RF_DISABLE_GPIO_Port GPIOE
#define USB_OTG_FS_OVRCR_EXTI3_Pin GPIO_PIN_3
#define USB_OTG_FS_OVRCR_EXTI3_GPIO_Port GPIOE
#define M24SR64_Y_GPO_Pin GPIO_PIN_4
#define M24SR64_Y_GPO_GPIO_Port GPIOE
#define SPSGRF_915_GPIO3_EXTI5_Pin GPIO_PIN_5
#define SPSGRF_915_GPIO3_EXTI5_GPIO_Port GPIOE
#define SPSGRF_915_GPIO3_EXTI5_EXTI_IRQn EXTI9_5_IRQn
#define SPBTLE_RF_IRQ_EXTI6_Pin GPIO_PIN_6
#define SPBTLE_RF_IRQ_EXTI6_GPIO_Port GPIOE
#define SPBTLE_RF_IRQ_EXTI6_EXTI_IRQn EXTI9_5_IRQn
#define BUTTON_EXTI13_Pin GPIO_PIN_13
#define BUTTON_EXTI13_GPIO_Port GPIOC
#define BUTTON_EXTI13_EXTI_IRQn EXTI15_10_IRQn
#define ARD_A5_Pin GPIO_PIN_0
#define ARD_A5_GPIO_Port GPIOC
#define ARD_A4_Pin GPIO_PIN_1
#define ARD_A4_GPIO_Port GPIOC
#define ARD_A3_Pin GPIO_PIN_2
#define ARD_A3_GPIO_Port GPIOC
#define ARD_A2_Pin GPIO_PIN_3
#define ARD_A2_GPIO_Port GPIOC
#define ARD_D1_Pin GPIO_PIN_0
#define ARD_D1_GPIO_Port GPIOA
#define ARD_D0_Pin GPIO_PIN_1
#define ARD_D0_GPIO_Port GPIOA
#define ARD_D10_Pin GPIO_PIN_2
#define ARD_D10_GPIO_Port GPIOA
#define ARD_D4_Pin GPIO_PIN_3
#define ARD_D4_GPIO_Port GPIOA
#define ARD_D7_Pin GPIO_PIN_4
#define ARD_D7_GPIO_Port GPIOA
#define ARD_D13_Pin GPIO_PIN_5
#define ARD_D13_GPIO_Port GPIOA
#define ARD_D12_Pin GPIO_PIN_6
#define ARD_D12_GPIO_Port GPIOA
#define ARD_D11_Pin GPIO_PIN_7
#define ARD_D11_GPIO_Port GPIOA
#define ARD_A1_Pin GPIO_PIN_4
#define ARD_A1_GPIO_Port GPIOC
#define ARD_A0_Pin GPIO_PIN_5
#define ARD_A0_GPIO_Port GPIOC
#define ARD_D3_Pin GPIO_PIN_0
#define ARD_D3_GPIO_Port GPIOB
#define ARD_D6_Pin GPIO_PIN_1
#define ARD_D6_GPIO_Port GPIOB
#define ARD_D8_Pin GPIO_PIN_2
#define ARD_D8_GPIO_Port GPIOB
#define DFSDM1_DATIN2_Pin GPIO_PIN_7
#define DFSDM1_DATIN2_GPIO_Port GPIOE
#define ISM43362_RST_Pin GPIO_PIN_8
#define ISM43362_RST_GPIO_Port GPIOE
#define DFSDM1_CKOUT_Pin GPIO_PIN_9
#define DFSDM1_CKOUT_GPIO_Port GPIOE
#define QUADSPI_CLK_Pin GPIO_PIN_10
#define QUADSPI_CLK_GPIO_Port GPIOE
#define QUADSPI_NCS_Pin GPIO_PIN_11
#define QUADSPI_NCS_GPIO_Port GPIOE
#define OQUADSPI_BK1_IO0_Pin GPIO_PIN_12
#define OQUADSPI_BK1_IO0_GPIO_Port GPIOE
#define QUADSPI_BK1_IO1_Pin GPIO_PIN_13
#define QUADSPI_BK1_IO1_GPIO_Port GPIOE
#define QUAD_SPI_BK1_IO2_Pin GPIO_PIN_14
#define QUAD_SPI_BK1_IO2_GPIO_Port GPIOE
#define QUAD_SPI_BK1_IO3_Pin GPIO_PIN_15
#define QUAD_SPI_BK1_IO3_GPIO_Port GPIOE
#define ISM43362_BOOT0_Pin GPIO_PIN_12
#define ISM43362_BOOT0_GPIO_Port GPIOB
#define ISM43362_WAKEUP_Pin GPIO_PIN_13
#define ISM43362_WAKEUP_GPIO_Port GPIOB

#define SPSGRF_915_SDN_Pin GPIO_PIN_15
#define SPSGRF_915_SDN_GPIO_Port GPIOB
#define INTERNAL_UART3_TX_Pin GPIO_PIN_8
#define INTERNAL_UART3_TX_GPIO_Port GPIOD
#define INTERNAL_UART3_RX_Pin GPIO_PIN_9
#define INTERNAL_UART3_RX_GPIO_Port GPIOD
#define LPS22HB_INT_DRDY_EXTI0_Pin GPIO_PIN_10
#define LPS22HB_INT_DRDY_EXTI0_GPIO_Port GPIOD
#define LPS22HB_INT_DRDY_EXTI0_EXTI_IRQn EXTI15_10_IRQn
#define LSM6DSL_INT1_EXTI11_Pin GPIO_PIN_11
#define LSM6DSL_INT1_EXTI11_GPIO_Port GPIOD
#define LSM6DSL_INT1_EXTI11_EXTI_IRQn EXTI15_10_IRQn
#define USB_OTG_FS_PWR_EN_Pin GPIO_PIN_12
#define USB_OTG_FS_PWR_EN_GPIO_Port GPIOD
#define SPBTLE_RF_SPI3_CSN_Pin GPIO_PIN_13
#define SPBTLE_RF_SPI3_CSN_GPIO_Port GPIOD
#define ARD_D2_Pin GPIO_PIN_14
#define ARD_D2_GPIO_Port GPIOD
#define ARD_D2_EXTI_IRQn EXTI15_10_IRQn
#define HTS221_DRDY_EXTI15_Pin GPIO_PIN_15
#define HTS221_DRDY_EXTI15_GPIO_Port GPIOD
#define HTS221_DRDY_EXTI15_EXTI_IRQn EXTI15_10_IRQn
#define VL53L0X_XSHUT_Pin GPIO_PIN_6
#define VL53L0X_XSHUT_GPIO_Port GPIOC
#define VL53L0X_GPIO1_EXTI7_Pin GPIO_PIN_7
#define VL53L0X_GPIO1_EXTI7_GPIO_Port GPIOC
#define VL53L0X_GPIO1_EXTI7_EXTI_IRQn EXTI9_5_IRQn
#define LSM3MDL_DRDY_EXTI8_Pin GPIO_PIN_8
#define LSM3MDL_DRDY_EXTI8_GPIO_Port GPIOC
#define LSM3MDL_DRDY_EXTI8_EXTI_IRQn EXTI9_5_IRQn
#define LED3_WIFI__LED4_BLE_Pin GPIO_PIN_9
#define LED3_WIFI__LED4_BLE_GPIO_Port GPIOC
#define SPBTLE_RF_RST_Pin GPIO_PIN_8
#define SPBTLE_RF_RST_GPIO_Port GPIOA
#define USB_OTG_FS_VBUS_Pin GPIO_PIN_9
#define USB_OTG_FS_VBUS_GPIO_Port GPIOA
#define USB_OTG_FS_ID_Pin GPIO_PIN_10
#define USB_OTG_FS_ID_GPIO_Port GPIOA
#define USB_OTG_FS_DM_Pin GPIO_PIN_11
#define USB_OTG_FS_DM_GPIO_Port GPIOA
#define USB_OTG_FS_DP_Pin GPIO_PIN_12
#define USB_OTG_FS_DP_GPIO_Port GPIOA
#define SYS_JTMS_SWDIO_Pin GPIO_PIN_13
#define SYS_JTMS_SWDIO_GPIO_Port GPIOA
#define SYS_JTCK_SWCLK_Pin GPIO_PIN_14
#define SYS_JTCK_SWCLK_GPIO_Port GPIOA
#define ARD_D9_Pin GPIO_PIN_15
#define ARD_D9_GPIO_Port GPIOA
#define INTERNAL_SPI3_SCK_Pin GPIO_PIN_10
#define INTERNAL_SPI3_SCK_GPIO_Port GPIOC
#define INTERNAL_SPI3_MISO_Pin GPIO_PIN_11
#define INTERNAL_SPI3_MISO_GPIO_Port GPIOC
#define INTERNAL_SPI3_MOSI_Pin GPIO_PIN_12
#define INTERNAL_SPI3_MOSI_GPIO_Port GPIOC
#define PMOD_RESET_Pin GPIO_PIN_0
#define PMOD_RESET_GPIO_Port GPIOD
#define PMOD_SPI2_SCK_Pin GPIO_PIN_1
#define PMOD_SPI2_SCK_GPIO_Port GPIOD
#define PMOD_IRQ_EXTI12_Pin GPIO_PIN_2
#define PMOD_IRQ_EXTI12_GPIO_Port GPIOD
#define PMOD_UART2_CTS_Pin GPIO_PIN_3
#define PMOD_UART2_CTS_GPIO_Port GPIOD
#define PMOD_UART2_RTS_Pin GPIO_PIN_4
#define PMOD_UART2_RTS_GPIO_Port GPIOD
#define PMOD_UART2_TX_Pin GPIO_PIN_5
#define PMOD_UART2_TX_GPIO_Port GPIOD
#define PMOD_UART2_RX_Pin GPIO_PIN_6
#define PMOD_UART2_RX_GPIO_Port GPIOD
#define STSAFE_A100_RESET_Pin GPIO_PIN_7
#define STSAFE_A100_RESET_GPIO_Port GPIOD
#define SYS_JTD0_SWO_Pin GPIO_PIN_3
#define SYS_JTD0_SWO_GPIO_Port GPIOB
#define ARD_D5_Pin GPIO_PIN_4
#define ARD_D5_GPIO_Port GPIOB
#define SPSGRF_915_SPI3_CSN_Pin GPIO_PIN_5
#define SPSGRF_915_SPI3_CSN_GPIO_Port GPIOB
//#define ST_LINK_UART1_TX_Pin GPIO_PIN_6
//#define ST_LINK_UART1_TX_GPIO_Port GPIOB
//#define ST_LINK_UART1_RX_Pin GPIO_PIN_7
//#define ST_LINK_UART1_RX_GPIO_Port GPIOB
#define ARD_D15_Pin GPIO_PIN_8
#define ARD_D15_GPIO_Port GPIOB
#define ARD_D14_Pin GPIO_PIN_9
#define ARD_D14_GPIO_Port GPIOB
#define ISM43362_SPI3_CSN_Pin GPIO_PIN_0
#define ISM43362_SPI3_CSN_GPIO_Port GPIOE
#define ISM43362_DRDY_EXTI1_Pin GPIO_PIN_1
#define ISM43362_DRDY_EXTI1_GPIO_Port GPIOE

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/
void initializeGPIOs(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOE, M24SR64_Y_RF_DISABLE_Pin|M24SR64_Y_GPO_Pin|ISM43362_RST_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, ARD_D10_Pin|SPBTLE_RF_RST_Pin|ARD_D9_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, ARD_D8_Pin|ISM43362_BOOT0_Pin|ISM43362_WAKEUP_Pin|LED2_Pin
						  |SPSGRF_915_SDN_Pin|ARD_D5_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOD, USB_OTG_FS_PWR_EN_Pin|PMOD_RESET_Pin|STSAFE_A100_RESET_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(SPBTLE_RF_SPI3_CSN_GPIO_Port, SPBTLE_RF_SPI3_CSN_Pin, GPIO_PIN_SET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC, VL53L0X_XSHUT_Pin|LED3_WIFI__LED4_BLE_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(SPSGRF_915_SPI3_CSN_GPIO_Port, SPSGRF_915_SPI3_CSN_Pin, GPIO_PIN_SET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(ISM43362_SPI3_CSN_GPIO_Port, ISM43362_SPI3_CSN_Pin, GPIO_PIN_SET);

	/*Configure GPIO pins : M24SR64_Y_RF_DISABLE_Pin M24SR64_Y_GPO_Pin ISM43362_RST_Pin ISM43362_SPI3_CSN_Pin */
	GPIO_InitStruct.Pin = M24SR64_Y_RF_DISABLE_Pin|M24SR64_Y_GPO_Pin|ISM43362_RST_Pin|ISM43362_SPI3_CSN_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	/*Configure GPIO pins : USB_OTG_FS_OVRCR_EXTI3_Pin SPSGRF_915_GPIO3_EXTI5_Pin SPBTLE_RF_IRQ_EXTI6_Pin ISM43362_DRDY_EXTI1_Pin */
	GPIO_InitStruct.Pin = USB_OTG_FS_OVRCR_EXTI3_Pin|SPSGRF_915_GPIO3_EXTI5_Pin|SPBTLE_RF_IRQ_EXTI6_Pin|ISM43362_DRDY_EXTI1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	/*Configure GPIO pin : BUTTON_EXTI13_Pin */
	GPIO_InitStruct.Pin = BUTTON_EXTI13_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(BUTTON_EXTI13_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : ARD_A5_Pin ARD_A4_Pin ARD_A3_Pin ARD_A2_Pin
						   ARD_A1_Pin ARD_A0_Pin */
	GPIO_InitStruct.Pin = ARD_A5_Pin|ARD_A4_Pin|ARD_A3_Pin|ARD_A2_Pin
						  |ARD_A1_Pin|ARD_A0_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG_ADC_CONTROL;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pins : ARD_D1_Pin ARD_D0_Pin */
	GPIO_InitStruct.Pin = ARD_D1_Pin|ARD_D0_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF8_UART4;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pins : ARD_D10_Pin SPBTLE_RF_RST_Pin ARD_D9_Pin */
	GPIO_InitStruct.Pin = ARD_D10_Pin|SPBTLE_RF_RST_Pin|ARD_D9_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pin : ARD_D4_Pin */
	GPIO_InitStruct.Pin = ARD_D4_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
	HAL_GPIO_Init(ARD_D4_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : ARD_D7_Pin */
	GPIO_InitStruct.Pin = ARD_D7_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG_ADC_CONTROL;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(ARD_D7_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : ARD_D13_Pin ARD_D12_Pin ARD_D11_Pin */
	GPIO_InitStruct.Pin = ARD_D13_Pin|ARD_D12_Pin|ARD_D11_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pin : ARD_D3_Pin */
	GPIO_InitStruct.Pin = ARD_D3_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(ARD_D3_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : ARD_D6_Pin */
	GPIO_InitStruct.Pin = ARD_D6_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG_ADC_CONTROL;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(ARD_D6_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : ARD_D8_Pin ISM43362_BOOT0_Pin ISM43362_WAKEUP_Pin LED2_Pin
						   SPSGRF_915_SDN_Pin ARD_D5_Pin SPSGRF_915_SPI3_CSN_Pin */
	GPIO_InitStruct.Pin = ARD_D8_Pin|ISM43362_BOOT0_Pin|ISM43362_WAKEUP_Pin|LED2_Pin
						  |SPSGRF_915_SDN_Pin|ARD_D5_Pin|SPSGRF_915_SPI3_CSN_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : DFSDM1_DATIN2_Pin DFSDM1_CKOUT_Pin */
	GPIO_InitStruct.Pin = DFSDM1_DATIN2_Pin|DFSDM1_CKOUT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = GPIO_AF6_DFSDM1;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	/*Configure GPIO pins : QUADSPI_CLK_Pin QUADSPI_NCS_Pin OQUADSPI_BK1_IO0_Pin QUADSPI_BK1_IO1_Pin
						   QUAD_SPI_BK1_IO2_Pin QUAD_SPI_BK1_IO3_Pin */
	GPIO_InitStruct.Pin = QUADSPI_CLK_Pin|QUADSPI_NCS_Pin|OQUADSPI_BK1_IO0_Pin|QUADSPI_BK1_IO1_Pin
						  |QUAD_SPI_BK1_IO2_Pin|QUAD_SPI_BK1_IO3_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF10_QUADSPI;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	/*Configure GPIO pins : INTERNAL_UART3_TX_Pin INTERNAL_UART3_RX_Pin */
	GPIO_InitStruct.Pin = INTERNAL_UART3_TX_Pin|INTERNAL_UART3_RX_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	/*Configure GPIO pins : LPS22HB_INT_DRDY_EXTI0_Pin LSM6DSL_INT1_EXTI11_Pin ARD_D2_Pin HTS221_DRDY_EXTI15_Pin
						   PMOD_IRQ_EXTI12_Pin */
	GPIO_InitStruct.Pin = LPS22HB_INT_DRDY_EXTI0_Pin|LSM6DSL_INT1_EXTI11_Pin|ARD_D2_Pin|HTS221_DRDY_EXTI15_Pin
						  |PMOD_IRQ_EXTI12_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	/*Configure GPIO pins : USB_OTG_FS_PWR_EN_Pin SPBTLE_RF_SPI3_CSN_Pin PMOD_RESET_Pin STSAFE_A100_RESET_Pin */
	GPIO_InitStruct.Pin = USB_OTG_FS_PWR_EN_Pin|SPBTLE_RF_SPI3_CSN_Pin|PMOD_RESET_Pin|STSAFE_A100_RESET_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	/*Configure GPIO pins : VL53L0X_XSHUT_Pin LED3_WIFI__LED4_BLE_Pin */
	GPIO_InitStruct.Pin = VL53L0X_XSHUT_Pin|LED3_WIFI__LED4_BLE_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pins : VL53L0X_GPIO1_EXTI7_Pin LSM3MDL_DRDY_EXTI8_Pin */
	GPIO_InitStruct.Pin = VL53L0X_GPIO1_EXTI7_Pin|LSM3MDL_DRDY_EXTI8_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pin : USB_OTG_FS_VBUS_Pin */
	GPIO_InitStruct.Pin = USB_OTG_FS_VBUS_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(USB_OTG_FS_VBUS_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : USB_OTG_FS_ID_Pin USB_OTG_FS_DM_Pin USB_OTG_FS_DP_Pin */
	GPIO_InitStruct.Pin = USB_OTG_FS_ID_Pin|USB_OTG_FS_DM_Pin|USB_OTG_FS_DP_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pins : INTERNAL_SPI3_SCK_Pin INTERNAL_SPI3_MISO_Pin INTERNAL_SPI3_MOSI_Pin */
	GPIO_InitStruct.Pin = INTERNAL_SPI3_SCK_Pin|INTERNAL_SPI3_MISO_Pin|INTERNAL_SPI3_MOSI_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pin : PMOD_SPI2_SCK_Pin */
	GPIO_InitStruct.Pin = PMOD_SPI2_SCK_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
	HAL_GPIO_Init(PMOD_SPI2_SCK_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : PMOD_UART2_CTS_Pin PMOD_UART2_RTS_Pin PMOD_UART2_TX_Pin PMOD_UART2_RX_Pin */
	GPIO_InitStruct.Pin = PMOD_UART2_CTS_Pin|PMOD_UART2_RTS_Pin|PMOD_UART2_TX_Pin|PMOD_UART2_RX_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	/*Configure GPIO pins : ARD_D15_Pin ARD_D14_Pin */
	GPIO_InitStruct.Pin = ARD_D15_Pin|ARD_D14_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}
