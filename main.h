#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int print_char(va_list, const char *format, int length, int pos);
int print_string(va_list, const char *format, int length, int pos);
int handle_mod(va_list, const char *format, int length, int pos);
int print_int(va_list, const char *format, int length, int pos);

typedef struct
{
	char *specifier;
	int (*func)(va_list, const char *format, int length, int pos);
} spec;

#endif /* MAIN_H */
