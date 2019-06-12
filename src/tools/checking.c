/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** check_tools
*/

#include "42sh.h"

int check_signe(char *str)
{
    if (my_strcompare("|", str) == 1)
        return (1);
    if (my_strcompare(";", str) == 1)
        return (1);
    if (my_strcompare("||", str) == 1)
        return (1);
    if (my_strcompare("&&", str) == 1)
        return (1);
    return (0);
}

int get_case(char *str)
{
    for (int b = 0; str[b]; b++) {
        if (str[b] == '|' && str[b + 1] == '\0')
            return (2);
        else if (str[b] == '|' && str[ b + 1] != '|')
            return (3);
        if (str[b] == ';' && str[b + 1] == '\0')
            return (2);
        else if (str[b] == ';')
            return (3);
        if (str[b] == '|' && str[b + 1] == '|' && str[b + 2] == '\0')
            return (2);
        else if (str[b] == '|' && str[b + 1] == '|')
            return (3);
        if (str[b] == '&' && str[b + 1] == '&' && str[b + 2] == '\0')
            return (2);
        else if (str[b] == '&' && str[b + 1] == '&')
            return (3);
    }
    return (0);
}

int check_argument(char *str)
{
    int nb = 0;

    if (check_signe(str) == 1)
        return (1);
    nb = get_case(str);
    if (nb != 0)
        return (nb);
    return (0);
}

int check_next(function_t *tmp, int ret)
{
    if (tmp == NULL)
        return (1);
    if (tmp->op != NULL && my_strcompare("&&", tmp->op) && ret != 0)
        return (1);
    if (tmp->op != NULL && my_strcompare("||", tmp->op) && ret == 0)
        return (1);
    return (0);
}
