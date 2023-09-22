#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * @ FA: Fenet and Agaba
 */

#define FA_UNUSED(x) (void)(x)
#define FA_BUFF_SIZE 1024

#define FA_MINUS 1
#define FA_PLUS 2
#define FA_ZERO 4
#define FA_HASH 8
#define FA_SPACE 16

#define FA_LONG 2
#define FA_SHORT 1

/**
 * struct fa_fmt - Format specification structure
 *
 * @fa_fmt: format.
 * @fa_fn: function associated.
 */
struct fa_fmt
{
    char fa_fmt;
    int (*fa_fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fa_fmt fa_fmt_t - Format specification structure
 *
 * @fa_fmt: format.
 * @fa_fn: function associated.
 */
typedef struct fa_fmt fa_fmt_t;

int _printf(const char *format, ...);
int fa_process_print(const char *fa_fmt, int *i,
                     va_list list, char buffer[], int flags, int width, int precision, int size);
int fa_print_char(va_list types, char buffer[],
                  int flags, int width, int precision, int size);
int fa_print_string(va_list types, char buffer[],
                    int flags, int width, int precision, int size);
int fa_print_percent(va_list types, char buffer[],
                     int flags, int width, int precision, int size);

int fa_print_int(va_list types, char buffer[],
                 int flags, int width, int precision, int size);
int fa_print_binary(va_list types, char buffer[],
                    int flags, int width, int precision, int size);
int fa_print_unsigned(va_list types, char buffer[],
                      int flags, int width, int precision, int size);
int fa_print_octal(va_list types, char buffer[],
                   int flags, int width, int precision, int size);
int fa_print_hexadecimal(va_list types, char buffer[],
                         int flags, int width, int precision, int size);
int fa_print_hexa_upper(va_list types, char buffer[],
                        int flags, int width, int precision, int size);

int fa_print_hexa(va_list types, char map_to[],
                  char buffer[], int flags, char flag_ch, int width, int precision, int size);

int fa_print_non_printable(va_list types, char buffer[],
                           int flags, int width, int precision, int size);

int fa_print_pointer(va_list types, char buffer[],
                     int flags, int width, int precision, int size);

int fa_get_flags(const char *format, int *i);
int fa_get_width(const char *format, int *i, va_list list);
int fa_get_precision(const char *format, int *i, va_list list);
int fa_get_size(const char *format, int *i);

int fa_print_reverse(va_list types, char buffer[],
                     int flags, int width, int precision, int size);

int fa_print_rot13string(va_list types, char buffer[],
                         int flags, int width, int precision, int size);

int fa_process_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int fa_write_number(int is_positive, int ind, char buffer[],
                    int flags, int width, int precision, int size);
int fa_write_num(int ind, char bff[], int flags, int width, int precision,
                 int length, char padd, char extra_c);
int fa_write_pointer(char buffer[], int ind, int length,
                     int width, int flags, char padd, char extra_c, int padd_start);

int fa_write_unsigned(int is_negative, int ind,
                      char buffer[],
                      int flags, int width, int precision, int size);

int fa_is_printable(char);
int fa_append_hexa_code(char, char[], int);
int fa_is_digit(char);

long int fa_convert_size_number(long int num, int size);
long int fa_convert_size_unsigned(unsigned long int num, int size);

#endif

