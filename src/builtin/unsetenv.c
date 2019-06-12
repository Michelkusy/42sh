/*
** EPITECH PROJECT, 2019
** unsetenv
** File description:
** unsetenv
*/

#include "42sh.h"

int find_supp(general_t *general, char *str)
{
    int i = 0;
    char **tab = NULL;

    for (i = 0; general->env[i]; i++) {
        tab = my_str_to_wordtab(general->env[i], '=');
        if (my_strcompare(tab[0], str))
            return (i);
    }
    return (-1);
}

void supp_env(general_t *general, char *str)
{
    int nb = 0;
    int i = 0;
    int j = 0;
    char **tmp = NULL;

    if ((nb = find_supp(general, str)) == -1)
        return;
    for (i = 0; general->env[i]; i++);
    tmp = malloc(sizeof(char *) * (i + 2));
    for (i = 0; general->env[i]; i++, j++) {
        if (i == nb)
            i++;
        if (general->env[i] == NULL)
            break;
        tmp[j] = malloc(sizeof(char *) * my_strlen(general->env[i]));
        tmp[j] = my_strcpy(general->env[i], tmp[j]);
    }
    tmp[j] = NULL;
    general->env = tmp;
}

void loop_unsetenv(general_t *general, char **command)
{
    for (int i = 0; command[i]; i++)
        supp_env(general, command[i]);
}

int unsetenv_fun(general_t *general, function_t *tmp)
{
    if (my_strcompare("unsetenv", tmp->str[0])) {
        if (tmp->str[1] == NULL)
            my_printf("unsetenv: Too few arguments.\n");
        else
            loop_unsetenv(general, tmp->str);
        return (1);
    }
    return (0);
}
