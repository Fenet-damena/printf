#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Function prototypes */

/**
 * my_printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed (excluding null byte) on success,
 *         -1 on error, and it may exit the program on critical error
 */
int my_printf(const char *format, ...);

/**
 * print_custom_format - Print the formatted output based on the format string
 * @format: The format string
 * @args: The variable argument list
 * Return: Number of characters printed
 */
int print_custom_format(const char *format, va_list args);

/**
 * handle_custom_format_specifier - Handle a format specifier
 * @specifier: The format specifier character
 * @args: The variable argument list
 * Return: Number of characters printed for the specifier
 */
int handle_custom_format_specifier(char specifier, va_list args);

/**
 * print_custom_number - Print an integer to stdout
 * @num: The integer to be printed
 * Return: The number of characters printed
 */
int print_custom_number(int num);

/**
 * print_custom_string - Print a string to stdout
 * @str: The string to be printed
 * Return: The number of characters printed
 */
int print_custom_string(const char *str);

/**
 * custom_putchar - Writes a character to stdout
 * @c: The character to print
 * Return: On success 1, on error -1
 */
int custom_putchar(char c);

#endif /* MAIN_H */

