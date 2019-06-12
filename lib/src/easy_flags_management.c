/*
** EPITECH PROJECT, 2018
** flags.c
** File description:
** first part of flags
*/

#include <stdarg.h>
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int flags_with_base_management(int argument, va_list display);

int easy_flags_management(int argument, va_list display)
{
    switch (argument){
    case 'c':
        my_putchar(va_arg(display, int));
        break;
    case 'd':
    case 'i':
        my_put_nbr(va_arg(display, int));
        break;
    case 's':
        my_putstr(va_arg(display, char *));
        break;
    case '%':
        my_putchar('%');
        break;
    default:
        flags_with_base_management(argument, display);
    }
    return (0);
}
