#include "main.h"

/**
 * fa_get_size - Computes the size to cast the argument
 * @format: string with a specified format for printing the arguments.
 * @i: reference to the current location within the format string.
 *
 * Return: Size specifier.
 */
int fa_get_size(const char *format, int *i)
{
    int current_index = *i + 1;
    int size = 0;

    if (format[current_index] == 'l')
        size = FA_LONG;
    else if (format[current_index] == 'h')
        size = FA_SHORT;

    if (size == 0)
        *i = current_index - 1;
    else
        *i = current_index;

    return (size);
}

