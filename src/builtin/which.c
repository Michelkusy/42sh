/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Which command
*/

#include "42sh.h"

char *get_path(char **path, char *binary)
{
    struct stat s;
    char *filepath = NULL;
    char *final_filepath = NULL;
    int my_stat = 0;

    if (path == NULL)
        return (NULL);
    for (int i = 0; path[i]; i++) {
        filepath = my_strcat(path[i], "/");
        final_filepath = my_strcat(filepath, binary);
        my_stat = stat(final_filepath, &s);
        if (my_stat != -1)
            return (final_filepath);
    }
    return (NULL);
}

int which_fun(general_t *general, function_t *tmp)
{
    char *element = NULL;

    if (my_strcompare("which", tmp->str[0])) {
        if (tmp->str[1] == NULL) {
            my_printf("which: Too few arguments\n");
            return (1);
        }
        for (int i = 1; tmp->str[i] != NULL; i++) {
            element = get_path(general->path, tmp->str[i]);
            if (element == NULL)
                my_printf("%s: Command not found\n", tmp->str[i]);
            else
                my_printf("%s\n", element);
            free(element);
        }
        return (1);
    }
    return (0);
}
