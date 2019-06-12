/*
** EPITECH PROJECT, 2019
** exit_redirection
** File description:
** exit_redirection
*/

#define _POSIX_SOURCE
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "42sh.h"

int fork_exit(function_t *tmp, general_t *general, int i, int fd)
{
    int pid;

    tmp->str[i] = NULL;
    tmp->str[i + 1] = NULL;
    pid = fork();
    if (pid == 0) {
        dup2(fd, 0);
        general->exit = 2;
        return (0);
    }
    else {
        wait(&pid);
        return (1);
    }
}

int double_exit(function_t *tmp, general_t *general, int i)
{
    char *str;
    int fd;
    FILE *fp = tmpfile();

    my_printf("? ");
    while ((str = get_next_line(0)) != NULL) {
        if (my_strcompare(str, tmp->str[i + 1]))
            break;
        my_printf("? ");
        fprintf(fp, "%s\n", str);
    }
    rewind(fp);
    fd = fileno(fp);
    return (fork_exit(tmp, general, i, fd));
}

int exit_redirect(function_t *tmp, general_t *general, int i)
{
    int fd;

    if ((fd = open(tmp->str[i + 1], O_RDONLY)) == -1) {
        my_printf("%s: No such file or directory\n");
        return (1);
    }
    return (fork_exit(tmp, general, i, fd));
}
