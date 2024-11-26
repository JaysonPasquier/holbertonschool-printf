#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_number - Convertit un entier en base 10 et l'écrit.
 * @n: L'entier à convertir.
 *
 * Return: Le nombre de caractères écrits.
 */
int print_number(int n)
{
	char buffer[12];
	int i = 0, count = 0;
	unsigned int num = (n < 0) ? -n : n;

	if (n < 0)
		count += write(1, "-", 1);
	do {
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}

/**
 * _printf - Fonction principale.
 * @format: Chaîne de format.
 *
 * Return: Nombre de caractères imprimés.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			if (*format == 'c')
			{

				char c = va_arg(args, int);

				count += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (!str)
					str = "(null)";
				while (*str)
					count += write(1, str++, 1);
			}
			else if (*format == '%')
				count += write(1, "%", 1);
			else if (*format == 'd' || *format == 'i')
				count += print_number(va_arg(args, int));
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
