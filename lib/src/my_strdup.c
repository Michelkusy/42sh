/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdlib.h>
int my_strlen(char *);

char *my_strdup(char *s1)
{
    char *copy = malloc(sizeof(char) * (my_strlen(s1) + 1));

    if (copy == NULL)
        return (NULL);
    if (s1 == NULL)
        return (NULL);
    for (int i = 0; s1[i]; i++)
        copy[i] = s1[i];
    copy[my_strlen(s1)] = 0;
    return (copy);
}
