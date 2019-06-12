/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** task faild
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    int i = 0;
    int k = 0;

    while (dest[i] != '\0') {
        str[i] = dest[i];
        i++;
    }
    while (src[k] != '\0') {
        str[i] = src[k];
        i++;
        k++;
    }
    str[i] = '\0';
    return (str);
}

char *my_strcat_sp(char *dest, char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + (2)));
    int i = 0;
    int k = 0;

    while (dest[i] != '\0') {
        str[i] = dest[i];
        i++;
    }
    str[i++] = '/';
    while (src[k] != '\0') {
        str[i] = src[k];
        i++;
        k++;
    }
    str[i] = '\0';
    return (str);
}
