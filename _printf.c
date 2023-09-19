#include "main.h"
<<<<<<< HEAD
#include <unistd.h>


/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 *
 * Return: on success 1
 * On error, -1 is returned, and errno is set appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
=======

/**
 * _printf - display output to stdout.
 * @format_str: character string.
 * 
 * Return: number of characters printed
 * 
 */

int _printf(const char *format_str, ...)
{
    size_t char_count = 0;
    va_list args_list;

    if (format_str != NULL)
    {
        va_start(args_list, format_str);

        for (; *format_str; format_str++)
        {
            if (*format_str != '%')
                char_count += write(1, format_str, 1);
            else if (*format_str == '%' && *(format_str - 1) == 92)
                char_count += _putchar('%');
            else
            {
                format_str++;
                char_count += process_specifiers(format_str, args_list);
            }
        }
        
        va_end(args_list);
        return char_count;
    }
    else
        return (0);
>>>>>>> 7061600a10a7500bbb58bb3991af2bdf8450032a
}
