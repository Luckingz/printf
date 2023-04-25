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

	va_start(ap, format);

	int c, index = 0;
	char *s;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(ap, int);
					_putchar(c);
					index++;
					break;
				case 's':
					s = va_arg(ap, char *);
					if (s == NULL)
						s = "(null)";
					while (*s)
						_putcharr(*s);
						s++;
						index++;
					break;
				case '%':
					_putchar('%');
					index++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					index += 2;
					break;
			}
		}
		else
			_putchar(*format);
			index++;
		format++;
	}
	va_end(ap);
	return (index);
}
