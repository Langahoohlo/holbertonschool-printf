#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * print_char - print a character to stdout
 * @c: character to be printed out
 * @length: length of what is to be printed
 * Return: length
 */

int print_char(va_list args, const char *format, int length, int pos)
{
	int i;

	for (i = 0; format[i]; i++)
	{
		if (i == pos)
		{
			if (format[i] == '\0')
				return (length);
			putchar(va_arg(args, int));
			return (length + 1);
		}
	}
	return (length);
}

/**
 * print_string - print a string to stdout
 * @str: pointer to a string that's to be printed
 * @length: length of what is going to be printed
 * Return: length
 */

int print_string(va_list args, const char *format, int length, int pos)
{
	int i, j;
	char nil[7] = "(null)", *str;

	for (j = 0; format[j]; j++)
	{
		str = va_arg(args, char *);
		if (str != NULL)
		{
			if (j == pos)
			{
				for (i= 0; str[i]; i++)
					putchar(str[i]);
				length += i;
				return (length);
			}
		}
		if (j == pos)
		{
			for (i = 0; nil[i]; i++)
				putchar(nil[i]);
			length += 6;
			return (length);
		}
	}
	return (length);
}

/**
 * handle_mod - handle modulo sign
 * @length: length of what is to be printed
 * Return: length
 */

int handle_mod (va_list args, const char *format, int length, int pos)
{
	(void) format;
	(void) args;
	(void) pos;

	putchar('%');
	return (length + 1);
}

/**
 * print_int - handles printing numbers
 * @num: number that's to be printed
 * @length: length of what is to be printed ouit to stdout
 * Return: length
 */

int print_int(va_list args, const char *format, int length, int pos)
{
	int i, j, num;
	char number[100];

	for (j = 0; format[j]; j++)
	{
		num = va_arg(args, int);
		if (j == pos)
		{
			sprintf(number, "%d", num);
			for (i = 0; number[i]; i++)
				putchar(number[i]);
			length += i;
			return (length);
		}
	}
	return (length);
}

/**
 * _printf - print argument according to format specifier
 * @format: what should be printed
 * Return: length
 */

int _printf(const char *format, ...)
{
	int i, j, length = 0;
	va_list args;
	spec format_spec[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", handle_mod},
		{"i", print_int},
		{"d", print_int}, 
		{NULL, NULL}
	};

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; format_spec[j].specifier != NULL; j++)
			{
				if (format[i + 1] == format_spec[j].specifier[0])
					length = format_spec[j].func(args, format, length, i);
				else
					return (length);
			}
			i++;
		} else
		{
			putchar(format[i]);
			length++;
		}
	}
	return (length);
}
