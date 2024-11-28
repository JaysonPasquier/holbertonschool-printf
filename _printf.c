#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - print a character
 * @c: the char to print
 * Return: number of char printed (always 1)
 */
int print_char(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_string - print a string of char
 * @s: the string to print
 * Return: number of char printed
 */
int print_string(char *s)
{
    int count = 0;

    if (!s)
        s = "(null)";
    while (*s)
        count += print_char(*s++);
    return (count);
}

/**
 * print_number - convert a int to base 10 and print it
 * @n: int to convert
 * Return: number of char printed
 */
int print_number(int n)
{
    char buffer[12];
    int i = 0, count = 0;
    unsigned int num = (n < 0) ? -n : n;

    if (n < 0)
        count += print_char('-');
    do {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    while (i--)
        count += print_char(buffer[i]);

    return (count);
}

/**
 * handle_format - handle the spec of format
 * @format: spec of the format
 * @args: list of variadic arguments
 * Return: number of char printed for the spec
 */
int handle_format(const char **format, va_list args)
{
    printf_functions pf = {print_char, print_string, print_number, handle_format};
    int count = 0, i, base;
    char buffer[32], *digits = "0123456789abcdef";
    unsigned long int num;

    if (**format == 'c')
        return (pf.print_char(va_arg(args, int)));
    if (**format == 's')
        return (pf.print_string(va_arg(args, char *)));
    if (**format == '%')
        return (pf.print_char('%'));
    if (**format == 'd' || **format == 'i')
        return (pf.print_number(va_arg(args, int)));

    if (**format == 'u' || **format == 'o' || **format == 'x' ||
     **format == 'X' || **format == 'p')
    {
        num = (**format == 'p') ? (unsigned long int)va_arg(args, void *) :
              va_arg(args, unsigned int);
        base = (**format == 'o') ? 8 : (**format == 'u') ? 10 : 16;

        if (**format == 'p')
            count += pf.print_string("0x");
        if (**format == 'X')
            digits = "0123456789ABCDEF";

        i = 0;
        do {
            buffer[i++] = digits[num % base];
            num /= base;
        } while (num && i < 31);

        while (i--)
            count += pf.print_char(buffer[i]);

        return (count);
    }

    count += pf.print_char('%');
    count += pf.print_char(**format);
    return (count);
}

/**
 * _printf - Produces a formatted output according to a given string.
 * @format: Format string.
 * Return: The number of characters printed or -1 in case of an error.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    printf_functions pf = {print_char, print_string, print_number, handle_format};

    if (!format)
        return (-1);

    va_start(args, format);
    while (*format)
    {
        if (*format != '%')
            count += pf.print_char(*format);
        else if (*(++format))
            count += pf.handle_format(&format, args);
        format++;
    }
    va_end(args);

    return (count);
}
