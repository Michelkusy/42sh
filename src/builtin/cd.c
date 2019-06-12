/*
** EPITECH PROJECT, 2019
** cd
** File description:
** cd
*/

#include "42sh.h"

void modify_pwd(general_t *general)
{
    char cwd[4096];
    char *final_path = NULL;
    int u = 0;

    getcwd(cwd, sizeof(cwd));
    while (general->env[u][0] != 'P' && general->env[u][1] != 'W'
            && general->env[u][2] != 'D')
        u++;
    final_path = my_strcat("PWD=", cwd);
    general->env[u] = final_path;
}

void add_sup(general_t *general, char *str, int first)
{
    if (first == 1) {
        my_printf(": No such file or directory.\n");
        general->ret = 1;
        return;
    }
    str = general->stock;
    general->stock = general->pwd_last;
    general->pwd_last = str;
    general->ret = 0;
}

void add_last(general_t *general, int op)
{
    char cwd[4096];
    char *str = NULL;
    static int first = 0;

    if (op == 0 || op == 2) {
        getcwd(cwd, sizeof(cwd));
        if ((str = malloc(sizeof(char) * my_strlen(cwd))) == NULL)
            exit(84);
        for (int h = 0; cwd[h] != '\0'; h++)
            str[h] = cwd[h];
        if (op == 0)
            general->pwd_last = str;
        if (first == 0 || op == 2)
            general->stock = str;
        first++;
    } else if (op == 1)
        add_sup(general, str, first);
}

int cd_sup(function_t *tmp, general_t *general)
{
    struct stat sb;

    if (my_strcompare("-", tmp->str[1])) {
        add_last(general, 2);
        chdir(general->pwd_last);
        add_last(general, 1);
        modify_pwd(general);
        return (general->ret = 0);
    }
    if (stat(tmp->str[1], &sb) == -1) {
        my_printf("%s: No such file or directory.\n", tmp->str[1]);
        return (general->ret = 1);
    }
    add_last(general, 0);
    if (tmp->str[2] == NULL && chdir(tmp->str[1]) == -1)
        my_printf("%s: Not a directory.\n", tmp->str[1]);
    modify_pwd(general);
    return (general->ret = 0);
}

int cd_fun(function_t *tmp, general_t *general)
{
    if (my_strcompare("cd", tmp->str[0])) {
        if (check_env(general) == 1) {
            my_printf("invalid env\n");
            return (general->ret = 1);
        }
        if (tmp->str[1] == NULL) {
            add_last(general, 0);
            chdir("/home");
            modify_pwd(general);
        } else if (tmp->str[2] != NULL) {
            my_printf("cd: Too many arguments.\n");
            return (general->ret = 1);
        } else
            cd_sup(tmp, general);
        return (1);
    }
    return (0);
}
