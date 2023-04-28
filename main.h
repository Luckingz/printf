#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);

int _printf(const char *format, ...);

int print_char(va_list arg);

int print_str(va_list arg);

int print_int(va_list arg);

#endif
