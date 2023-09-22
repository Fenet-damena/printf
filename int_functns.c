#include "main.h"

/**
 * fa_print_char - Displays a character
 * @types: List of arguments
 * @buffer: Buffer array to process printing
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Number of characters printed
 */
int fa_print_char(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    char c = va_arg(types, int);

    return (fa_process_write_char(c, buffer, flags, width, precision, size));
}


/**
 * fa_print_string - Displays a string
 * @types: List of arguments
 * @buffer: Buffer array to process printing
 * @flags:  Computes active flags
 * @width: get width.
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Number of characters printed
 */
int fa_print_string(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    int length = 0, i;
    char *str = va_arg(types, char *);

    FA_UNUSED(buffer);
    FA_UNUSED(flags);
    FA_UNUSED(width);
    FA_UNUSED(precision);
    FA_UNUSED(size);
    if (str == NULL)
    {
        str = "(null)";
        if (precision >= 6)
            str = "      ";
    }

    while (str[length] != '\0')
        length++;

    if (precision >= 0 && precision < length)
        length = precision;

    if (width > length)
    {
        if (flags & FA_MINUS)
        {
            write(1, &str[0], length);
            for (i = width - length; i > 0; i--)
                write(1, " ", 1);
            return (width);
        }
        else
        {
            for (i = width - length; i > 0; i--)
                write(1, " ", 1);
            write(1, &str[0], length);
            return (width);
        }
    }

    return (write(1, str, length));
}

/**
 * fa_print_percent - Displays a percent sign
 * @types: List of arguments
 * @buffer: Buffer array to process printing
 * @flags:  Computes active flags
 * @width: get width.
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Number of characters printed
 */
int fa_print_percent(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    FA_UNUSED(types);
    FA_UNUSED(buffer);
    FA_UNUSED(flags);
    FA_UNUSED(width);
    FA_UNUSED(precision);
    FA_UNUSED(size);
    return (write(1, "%%", 1));
}


/**
 * fa_print_int - Displays integer
 * @types: List of arguments
 * @buffer: Buffer array to process printing
 * @flags:  Computes active flags
 * @width: get width.
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Number of characters printed
 */
int fa_print_int(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    int i = FA_BUFF_SIZE - 2;
    int is_negative = 0;
    long int n = va_arg(types, long int);
    unsigned long int num;

    n = fa_convert_size_number(n, size);

    if (n == 0)
        buffer[i--] = '0';

    buffer[FA_BUFF_SIZE - 1] = '\0';
    num = (unsigned long int)n;

    if (n < 0)
    {
        num = (unsigned long int)((-1) * n);
        is_negative = 1;
    }

    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    return (fa_write_number(is_negative, i, buffer, flags, width, precision, size));
}


/**
 * fa_print_binary - Displays an unsigned number in binary
 * @types: List of arguments
 * @buffer: Buffer array to handle printing
 * @flags:  Computes active flags
 * @width: get width.
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Number of characters printed
 */
int fa_print_binary(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    unsigned int n, m, i, sum;
    unsigned int a[32];
    int count;

    FA_UNUSED(buffer);
    FA_UNUSED(flags);
    FA_UNUSED(width);
    FA_UNUSED(precision);
    FA_UNUSED(size);

    n = va_arg(types, unsigned int);
    m = 2147483648; /* (2 ^ 31) */
    a[0] = n / m;
    for (i = 1; i < 32; i++)
    {
        m /= 2;
        a[i] = (n / m) % 2;
    }
    for (i = 0, sum = 0, count = 0; i < 32; i++)
    {
        sum += a[i];
        if (sum || i == 31)
        {
            char z = '0' + a[i];
            write(1, &z, 1);
            count++;
        }
    }
    return (count);
}

