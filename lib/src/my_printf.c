/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** create again the printf program in the C lib
*/

#include <stdarg.h>
#include <stdio.h>
int easy_flags_management(int argument, va_list display);
void my_putchar(char c);

int my_printf(char *str, ...)
{
    int i = 0;
    int argument;
    va_list display;

    va_start(display, str);
    while (str[i] != '\0'){
        if (str[i] == '%'){
            i++;
            argument = str[i];
            easy_flags_management(argument, display);
            i++;
        } else {
            my_putchar(str[i]);
            i++;
        }
    }
    va_end(display);
    return (0);
}
