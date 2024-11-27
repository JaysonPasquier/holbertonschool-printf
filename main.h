#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct printf_functions - Structure for printf functions
 * @print_char: Function to print a character
 * @print_string: Function to print a string
 * @print_number: Function to print a number
 * @handle_format: Function to handle format specifiers
 */
typedef struct printf_functions
{
    int (*print_char)(char);
    int (*print_string)(char *);
    int (*print_number)(int);
    int (*handle_format)(const char **, va_list, struct printf_functions *);
} printf_functions;

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *s);
int print_number(int n);
int handle_format(const char **format, va_list args, printf_functions *pf);

#endif
