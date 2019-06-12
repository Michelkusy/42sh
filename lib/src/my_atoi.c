/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** Convert a string into integer
*/

int my_strlen(char *);

int my_atoi(char *str)
{
    int number = 0;

    if (my_strlen(str) >= 10)
        return (0);
    for (int i = 0; str[i] >= '0' && str[i] <= '9'; i++)
        number = number * 10 + (str[i] - '0');
    return (number);
}
