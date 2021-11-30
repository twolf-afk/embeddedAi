
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef UART1_H
#define UART1_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Exported types ------------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void initializeUart1(void);
void uart1_transmit(uint8_t* pointer, uint16_t length);

/* Private defines -----------------------------------------------------------*/


#ifdef __cplusplus
}
#endif

#endif

