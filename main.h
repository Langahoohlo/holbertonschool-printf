#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int print_char(char c, int length);
int print_string(const char *str, int length);
int handle_mod(int length);
int print_int(int num, int length);

typedef struct format_specifier
{
	char *specifier;
	int (*func)(va_list, const char *format, int length);
} spec;

#endif /* MAIN_H */
