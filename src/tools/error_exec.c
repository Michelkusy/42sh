/*
** EPITECH PROJECT, 2019
** error_exec
** File description:
** error
*/

#include "42sh.h"

int analyse_pipe(function_t *tmp)
{
    int b = 0;

    while (tmp != NULL) {
        if (tmp->op != NULL && tmp->op[0] == '|')
            b++;
        if (b == 10)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int message_error(int sig)
{
    if (WIFSIGNALED(sig)) {
        if (WTERMSIG(sig) == SIGSEGV)
            my_printf("Segmentation fault");
        else if (WTERMSIG(sig) == SIGFPE)
            my_printf("Floating exception");
        if (WTERMSIG(sig) == SIGABRT)
            my_printf("Aborted");
        if (WCOREDUMP(sig))
            my_printf(" (core dumped)");
        my_printf("\n");
    }
    return (sig);
}

int error_multiple_redirect(function_t *tmp)
{
    char *redirect[] = {">", "<", ">>", "<<"};
    int in = 0;
    int out = 0;

    for (int i = 0; tmp->str[i]; i++) {
        if (find_redirect(tmp->str[i], redirect) == 1 ||
            find_redirect(tmp->str[i], redirect) == 3)
            in++;
        if (find_redirect(tmp->str[i], redirect) == 2 ||
            find_redirect(tmp->str[i], redirect) == 4)
            out++;
    }
    if (in > 1 || out > 1 ) {
        my_printf("Ambiguous output redirect.\n");
        return (0);
    }
    if (in == 1 && out == 1)
        return (1);
    return (2);
}

int error_redirect(function_t *tmp)
{
    char *redirect[] = {">", "<", ">>", "<<"};

    if (find_redirect(tmp->str[0], redirect)) {
        my_printf("Invalid null command.\n");
        return (1);
    }
    for (int i = 0; tmp->str[i]; i++) {
        if (find_redirect(tmp->str[i], redirect) &&
            (check_string(tmp->str[i + 1]) == 2 ||
            find_redirect(tmp->str[i + 1], redirect))) {
            my_printf("Missing name for redirect.\n");
            return (1);
        }
    }
    if (error_multiple_redirect(tmp) == 0)
        return (1);
    return (0);
}

int check_env(general_t *general)
{
    int q = 0;
    int a = 0;
    int g = 0;

    for (int h = 0; general->env[h]; h++) {
        if (general->env[h][0] == 'P' && general->env[h][1] == 'W'
            && general->env[h][2] == 'D' && a == 0) {
            q++;
            a++;
        } else if (general->env[h][0] == 'P' && general->env[h][1] == 'A'
            && general->env[h][2] == 'T' && general->env[h][3] == 'H'
            && g == 0) {
            q++;
            g++;
        }
    }
    if (q == 2)
        return (0);
    else
        return (1);
}
