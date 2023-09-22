#include "main.h"

/**
 * fa_print_pointer - Displays the value of a pointer variable
 * @types: List of arguments
 * @buffer: Buffer array to process printing
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision parameter
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int fa_print_pointer(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    char extra_c = 0, padd = ' ';
    int ind = FA_BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
    unsigned long num_addrs;
    char map_to[] = "0123456789abcdef";
    void *addrs = va_arg(types, void *);

    FA_UNUSED(width);
    FA_UNUSED(size);

    if (addrs == NULL)
        return (write(1, "(nil)", 5));

    buffer[FA_BUFF_SIZE - 1] = '\0';
    FA_UNUSED(precision);

    num_addrs = (unsigned long)addrs;

    while (num_addrs > 0)
    {
        buffer[ind--] = map_to[num_addrs % 16];
        num_addrs /= 16;
        length++;
    }

    if ((flags & FA_ZERO) && !(flags & FA_MINUS))
        padd = '0';
    if (flags & FA_PLUS)
        extra_c = '+', length++;
    else if (flags & FA_SPACE)
        extra_c = ' ', length++;

    ind++;

    /*return (write(1, &buffer[i], FA_BUFF_SIZE - i - 1));*/
    return (fa_write_pointer(buffer, ind, length,
        width, flags, padd, extra_c, padd_start));
}


/**
 * fa_print_non_printable - Displays ASCII codes in hexadecimal of non-printable characters
 * @types: List of arguments
 * @buffer: Buffer array to process printing
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision parameter
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int fa_print_non_printable(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    int i = 0, offset = 0;
    char *str = va_arg(types, char *);

    FA_UNUSED(flags);
    FA_UNUSED(width);
    FA_UNUSED(precision);
    FA_UNUSED(size);

    if (str == NULL)
        return (write(1, "(null)", 6));

    while (str[i] != '\0')
    {
        if (fa_is_printable(str[i]))
            buffer[i + offset] = str[i];
        else
            offset += fa_append_hexa_code(str[i], buffer, i + offset);

        i++;
    }

    buffer[i + offset] = '\0';

    return (write(1, buffer, i + offset));
}


/**
 * fa_print_reverse - Displays a string in reverse.
 * @types: List of arguments
 * @buffer: Buffer array to process printing
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision parameter
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int fa_print_reverse(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    char *str;
    int i, count = 0;

    FA_UNUSED(buffer);
    FA_UNUSED(flags);
    FA_UNUSED(width);
    FA_UNUSED(size);

    str = va_arg(types, char *);

    if (str == NULL)
    {
        FA_UNUSED(precision);
        str = ")Null(";
    }
    for (i = 0; str[i]; i++)
        ;

    for (i = i - 1; i >= 0; i--)
    {
        char z = str[i];
        write(1, &z, 1);
        count++;
    }
    return (count);
}


/**
 * fa_print_rot13string - Displays a string in ROT13.
 * @types: List of arguments
 * @buffer: Buffer array to handle printing
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision parameter
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int fa_print_rot13string(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    char x;
    char *str;
    unsigned int i, j;
    int count = 0;
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    str = va_arg(types, char *);
    FA_UNUSED(buffer);
    FA_UNUSED(flags);
    FA_UNUSED(width);
    FA_UNUSED(precision);
    FA_UNUSED(size);

    if (str == NULL)
        str = "(AHYY)";
    for (i = 0; str[i]; i++)
    {
        for (j = 0; in[j]; j++)
        {
            if (in[j] == str[i])
            {
                x = out[j];
                write(1, &x, 1);
                count++;
                break;
            }
        }
        if (!in[j])
        {
            x = str[i];
            write(1, &x, 1);
            count++;
        }
    }
    return (count);
}

