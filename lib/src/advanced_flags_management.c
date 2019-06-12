/*
** EPITECH PROJECT, 2018
** flags3.c
** File description:
** other flags for my printf
*/

#include <stdarg.h>
int none_signed(long nb);
int my_putstr(char const *str);
int my_put_nbr_base(unsigned long long nb, char *base_str);
void my_print_special(char *str);
void my_putchar(char c);

int advanced_flags_management(int argument, va_list display)
{
    switch (argument){
    case 'u':
        none_signed(va_arg(display, long));
        break;
    case 'p':
        my_putstr("0x");
        my_put_nbr_base(va_arg(display, unsigned long long),
                        "0123456789abcdef");
        break;
    case 'S':
        my_print_special(va_arg(display, char *));
        break;
    default :
        my_putchar('%');
        my_putchar(argument);
    }
    return (0);
}
