/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** No description
*/

int my_getnbr(char const *str)
{
    int result = 0;
    int negative = 0;
    long test = 0;
    int i = 0;

    for (i = 0; str[i] < '0' || str[i] > '9'; i++)
        if (str[i] == '\0')
            return (0);
    if (i > 0 && str[i - 1] == '-')
        negative++;
    for (i = i; str[i] == '0'; i++);
    for (i = i; str[i] >= '0' && str[i] <= '9' && str[i] != '\0'; i++) {
        test = test * 10 + str[i] - 48;
        if (test >= 2147483647 || test <= -2147483648)
            return (0);
        result = result * 10 + str[i] - 48;
    }
    if (negative == 1)
        result = -result;
    return (result);
}
