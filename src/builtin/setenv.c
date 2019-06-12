/*
** EPITECH PROJECT, 2019
** setenv
** File description:
** setenv
*/

#include "42sh.h"

int check_string(char *str)
{
    if (str == NULL)
        return (2);
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > 'z')
            return (1);
        if (str[i] > 'Z' && str[i] < 'a')
            return (1);
        if (str[i] > '9' && str[i] < 'A')
            return (1);
    }
    return (0);
}

int find_add(general_t *general, char **command, int i)
{
    char **tab = NULL;

    tab = my_str_to_wordtab(general->env[i], '=');
    if (my_strcompare(tab[0], command[1])) {
        general->env[i] = my_strcat(command[1], "=");
        if (command[2] != NULL)
            general->env[i] = my_strcat(general->env[i], command[2]);
        return (1);
    }
    return (0);
}

char **new_env(general_t *general, char **command)
{
    char **tmp = NULL;
    int i = 0;

    for (i = 0; general->env[i]; i++);
    tmp = malloc(sizeof(char *) * (i + 2));
    for (i = 0; general->env[i]; i++) {
        tmp[i] = malloc(sizeof(char *) * (my_strlen(general->env[i]) + 2));
        tmp[i] = my_strcpy(general->env[i], tmp[i]);
    }
    tmp[i] = my_strcat(command[1], "=");
    if (command[2] != NULL)
        tmp[i] = my_strcat(tmp[i], command[2]);
    tmp[i + 1] = NULL;
    return (tmp);
}

void add_env(general_t *general, char **command)
{
    int i = 0;

    if (check_string(command[1])) {
        my_printf("setenv: Variable name must contain");
        my_printf(" alphanumeric characters.\n");
        return;
    }
    for (i = 0; general->env[i]; i++)
        if (find_add(general, command, i))
            return;
    general->env = new_env(general, command);
}

int setenv_fun(general_t *general, function_t *tmp)
{
    if (my_strcompare("setenv", tmp->str[0])) {
        if (tmp->str[1] == NULL)
            display_env(general);
        else if (tmp->str[2] == NULL || tmp->str[3] == NULL)
            add_env(general, tmp->str);
        else
            my_printf("setenv: Too many arguments.\n");
        return (1);
    }
    return (0);
}
