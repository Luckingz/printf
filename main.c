#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _printf - Function to print
 * @format: Format of the text to be printed
 * Return: 0 on sucess
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int index = 0;

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format != '%';)
		{
			format++;
			if (*format == 'c')
				char c = va_arg(ap, int);

				_putchar(c);
				index++;
		else if (*format == 's')
		{
			char *s = va_arg(ap, char *);

			for (int 1 = 0; s[i] != '\0')
				_putcar(s[i]);
				index++;
		}
		else if (*format == '%')
		{
			_putchar('%');
			index++;
		}
		else
			/** Unsupported format */
	}
	else
	{
		_putchar(*format);
		index++;
	}
	format++;
	}
	va_end(ap);
	return (index);
}
