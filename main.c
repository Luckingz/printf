#include "main.h"
#include <stdio.h>
#include <stdarg.>
#include <stdlib.h>

/**
 * print_char - Prints a character to stdout
 * @arg: List containing a single character to print
 *
 * Return: The number of characters printed
 */
int print_char(va_list arg)
{
	_putchar(va_arg(arg, int));
		va_list arg
	char *str = va_arg(arg, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		str++;
		len++;
	}
	return (len);
}

/**
 * print_int - Prints an integer to stdout
 * @arg: List containing an integer to print
 *
 * Return: The number of characters printed
 */
int print_int(va_list arg)
{
	int n = va_arg(arg, int);
	int len = 0;

	if (n < 0)
	{
		_putchar('-');
		len++;
		n = -n;
	}

	if (n / 10)
		len += print_int_helper(n / 10);

	_putchar(n % 10 + '0');
	len++;
	return (len);
}

/**
 * print_int_helper - Recursive helper function for print_int
 * @n: The number to print
 *
 * Return: The number of digits in the number
 */
int print_int_helper(int n)
{
	int len = 0;

	if (n / 10)
		len += print_int_helper(n / 10);

	_putchar(n % 10 + '0');
	len++;
	return (len);
}

/**
 * _printf - Produces output according to a format
 * @format: A string containing zero or more directives
 * @...: Arguments to substitute into the format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += format_dispatch(&format, args);
		}
		else
		{
			_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}

/**
 * format_dispatch - Dispatches the appropriate conversion function
 * @format: Pointer to the format specifier character
 * @args: List containing the arguments to print
 *
 * Return: The number of characters printed by the conversion function
 */
int format_dispatch(const char **format, va_list args)
{
	int len = 0;

	switch (**format)
	{
		case 'c':
			len += print_char(args);
			break;
		case 's':
			len += va_arg(args, char *)
			break;
		case 'd':
		case 'i':
			len += print_int(args);
			break;
		case '%':
			_putchar('%');
			len++;
			break;
		default:
			_putchar('%');
			_putchar(**format);
			len += 2;
			break;
	}
	return (len);
}
