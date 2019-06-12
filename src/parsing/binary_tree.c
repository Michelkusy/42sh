/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "42sh.h"

char *add_up_str(char *order)
{
    int k = 0;
    char *str;

    while (order[k] != ';' && order[k] != '|' && order[k] != '&')
        k++;
    str = malloc(sizeof(char) * k);
    for (int b = 0; order[b] != ';' && order[b] != '|' && order[b] != '&'; b++)
        str[b] = order[b];
    str[k] = '\0';
    if (order[0] == ';' || order[0] == '|' || order[0] == '&')
        return (NULL);
    return (str);
}

char *add_option(char *order)
{
    char *str = malloc(sizeof(char) * 3);

    for (int b = 0; order[b]; b++) {
        if ((order[b] == '|' || order[b] == ';') && order[b + 1] != '|') {
            str[0] = order[b];
            str[1] = '\0';
        } else if ((order[b] == '|' && order[b + 1] == '|') ||
                    (order[b] == '&' && order[b + 1] == '&')) {
            str[0] = order[b];
            str[1] = order[b + 1];
            str[2] = '\0';
            break;
        }
    }
    return (str);
}

int get_pipes_pos(char *order)
{
    int b = 0;

    while (1) {
        if ((order[b] == '|' || order[b] == ';') && order[b + 1] != '|') {
            break;
        } else if ((order[b] == '&' && order[b + 1] == '&') ||
                    (order[b] == '|' && order[b + 1] == '|')) {
            b++;
            break;
        }
        b++;
    }
    b++;
    return (b);
}

char *add_down_str(char *order)
{
    char *str;
    int len = 0;
    int k = get_pipes_pos(order);
    int b = k;

    for (;order[b]; b++)
        len++;
    str = malloc(sizeof(char) * len);
    for (int o = 0; order[k]; o++) {
        str[o] = order[k];
        k++;
    }
    str[len] = '\0';
    return (str);
}
