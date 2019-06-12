/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** minishell
*/

#include "42sh.h"

void find_the_path(general_t *general, char **env)
{
    general->env = env;
    general->local = NULL;
    general->exit = 0;
    general->ret = 0;
    general->next_h = NULL;
    general->path = my_str_to_wordtab(getenv("PATH"), ':');
}

char *change_str(char *str)
{
    char *new = malloc(sizeof(char *) * (my_strlen(str) * 2));
    int i;
    int j = 0;

    for (i = 0; str[i]; i++, j++) {
        if ((str[i] == '>' && str[i + 1] == '>') ||
            (str[i] == '<' && str[i + 1] == '<')) {
            new[j++] = ' ';
            new[j++] = str[i++];
            new[j++] = str[i];
            new[j] = ' ';
        } else if (str[i] == '>' || str[i] == '<') {
            new[j++] = ' ';
            new[j++] = str[i];
            new[j] = ' ';
        } else
            new[j] = str[i];
    }
    new[j] = '\0';
    return (new);
}

void loop_minishel(general_t *general, char *str)
{
    char *new = NULL;
    char **order = NULL;

    new = change_str(str);
    order = my_str_to_wordtab(new, ' ');
    free(new);
    add_history(order, general);
    parser(order, general);
    check_history(general->next, general->next_h);
    analyse(general);
}

int minishell(general_t *general, char **env)
{
    char *str = NULL;

    my_printf((char *) PROMPT_TEXT, get_time());
    find_the_path(general, env);
    add_last(general, 0);
    while ((str = get_next_line(0)) != NULL) {
        if (str[0] != '\0')
            loop_minishel(general, str);
        free(str);
        if (general->exit) {
            free_all(general, env);
            break;
        }
        my_printf((char *) PROMPT_TEXT, get_time());
    }
    return (EXIT_OK);
}
