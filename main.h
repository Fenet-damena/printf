#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int _putchar(char c);
int _printf(const char format, ...);
int print_num(va_list n);
int print_string(va_list s);
int _strlen(const chars);
int _strcmp(const char s, const chart);
int (*cmp_func(const char a))(va_list);
int print_char(va_list arr);
void print_bin(unsigned int num);
int print_unsigned(va_list n);

/**
 
struct types - specifier structure for printf
@p: pointer to characteres specifiers
@func : function pointer to print fucntions
*/
typedef struct types
{
    char p;
    int (*func)(va_list);
} myprintf;
#endif