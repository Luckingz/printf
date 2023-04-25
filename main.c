#include "main.h"

/**
 * _printf - Function to print 
 * @format: Format of the text to be printed
 * Return: 0 on sucess
 */

int _printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);

	char se = va_arg(ap, char);
	if (format == 'c' || format == 's' || format == '%')
	{
		_putchar(se);
	}
	va_end(ap);
}
