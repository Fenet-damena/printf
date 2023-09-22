#include "main.h"


/**
 * fa_print_unsigned - Displays an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array to process printing
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision parameter
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int fa_print_unsigned(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    int i = FA_BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);

    num = fa_convert_size_unsigned(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[FA_BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    return (fa_write_unsigned(0, i, buffer, flags, width, precision, size));
}


/**
 * fa_print_octal - Displays an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to process printing
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision parameter
 * @size: Size specifier
 * Return: Number of characters printed
 */
int fa_print_octal(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    int i = FA_BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    FA_UNUSED(width);

    num = fa_convert_size_unsigned(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[FA_BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[i--] = (num % 8) + '0';
        num /= 8;
    }

    if (flags & FA_HASH && init_num != 0)
        buffer[i--] = '0';

    i++;

    return (fa_write_unsigned(0, i, buffer, flags, width, precision, size));
}


/**
 * fa_print_hexadecimal - Displays an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to process printing
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision parameter
 * @size: Size specifier
 * Return: Number of characters printed
 */
int fa_print_hexadecimal(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    return (fa_print_hexa(types, "0123456789abcdef", buffer,
        flags, 'x', width, precision, size));
}


/**
 * fa_print_hexa_upper - Displays an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle printing
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision parameter
 * @size: Size specifier
 * Return: Number of characters printed
 */
int fa_print_hexa_upper(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    return (fa_print_hexa(types, "0123456789ABCDEF", buffer,
        flags, 'X', width, precision, size));
}


/**
 * fa_print_hexa - Prints a hexadecimal number in lower or upper case
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle printing
 * @flags: Computes flags
 * @flag_ch: Computes active flags
 * @width: Width
 * @precision: Precision parameter
 * @size: Size specifier
 * Return: Number of characters printed
 */
int fa_print_hexa(va_list types, char map_to[], char buffer[],
    int flags, char flag_ch, int width, int precision, int size)
{
    int i = FA_BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    FA_UNUSED(width);

    num = fa_convert_size_unsigned(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[FA_BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[i--] = map_to[num % 16];
        num /= 16;
    }

    if (flags & FA_HASH && init_num != 0)
    {
        buffer[i--] = flag_ch;
        buffer[i--] = '0';
    }

    i++;

    return (fa_write_unsigned(0, i, buffer, flags, width, precision, size));
}

