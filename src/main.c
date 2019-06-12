/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "42sh.h"
#include <stdbool.h>

bool helper(int ac, char **av)
{
    if (ac == 2) {
        if (my_strcompare(av[1], (char *) HELP_ARGS)) {
            my_printf((char *) HELP_ARGS_LANG);
            return (true);
        }
    }
    return (false);
}

int main (int ac, char **av, char **env)
{
    general_t *general = malloc(sizeof(general_t));

    if (general == NULL)
        return (EXIT_FAIL);
    general->path = NULL;
    general->next = NULL;
    if (helper(ac, av))
        return (EXIT_OK);
    return (minishell(general, env));
}
