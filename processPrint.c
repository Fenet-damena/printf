#include "main.h"

/**
 * process_print - Displays an argument based on its type
 * @fmt: string with a specified format for printing the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to process print.
 * @flags: Computes active flags
 * @width: get width.
 * @precision: Precision parameter
 * @size: Size specifier
 * Return: 1 or 2;
 */
int fa_process_print(const char *fmt, int *ind, va_list list, char buffer[],
                 int flags, int width, int precision, int size)
{
    int i, unknown_len = 0, printed_chars = 0;
    fa_fmt_t fmt_types[] = {
        {'c', fa_print_char}, {'s', fa_print_string}, {'%', fa_print_percent},
        {'i', fa_print_int}, {'d', fa_print_int}, {'b', fa_print_binary},
        {'u', fa_print_unsigned}, {'o', fa_print_octal}, {'x', fa_print_hexadecimal},
        {'X', fa_print_hexa_upper}, {'p', fa_print_pointer}, {'S', fa_print_non_printable},
        {'r', fa_print_reverse}, {'R', fa_print_rot13string}, {'\0', NULL}
    };

    for (i = 0; fmt_types[i].fa_fmt != '\0'; i++)
    {
        if (fmt[*ind] == fmt_types[i].fa_fmt)
        {
            return fmt_types[i].fa_fn(list, buffer, flags, width, precision, size);
        }
    }

    if (fmt_types[i].fa_fmt == '\0')
    {
        if (fmt[*ind] == '\0')
        {
            return -1;
        }
        unknown_len += write(1, "%", 1);
        if (fmt[*ind - 1] == ' ')
        {
            unknown_len += write(1, " ", 1);
        }
        else if (width)
        {
            --(*ind);
            while (fmt[*ind] != ' ' && fmt[*ind] != '%')
            {
                --(*ind);
            }
            if (fmt[*ind] == ' ')
            {
                --(*ind);
            }
            return 1;
        }
    }

    return printed_chars;
}

