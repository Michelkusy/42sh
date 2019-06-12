/*
** EPITECH PROJECT, 2019
** pipe.c
** File description:
** pipe
*/

#include "42sh.h"

void exec_right(general_t *general, function_t *tmp_left)
{
    char *element;

    for (int i = 0; general->path[i]; i++) {
        element = my_strcat_sp(general->path[i], tmp_left->str[0]);
        execve(element, tmp_left->str, general->env);
    }
    my_printf("%s: command not found.\n", tmp_left->str[0]);
    exit (0);
}

void exec_left(general_t *general, function_t *tmp_right)
{
    char *element;

    for (int i = 0; general->path[i]; i++) {
        element = my_strcat_sp(general->path[i], tmp_right->str[0]);
        execve(element, tmp_right->str, general->env);
    }
    my_printf("%s: command not found.\n", tmp_right->str[0]);
    exit (0);
}

void exec_pipe(function_t *tmp_left, function_t *tmp_right, general_t *general)
{
    int pid;
    int pfd[2];

    pipe(pfd);
    pid = fork();
    if (pid == 0) {
        close(pfd[0]);
        dup2(pfd[1], 1);
        close(pfd[1]);
        exec_left(general, tmp_left);
    } else {
        close(pfd[1]);
        dup2(pfd[0], 0);
        close(pfd[0]);
        exec_right(general, tmp_right);
    }
}

function_t *fun_pipe(function_t *tmp, general_t *general)
{
    function_t *last = tmp;

    while (last != NULL && last->op != NULL
    && last->op[0] == '|' && last->op[1] == '\0')
        last = last->next;
    if (fork())
        wait(NULL);
    else
        exec_pipe(tmp, tmp->next, general);
    return (last->next);
}
