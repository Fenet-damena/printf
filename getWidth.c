#include "main.h"

/**
 * fa_get_width - Computes the width for printing
 * @format: string with a specified format for printing the arguments.
 * @i: reference to the current location within the format string.
 * @list: List of arguments to be printed.
 *
 * Return: Width.
 */
int fa_get_width(const char *format, int *i, va_list list)
{
    int current_index = *i + 1;
    int width = 0;

    while (format[current_index] != '\0')
    {
        if (fa_is_digit(format[current_index]))
        {
            width *= 10;
            width += format[current_index] - '0';
        }
        else if (format[current_index] == '*')
        {
            current_index++;
            width = va_arg(list, int);
            break;
        }
        else
            break;

        current_index++;
    }

    *i = current_index - 1;

    return (width);
}

