#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - Function to print
 * @format: variable
 * Return: 0 on succes
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
			if (*format == '\0')
				break;
		switch (*format)
		{
			case 'c':
				len += print_char(args);
				break;
			case 's':
				len += print_str(args);
				break;
			case 'd':
			case 'i':
				len += print_int(args);
				break;
		default:
				_putchar('%');
				_putchar(*format);
				len += 2;
				break;
		}
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
 * print_char - function to print char
 * @arg: argument
 * Return: 0 on success
 */

int print_char(va_list arg)
{
	int ch = va_arg(arg, int);

	_putchar(ch);
	return (1);
}

/**
 * print_str - function to print string
 * @arg: argument
 * Return: 0 on succes
 */

int print_str(va_list arg)
{
	char *str = va_arg(arg, char *);
	int len = 0;

	if (str == NULL)
		str = "(nil)";

	while (*str)
	{
		_putchar(*str);
		str++;
		len++;
	}
	return (len);
}

/**
 * print_int - Function to print int
 * @arg: argument
 * Return: 0 on success
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

	if (n >= 10)
		len += print_int(arg);

	_putchar(n % 10 + '0');
	len++;

	return (len);
}
