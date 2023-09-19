<<<<<<< HEAD
#include "main.h"

/**
 * _printf - prints out the parameters given to it
 *
 * @format: format of character given to it
 * Return: number of elements given to it
 */


int _printf(const char *format, ...)
{
	va_list arr;
	int i = 0, count = 0;

	if (!format)
		return (-1);
	va_start(arr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				count++;
				i++;
			}
			else if (cmp_func(format[i + 1]) != NULL)
			{
				count += (cmp_func(format[i + 1]))(arr);
				i++;
			}
			else
			{
				_putchar(format[i]);
				count++;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(arr);
	return (count);
}
=======
#ifndef MAIN_H_
#define MAIN_H_
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int output_int(int n);
int _putchar(char c);
int output_unsignedint(int n);
int _printf(const char *format, ...);
int _strlen(const char *str);
int output_string(char *str);
int output_String(char *str);
int output_float(float n);
int output_binary(unsigned long int n);
size_t process_specifiers(const char *format, va_list list);

#endif
>>>>>>> 7061600a10a7500bbb58bb3991af2bdf8450032a
