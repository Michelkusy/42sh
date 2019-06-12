/*
** EPITECH PROJECT, 2019
** entrance_redirect
** File description:
** entrance_redirect
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "42sh.h"

int fork_entrance(function_t *tmp, general_t *general, int i, int fd)
{
    int pid;

    tmp->str[i] = NULL;
    tmp->str[i + 1] = NULL;
    pid = fork();
    if (pid == 0) {
        dup2(fd, 1);
        general->exit = 2;
        return (0);
    }
    else {
        wait(&pid);
        return (1);
    }
}

int entrance_redirect(function_t *tmp, general_t *general, int i)
{
    FILE *fp;
    DIR *dir;
    int fd;

    if ((dir = opendir(tmp->str[i + 1])) != NULL) {
        my_printf("%s: Is a directory.\n", tmp->str[i + 1]);
        closedir(dir);
        return (1);
    }
    if ((fp = fopen(tmp->str[i + 1], "w+")) == NULL)
        exit(84);
    fd = open(tmp->str[i + 1], O_WRONLY);

    return (fork_entrance(tmp, general, i, fd));
}

int double_entrance(function_t *tmp, general_t *general, int i)
{
    FILE *fp;
    DIR *dir;
    int fd;

    if ((dir = opendir(tmp->str[i + 1])) != NULL) {
        my_printf("%s: Is a directory.\n", tmp->str[i + 1]);
        closedir(dir);
        return (1);
    }
    if ((fp = fopen(tmp->str[i + 1], "a+")) == NULL)
        exit(84);
    fd = open(tmp->str[i + 1], O_WRONLY | O_APPEND);

    return (fork_entrance(tmp, general, i, fd));
}
