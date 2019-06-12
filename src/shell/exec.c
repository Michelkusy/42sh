/*
** EPITECH PROJECT, 2019
** exec
** File description:
** exech
*/

#include "42sh.h"
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>

char *test_every_path(char **path, char **binary)
{
    struct stat s;
    char *filepath = NULL;
    char *final_filepath = NULL;
    int my_stat = 0;

    my_stat = stat(binary[0], &s);
    if (my_stat != ERROR_LIBC && s.st_mode & S_IXUSR)
        return (binary[0]);
    if (path == NULL)
        return (NULL);
    for (int i = 0; path[i]; i++) {
        filepath = my_strcat(path[i], "/");
        final_filepath = my_strcat(filepath, binary[0]);
        my_stat = stat(final_filepath, &s);
        if (my_stat != ERROR_LIBC)
            return (final_filepath);
    }
    return (NULL);
}

bool check_current_cwd(char *cwd, char *binary)
{
    struct stat s;
    int my_stat = 0;
    char *final = NULL;

    final = my_strcat_sp(cwd, binary);
    my_stat = stat(final, &s);
    if (my_stat != ERROR_LIBC)
        return (true);
    return (false);
}

void test_elf_binary_and_execute(char *str, char *old_cmd, char **tmp, char 
**env)
{
    if (execve(str, tmp, env) == ERROR_LIBC)
        if (errno == ENOEXEC)
            my_printf((char *) WRONG_ENV, old_cmd);
}

void test_binary_and_execute(char *str, char *old_cmd, char **tmp, char **env)
{
    struct stat s;

    stat(str, &s);
    if (S_ISREG(s.st_mode))
        test_elf_binary_and_execute(str, old_cmd, tmp, env);
    else
        my_printf((char *) PERMISSION_DENIED, old_cmd);
}

void exec_fun(function_t *tmp, general_t *general)
{
    char *element = NULL;
    char cwd[4096] = {0};
    pid_t pro = fork();
    char *str = NULL;
    char *old_command = NULL;
    int status = 0;

    if (pro == 0) {
        if (check_current_cwd(getcwd(cwd, sizeof(cwd)), tmp->str[0]) &&
        tmp->str[0][0] == '.' && tmp->str[0][1] == '/') {
            old_command = my_strdup(tmp->str[0]);
            str = my_strcat_sp(getcwd(cwd, sizeof(cwd)), tmp->str[0]);
            test_binary_and_execute(str, old_command, tmp->str, general->env);
        } else if ((element = test_every_path(general->path, tmp->str)) != NULL)
            test_binary_and_execute(element, element, tmp->str, general->env);
        else if (general->exit != 2)
            my_printf("%s: Command not found.\n", tmp->str[0]);
        exit(EXIT_CMD_NOT_FOUND);
    }
    wait(&status);
    general->ret = message_error(status);
}