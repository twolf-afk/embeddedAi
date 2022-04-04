
/* Includes ------------------------------------------------------------------*/
#include "utilities.h"

/* Private includes ----------------------------------------------------------*/
#include <stdio.h>
#include <stdarg.h>

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/
void addingNumbers(uint8_t amountOfNumbers, ...)		// This is a variadic function, it takes an infinite amount of arguments
{

	short sum = 0;

	// Initializes a list of arguments
    va_list variadic_arguments;

    // Makes access to the arguments
    // amountOfNumbers are the amount of arguments
    va_start(variadic_arguments, amountOfNumbers);

    for (int i = 0; i < amountOfNumbers; ++i) {

    	// with 'va_arg' you can access the items
    	// 'int' indicates the type
    	int number = va_arg(variadic_arguments, int);

    	sum = sum + number;

	}

    // closes the traversal through argument list
    va_end(variadic_arguments);

}
