/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** utils
*/

#include "42sh.h"

int tab_len(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL ; i++);
    return (i);
}

char *remove_one_char(char *str)
{
    char *string = malloc(sizeof(char) * my_strlen(str));

    for (int i = 0, j = 1 ; str[j] != '\0' ; i++, j++) {
        string[i] = str[j];
        string[i + 1] = '\0';
    }
    return (string);
}