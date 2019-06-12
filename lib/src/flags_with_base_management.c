/*
** EPITECH PROJECT, 2018
** flags2.c
** File description:
** other flags that I append to another function for better visibility
*/

#include <stdarg.h>
int my_put_nbr_base(unsigned long long nb, char *base_str);
int advanced_flags_management(int argument, va_list display);

int flags_with_base_management(int argument, va_list display)
{
    switch (argument){
    case 'X':
        my_put_nbr_base(va_arg(display, unsigned long long),
                        "0123456789ABCDEF");
        break;
    case 'x':
        my_put_nbr_base(va_arg(display, unsigned long long),
                        "0123456789abcdef");
        break;
    case 'b':
        my_put_nbr_base(va_arg(display, unsigned long long), "01");
        break;
    case 'o':
        my_put_nbr_base(va_arg(display, unsigned long long), "01234567");
        break;
    default:
        advanced_flags_management(argument, display);
    }
    return (0);
}
