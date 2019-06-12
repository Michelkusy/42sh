/*
** EPITECH PROJECT, 2019
** exit
** File description:
** exit
*/

#include "42sh.h"

int exit_fun(function_t *tmp, general_t *general)
{
    if (my_strcompare("exit", tmp->str[0])) {
        if (tmp->str[1] == NULL && tmp->next == NULL)
            exit(general->ret);
        else if (tmp->str[1] == NULL) {
            general->exit = 1;
            return (1);
        } else {
            my_printf("exit: Expression Syntax.\n");
            return (1);
        }
    }
    return (0);
}
