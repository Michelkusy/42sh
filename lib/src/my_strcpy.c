/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** my_strcpy
*/

#include <stdlib.h>

char *my_strcpy(char *src, char *dest)
{
    int i;

    if (dest == NULL || src == NULL)
        return (NULL);
    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}