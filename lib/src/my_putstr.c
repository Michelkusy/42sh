/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Print a string
*/

int write(int, char *, int);
int my_strlen(const char *);

void my_putstr(char const *str)
{
    write(1, (char *)str, my_strlen(str));
}

void my_putstr_error(char const *str)
{
    write(2, (char *)str, my_strlen(str));
}