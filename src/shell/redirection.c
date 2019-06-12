/*
** EPITECH PROJECT, 2019
** redirection
** File description:
** redirection
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "42sh.h"

int find_redirect(char *str, char **redirect)
{
    if (my_strcompare(str, redirect[0]))
        return (1);
    if (my_strcompare(str, redirect[1]))
        return (2);
    if (my_strcompare(str, redirect[2]))
        return (3);
    if (my_strcompare(str, redirect[3]))
        return (4);
    return (0);
}

int calcul_in(function_t *tmp, general_t *general, int nb)
{
    char *redirect[] = {">", "<", ">>", "<<"};

    for (int i = 0; i < nb; i++) {
        if (tmp->str[i] && find_redirect(tmp->str[i], redirect) == 1)
            return (entrance_redirect(tmp, general, i));
        else if (tmp->str[i] && find_redirect(tmp->str[i], redirect) == 3)
            return (double_entrance(tmp, general, i));
    }
    return (1);
}

int calcul_out(function_t *tmp, general_t *general, int nb)
{
    char *redirect[] = {">", "<", ">>", "<<"};

    for (int i = 0; i < nb; i++) {
        if (tmp->str[i] && find_redirect(tmp->str[i], redirect) == 2)
            return (exit_redirect(tmp, general, i));
        else if (tmp->str[i] && find_redirect(tmp->str[i], redirect) == 4)
            return (double_exit(tmp, general, i));
    }
    return (1);
}

int multiple_redirect(function_t *tmp, general_t *general)
{
    int in;
    int out;
    int nb;

    for (nb = 0; tmp->str[nb]; nb++);
    out = calcul_out(tmp, general, nb);
    if (out)
        return (1);
    in = calcul_in(tmp, general, nb);
    if (in == 0 && out == 0)
        return (0);
    return (1);
}

int redirection_analyse(function_t *tmp, general_t *general)
{
    char *redirect[] = {">", "<", ">>", "<<"};

    if (error_multiple_redirect(tmp) == 1)
        return (multiple_redirect(tmp, general));

    for (int i = 0; tmp->str[i]; i++) {
        if (find_redirect(tmp->str[i], redirect) == 1)
            return (entrance_redirect(tmp, general, i));
        if (find_redirect(tmp->str[i], redirect) == 2)
            return (exit_redirect(tmp, general, i));
        if (find_redirect(tmp->str[i], redirect) == 3)
            return (double_entrance(tmp, general, i));
        if (find_redirect(tmp->str[i], redirect) == 4)
            return (double_exit(tmp, general, i));
    }
    return (0);
}
