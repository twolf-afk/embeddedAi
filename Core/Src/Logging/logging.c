
/* Includes ------------------------------------------------------------------*/
#include "Logging/logging.h"

/* Private includes ----------------------------------------------------------*/
#include "stmAiExampleConfiguration.h"
#include "Uart/uart1.h"

#include <stdio.h>
#include <string.h>
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static void writeMessageToStLink(char* message, uint16_t length);
static void writeMessageToUsb(void);

/* Private user code ---------------------------------------------------------*/
void writeLoggingMessage(char* message)
{

	if (useStLinkForLogging)
	{
		writeMessageToStLink(strcat(message, "\r\n"), strlen(message));
	}
	if (useUsbForLogging)
	{
		writeMessageToUsb();
	}
}

static void writeMessageToStLink(char* message, uint16_t length)
{

	uart1_transmit(message, length);

}

static void writeMessageToUsb(void)
{
	printf("USB was used for Logging\r\n");
}
