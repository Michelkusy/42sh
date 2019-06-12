/*
** EPITECH PROJECT, 2019
** echo.c
** File description:
** echo
*/

#include "42sh.h"

void echo_disp(char *str)
{
    int len = my_strlen(str);

    if ((str[0] == '"' || str[0] == '\'') &&
        (str[len - 1] == '"' || str[len - 1] == '\'')) {
        str[len - 1] = '\0';
        str++;
    }
    my_printf("%s", str);
}

void echo_sup(int ret, char **str, int i, general_t *gen)
{
    if (i != 1)
        my_printf(" ");
    if (str[i][0] == '$') {
        check_local_var(gen, str[i]);
    }
    else if (my_strcompare("$?", str[i])) {
        my_printf("%d", ret);
    } else
        echo_disp(str[i]);
    return;
}

int echo_fun(general_t *general, function_t *tmp)
{
    if (my_strcompare("echo", tmp->str[0])) {
        for (int i = 1; tmp->str[i]; i++)
            echo_sup(general->ret, tmp->str, i, general);
        my_printf("\n");
        general->ret = 0;
        return (1);
    }
    return (0);
}
