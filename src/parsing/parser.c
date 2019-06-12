/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** functions used to pars the command line
*/

#include "42sh.h"

function_t *nv_tmp(function_t *tmp, char **str, char *order, int b)
{
    if (check_argument(order) == 2) {
        str[b] = add_up_str(order);
        b++;
    }
    if (check_argument(order) == 3 && (order[0] != '|' && order[0] != ';')) {
        str[b] = add_up_str(order);
        b++;
    }
    str[b] = NULL;
    tmp->str = str;
    tmp->next = malloc(sizeof(function_t));
    tmp->op = add_option(order);
    tmp = tmp->next;
    return (tmp);
}

function_t *end_parser(function_t *tmp, char **str, int b)
{
    str[b] = NULL;
    if (str[b - 1][0] == '\0')
        str[b - 1] = NULL;
    tmp->str = str;
    tmp->op = NULL;
    tmp->next = NULL;
    return (tmp);
}

void parser(char **order, general_t *general)
{
    function_t *tmp = malloc(sizeof(function_t));
    char **str = malloc(sizeof(char *) * (nb_array(order) + 1));
    int b = 0;

    general->next = tmp;
    tmp->op = NULL;
    check_error_first(order[0]);
    for (int j = 0; order[j]; j++) {
        if (check_argument(order[j]) != 0) {
            tmp = nv_tmp(tmp, str, order[j], b);
            b = 0;
            str = malloc(sizeof(char *) * nb_array(order) + 1);
            if (check_add_last(&str[0], order[j]) == 1)
                b++;
        } else {
            str[b] = order[j];
            b++;
        }
    }
    tmp = end_parser(tmp, str, b);
}

function_t *end_spe_parser(function_t *tmp, char **str, int b, function_t *end)
{
    str[b] = NULL;
    if (str[b - 1][0] == '\0')
        str[b - 1] = NULL;
    tmp->str = str;
    tmp->op = ";";
    tmp->next = end;
    return (tmp);
}

void parse_array(char **order, function_t *tmp)
{
    function_t *add = tmp->next;
    char **str = malloc(sizeof(char *) * (nb_array(order) + 1));
    int b = 0;

    tmp->op = NULL;
    check_error_first(order[0]);
    for (int j = 0; order[j]; j++) {
        if (check_argument(order[j]) != 0) {
            tmp = nv_tmp(tmp, str, order[j], b);
            b = 0;
            str = malloc(sizeof(char *) * nb_array(order) + 1);
            if (check_add_last(&str[0], order[j]) == 1)
                b++;
        } else {
            str[b] = order[j];
            b++;
        }
    }
    tmp = end_spe_parser(tmp, str, b, add);
}
