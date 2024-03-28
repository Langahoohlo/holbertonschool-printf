#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
/**
 * print_char - print a character to stdout
 * @c: character to be pribted to stdout
 * @length: length of what is to be printed
 */
int print_char(char c, int length)
{
    putchar(c);
    length++;
    return (length);
}
/**
 * print_string - print a string to stdout
 * @str: pointer to a string thats to be printed
 * @length: length of what is to be printed
 * Return: pointer
 */
int print_string(const char *str, int length)
{
    int i;
    char nil[7] = "(null)";
    if (str != NULL)
    {
        for (i = 0; str[i]; i++)
            putchar(str[i]);
        length += i;
        return (length);
    }
    else
    {
        for (i = 0; nil[i]; i++)
            putchar(nil[i]);
        length += 6;
        return (length);
    }
}
/**
 * handle_mod - handle modulas sign
 * @length: length of what is to be printed
 * @n: used to determine whether to print two modulo signs or just one
 */
int handle_mod(int length)
{
    putchar('%');
    length++;
    return (length);
}
/**
 * _printf - print arguments
 * @format: pointer to character
 * Return: length of what is to be printed
 */
int _printf(const char *format, ...)
{
    int length = 0, i;
    va_list args;
    if (format == NULL)
        return (-1);
    va_start(args, format);
    for (i = 0; format[i]; i++)
    {
        switch (format[i])
        {
        case '%':
            switch (format[i + 1])
            {
            case 'c':
                length = print_char(va_arg(args, int), length);
                i++;
                break;
            case 's':
                length = print_string(va_arg(args, char *), length);
                i++;
                break;
            case '%':
                if (strlen(format) > 2)
                {
                    length = handle_mod(length);
                    i++;
                }
                break;
            case '\0':
                length = print_char(format[i], length);
                break;

            default:
                print_string(format, length);
                i++;
                break;
            }
            break;
        default:
            if (format[i] == '%')
            {
                length--;
            }
            else
                length = print_char(format[i], length);
            break;
        }
    }
    va_end(args);
    
    return (length);
}
