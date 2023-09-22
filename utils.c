#include "main.h"

/**
 * fa_is_printable - Assesses a char is printable
 * @c: Char to be assessed.
 *
 * Return: 1 if c is a printable character, 0 otherwise
 */
int fa_is_printable(char c)
{
    if (c >= 32 && c < 127)
        return (1);

    return (0);
}

/**
 * fa_append_hexa_code - Append ASCII in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */
int fa_append_hexa_code(char ascii_code, char buffer[], int i)
{
    char map_to[] = "0123456789ABCDEF";
    /* The hexadecimal format code is always 2 digits long */
    if (ascii_code < 0)
        ascii_code *= -1;

    buffer[i++] = '\\';
    buffer[i++] = 'x';

    buffer[i++] = map_to[ascii_code / 16];
    buffer[i] = map_to[ascii_code % 16];

    return (3);
}

/**
 * fa_is_digit - Verifies if a char is a digit
 * @c: Char to be verified.
 *
 * Return: 1 if 'c' is a printable digit, 0 otherwise
 */
int fa_is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);

    return (0);
}

/**
 * fa_convert_size_number - Converts a number to the specified size using casting.
 * @num: Number to be converted.
 * @size: Number indicating the type to be converted to casting.
 *
 * Return: Casted value of num
 */
long int fa_convert_size_number(long int num, int size)
{
    if (size == FA_LONG)
        return (num);
    else if (size == FA_SHORT)
        return ((short)num);

    return ((int)num);
}

/**
 * fa_convert_size_unsgnd - Converts a number to the specified size using casting.
 * @num: Number to be converted.
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int fa_convert_size_unsgnd(unsigned long int num, int size)
{
    if (size == FA_LONG)
        return (num);
    else if (size == FA_SHORT)
        return ((unsigned short)num);

    return ((unsigned int)num);
}

