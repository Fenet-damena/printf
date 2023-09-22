#include "main.h"

void fa_print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - This is a Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    int i, printed = 0, printed_chars = 0;
    int flags, width, precision, size, buff_ind = 0;
    va_list list;
    char buffer[FA_BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == FA_BUFF_SIZE)
                fa_print_buffer(buffer, &buff_ind);
            /* write(1, &format[i], 1);*/
            printed_chars++;
        }
        else
        {
            fa_print_buffer(buffer, &buff_ind);
            flags = fa_get_flags(format, &i);
            width = fa_get_width(format, &i, list);
            precision = fa_get_precision(format, &i, list);
            size = fa_get_size(format, &i);
            ++i;
            printed = fa_process_print(format, &i, list, buffer,
                flags, width, precision, size);
            if (printed == -1)
                return (-1);
            printed_chars += printed;
        }
    }

    fa_print_buffer(buffer, &buff_ind);

    va_end(list);

    return (printed_chars);
}

/**
 * fa_print_buffer - Displays  the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index to add the next char, depicts the length.
 */
void fa_print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, &buffer[0], *buff_ind);

    *buff_ind = 0;
}

