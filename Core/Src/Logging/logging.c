
/* Includes ------------------------------------------------------------------*/
#include "Logging/logging.h"

/* Private includes ----------------------------------------------------------*/
#include "stmAiExampleConfiguration.h"
#include "Uart/uart1.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define logBufferSize (128);

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static void writeMessageToStLink(char* message, uint16_t length);
static void writeMessageToUsb(const char* format, ...);

/* Private user code ---------------------------------------------------------*/
void writeLoggingMessage(const char* format, ...)
{
	int logBufferMessageSize = logBufferSize;
	char* logBuffer[logBufferMessageSize];

	if (useStLinkForLogging)
	{
		va_list variadicArgumentList;
		va_start(variadicArgumentList, format);

		vsnprintf(logBuffer, logBufferMessageSize, format, variadicArgumentList);

		writeMessageToStLink(logBuffer, logBufferMessageSize);
	}
	if (useUsbForLogging)
	{
		writeMessageToUsb(format);
	}
}

static void writeMessageToStLink(char* message, uint16_t length)
{

	uart1_transmit(message, length);

}

static void writeMessageToUsb(const char* format, ...)
{
    printf(format);
}
