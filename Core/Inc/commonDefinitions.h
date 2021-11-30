/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef COMMONDEFINITIONS_H
#define COMMONDEFINITIONS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/

/* Private defines -----------------------------------------------------------*/
#define ST_LINK_UART1_TX_Pin GPIO_PIN_6
#define ST_LINK_UART1_TX_GPIO_Port GPIOB
#define ST_LINK_UART1_RX_Pin GPIO_PIN_7
#define ST_LINK_UART1_RX_GPIO_Port GPIOB

#define LED2_Pin GPIO_PIN_14
#define LED2_GPIO_Port GPIOB

#ifdef __cplusplus
}
#endif

#endif
