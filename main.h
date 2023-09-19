#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int output_int(int n);
int _putchar(char c);
int output_unsignedint(int n);
int _printf(const char *format, ...);
int _strlen(const char *str);
int output_string(char *str);
int output_String(char *str);
int output_float(float n);
int output_binary(unsigned long int n);
size_t process_specifiers(const char *format, va_list list);


