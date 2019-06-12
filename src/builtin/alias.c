/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Alias command
*/

#include "42sh.h"

int alias_fun(function_t *tmp)
{
    if (my_strcompare("alias", tmp->str[0])) {
        if (tmp->str[1] == NULL && tmp->str[2] == NULL) {
            my_printf("missing arguments\n");
            return (1);
        }
    }
    return (0);
}
