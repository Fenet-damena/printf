#include "main.h"

/**
 * fa_get_flags - Computes active flags
 * @format: string with a specified format for printing the arguments.
 * @i: reference to the current location within the format string.
 * Return: Flags:
 */
int fa_get_flags(const char *format, int *i)
{
    /* - + 0 # ' ' */
    /* 1 2 4 8  16 */
    int j, current_index;
    int flags = 0;
    const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARR[] = {FA_MINUS, FA_PLUS, FA_ZERO, FA_HASH, FA_SPACE, 0};

    for (current_index = *i + 1; format[current_index] != '\0'; current_index++)
    {
        for (j = 0; FLAGS_CH[j] != '\0'; j++)
        {
            if (format[current_index] == FLAGS_CH[j])
            {
                flags |= FLAGS_ARR[j];
                break;
            }
        }

        if (FLAGS_CH[j] == 0)
            break;
    }

    *i = current_index - 1;

    return (flags);
}

