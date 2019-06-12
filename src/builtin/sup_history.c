/*
** EPITECH PROJECT, 2019
** hsitory_sup
** File description:
** history
*/

#include "42sh.h"

char **sup_array(char **tmp, char **sup)
{
    char **str = malloc(sizeof(char *) * (tab_len(tmp) + tab_len(sup)));
    int i = 0;

    for (int b = 0; tmp[b]; b++) {
        str[i] = tmp[b];
        i++;
    }
    for (int k = 1; sup[k]; k++) {
        str[i] = sup[k];
        i++;
    }
    str[i] = NULL;
    return (str);
}

void modif_history(function_t *tmp, history_t *his)
{
    char **array = NULL;

    while (his) {
        for (int i = 1; tmp->str[0][i] == his->history[0][i - 1]
                 && his->history[0][0] != '!'; i++) {
            if (tmp->str[0][i + 1] == '\0' && his->history[0][i] == '\0')
                array = his->history;
        }
        his = his->next;
    }
    if (array != NULL) {
        array = sup_array(array, tmp->str);
        for (int h = 0; array[h]; h++) {
            my_printf("%s", array[h]);
            if (array[h + 1])
                my_printf(" ");
        }
        my_printf("\n");
        array = sup_array(array, tmp->str);
        parse_array(array, tmp);
    }
}

void check_history(function_t *tmp, history_t *his)
{
    while (tmp) {
        if (tmp->str != NULL && tmp->str[0][0] == '!') {
            modif_history(tmp, his);
            return;
        }
        tmp = tmp->next;
    }
    return;
}
