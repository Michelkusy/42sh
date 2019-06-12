/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** little function used on 42sh
*/

#include "42sh.h"

int nb_array(char **order)
{
    int nb = 0;

    while (order[nb])
        nb++;
    return nb;
}

int check_error_first(char *str)
{
    if (str[0] == ';' || str[0] == '|') {
        my_printf("bash: syntax error near unexpected token '%c'\n", str[0]);
        exit(84);
    }
    return (0);
}

int check_add_last(char **str, char *order)
{
    if (check_argument(order) == 3) {
        *str = add_down_str(order);
        return (1);
    }
    return (0);
}

void purge_back(char *str)
{
    while (*str != '\0') {
        *str = *(str + 1);
        str += 1;
    }
}

void free_all(general_t *general, char **env)
{
    if (general->exit == 1) {
        free(general);
        free(env);
    }
}
