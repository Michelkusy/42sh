/*
** EPITECH PROJECT, 2019
** history.c
** File description:
** history
*/

#include "42sh.h"

void display_history(history_t *history)
{
    for (int i = 1; history; i++) {
        my_printf(" %d\t", i);
        my_printf("%d:%d\t", history->date.tm_hour, history->date.tm_min);
        for (int b = 0; history->history[b]; b++)
            my_printf(" %s", history->history[b]);
        my_printf("\n");
        history = history->next;
    }
}

int history_fun(general_t *general, function_t *tmp)
{
    if (my_strcompare("history", tmp->str[0])) {
        if (tmp->str[1] != NULL) {
            my_printf("bash: history: %s: numeric argument required\n",
                        tmp->str[1]);
            general->ret = 1;
        } else {
            display_history(general->next_h);
            general->ret = 0;
        }
        return (1);
    }
    return (0);
}

void add_history(char **str, general_t *general)
{
    history_t *history = malloc(sizeof(history_t));
    history_t *tmp = general->next_h;
    time_t temps;

    time(&temps);
    history->date = *gmtime(&temps);
    history->history = str;
    history->next = NULL;
    if (general->next_h == NULL) {
        general->next_h = history;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = history;
    return;
}
