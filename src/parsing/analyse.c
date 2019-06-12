/*
** EPITECH PROJECT, 2019
** analyse
** File description:
** analyse
*/

#include "42sh.h"

int advance_analyse(function_t *tmp, general_t *general)
{
    if (echo_fun(general, tmp) == 1)
        return (1);
    if (history_fun(general, tmp) == 1)
        return (1);
    if (alias_fun(tmp) == 1)
        return (1);
    if (which_fun(general, tmp) == 1)
        return (1);
    return (0);
}

int basic_analyse(function_t *tmp, general_t *general)
{
    if (exit_fun(tmp, general) == 1)
        return (1);
    if (cd_fun(tmp, general) == 1)
        return (1);
    if (set_local(general, tmp) == 1)
        return (1);
    if (env_fun(general, tmp) == 1)
        return (1);
    if (setenv_fun(general, tmp) == 1)
        return (1);
    if (unsetenv_fun(general, tmp) == 1)
        return (1);
    return (advance_analyse(tmp, general));
}

function_t *advanced_analyse(function_t *tmp, general_t *general)
{
    if (tmp->op != NULL && tmp->op[0] == '|' && tmp->op[1] == '\0') {
        return (fun_pipe(tmp, general));
    }
    exec_fun(tmp, general);
    if (check_next(tmp, general->ret) == 1)
        return (NULL);
    tmp = tmp->next;
    return (tmp);
}

void pars_inib(function_t *tmp)
{
    int i = 0;
    int j = 0;

    while (tmp->str[i] != NULL) {
        j = 0;
        while (tmp->str[i][j] != '\0') {
            if (tmp->str[i][j] == '\\') {
                purge_back(&tmp->str[i][j]);
                purge_back(&tmp->str[i][j]);
            }
            j++;
        }
        i++;
    }
}

void analyse(general_t *general)
{
    function_t *tmp = general->next;

    pars_inib(tmp);
    if (analyse_pipe(tmp) || error_redirect(tmp))
        return;
    while (tmp != NULL) {
        if (redirection_analyse(tmp, general) == 1) {
            if (check_next(tmp, general->ret) == 1)
                break;
            tmp = tmp->next;
        } else if (basic_analyse(tmp, general) == 1) {
            if (check_next(tmp, general->ret) == 1)
                break;
            tmp = tmp->next;
        } else
            tmp = advanced_analyse(tmp, general);
    }
}
