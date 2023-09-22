#include "main.h"

/**
 * fa_get_precision - computes the precision for printing
 * @i: reference to the current location within the format string.
 * @format: string with a specified format for printing the arguments.
 * @list: List of arguments to be printed
 *
 * Return: Precision.
 */
int fa_get_precision(const char *format, int *i, va_list list)
{
    int current_index = *i + 1;
    int precision = -1;

    if (format[current_index] != '.')
        return (precision);

    precision = 0;

    current_index += 1;  

    while (fa_is_digit(format[current_index]))
    {
        precision *= 10;
        precision += format[current_index] - '0';
        current_index += 1;
    }

    if (format[current_index] == '*')
    {
        current_index++;
        precision = va_arg(list, int);
    }

    *i = current_index - 1;

    return (precision);
}


