/*
** EPITECH PROJECT, 2019
** my_add_to_dest.c
** File description:
** add a string to another string named dest
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_add_to_dest(char *dest, char *add)
{
    int dest_len = my_strlen(dest);
    int add_len = my_strlen(add);
    char *res = malloc(sizeof(char) * (dest_len + add_len + 1));
    int pos = 0;

    for (int i = 0; dest[i] != '\0'; i++) {
        res[pos] = dest[i];
        pos += 1;
    }
    res[pos] = '/';
    pos++;
    for (int i = 0; add[i] != '\0'; i++) {
        res[pos] = add[i];
        pos += 1;
    }
    res[pos] = '\0';
    return (res);
}
