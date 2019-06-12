/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "42sh.h"

void helper(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_printf("UNIX command interpreter\n");
    }
}

int main_test(int ac, char **av, char **env)
{
    general_t *general = malloc(sizeof(general_t));

    if (general == NULL)
        return (84);
    general->path = NULL;
    general->next = NULL;
    helper(ac, av);
    my_printf("\e[31m[Fédération.Turque]\e[32m[%s]\033[32;5m>\033[0m ",
                get_time());
    return (minishell(general, env));
}
