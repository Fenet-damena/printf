#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Function prototypes */

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed (excluding null byte) on success,
 *         -1 on error, and it may exit the program on critical error
 */
int _printf(const char *format, ...);

/**
 * print_format - Prints the formatted output based on the format string
 * @format: The format string
 * @args: The variable argument list
 * Return: Number of characters printed
 */
int print_format(const char *format, va_list args);

/**
 * handle_format_specifier - Handles a format specifier
 * @specifier: format specifier character
 * @args: variable argument list
 * Return: Number of characters printed for the specifier
 */
int handle_format_specifier(char specifier, va_list args);

/**
 * print_number - Prints an integer to stdout
 * @num: integer that should be  print
 * Return: The number of characters printed
 */
int print_number(int num);

/**
 * print_string - Prints a string to stdout
 * @str: string that should be printed
 * Return: The number of characters printed
 */
int print_string(const char *str);

/**
 * _putchar - Outputs a single character to stdout
 * @c: character that should be printed
 * Return: On success 1, on error -1
 */
int _putchar(char c);

#endif /* MAIN_H */

