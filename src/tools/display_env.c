/*
** EPITECH PROJECT, 2019
** basic_function.c
** File description:
** basic_function
*/

#include "42sh.h"

void display_env(general_t *general)
{
    for (int i = 0; general->env[i]; i++)
        my_printf("%s\n", general->env[i]);
}

int env_fun(general_t *general, function_t *tmp)
{
    if (my_strcompare("env", tmp->str[0])) {
        if (tmp->str[1] != NULL) {
            general->ret = 1;
            my_printf("env: '%s': No such file or directory.\n", tmp->str[1]);
            return (1);
        }
        general->ret = 0;
        display_env(general);
        return (1);
    }
    return (0);
}
