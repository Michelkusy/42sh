/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Count the lenght of a string
*/

int my_strlen(const char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
