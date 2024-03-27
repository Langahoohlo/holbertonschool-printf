#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _printf - print arguments
 * @format: pointer to character
 * Return: length of what is to be printed
 */

int _printf(const char *format, ...) {
    int length = 0, i, j, k, l = 0;
    char *str, *ptr, c, nil[7] = "(null)";
    va_list args;
    va_list arg;

    if (format == NULL)
        return (0);

    va_start(args, format);

    for (i = 0; format[i]; i++) {
        switch(format[i]) {
            case '%':
                switch(format[i + 1]) {
                    case 'c':
                        va_arg(args, int);
                        length++;
                        i++;
                        break;

                    case 's':
                        str = va_arg(args, char *);
                        if (str == NULL)
                            length += 6;
                        else
                            length += strlen(str);
                        i++;
                        break;

                    case '%':
                        if (strlen(format) > 2)
                            length++;
                        else
                            length += 2;
                }
                break;
                default:
                        if (format[i] == '%')
                            length--;
                        else
                            length++;
                        break;
        }
    }
    va_end(args);

    ptr = malloc(length * sizeof(char));
    va_start(arg, format);
    for (i = 0, l = 0, k = 0; format[i]; i++) {
        switch(format[i]) {
            case '%':
                switch(format[i + 1]) {
                    case 'c':
                        c = va_arg(arg, int);
                        ptr[l] = c;
                        l++;
                        i++;
                        break;

                    case 's':
                        str = va_arg(arg, char *);
                        if (str == NULL)
                            for (j = 0; nil[j]; j++, l++)
                                ptr[l] = nil[j];
                        else
                            for (j = 0; str[j]; j++, l++)
                                ptr[l] = str[j];
                        i++;
                        break;

                    case '%':
                        	ptr[l] = '%';
                            l++;
							if (strlen(format) > 2)
								i++;
                }
                break;
            default:
                if (format[i - 1] != '%') {
                    k = l;
                    ptr[k] = format[i];
                    l++;
                }
                break;
        }
    }
    ptr[l] = '\0';
    for (l = 0; ptr[l]; l++)
        putchar(ptr[l]);
    free(ptr);
    return (length);
}
