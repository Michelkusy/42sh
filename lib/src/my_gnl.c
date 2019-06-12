/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** The goal of this project is to write a function that returns a read line from
** a file descriptor.
** If there are no more lines to return, or if there is an error during the
** reading, the function will come back NULL.
*/

#include <stdlib.h>
#include <unistd.h>

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    while (i < n) {
        dest[i] = 0;
        i = i + 1;
    }
    return (dest);
}

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

char *my_realloc_and_copy(char *line, char *buffer, int try, int *char_readed)
{
    char *new_line = NULL;
    int line_lengh = 0;

    if (line != NULL)
        line_lengh = my_strlen(line);
    new_line = malloc(line_lengh + try + 1);
    if (new_line == NULL)
        return (NULL);
    if (line != NULL)
        my_strncpy(new_line, line, line_lengh);
    my_strncpy(new_line + line_lengh, buffer + *char_readed, try);
    new_line[line_lengh + try] = '\0';
    *char_readed += ++try;
    free(line);
    return (new_line);
}

char *get_next_line(const int fd)
{
    static char buffer[100];
    static int return_buffer = 0;
    static int char_readed = 0;
    char *line = NULL;

    for (int try = 0; 1; try++) {
        if (return_buffer <= char_readed) {
            char_readed = 0;
            try = 0;
            return_buffer = read(fd, buffer, 100);
            if (return_buffer == 0)
                return (line);
            if (return_buffer == -1)
                return (NULL);
        }
        if (buffer[char_readed + try] == '\n') {
            line = my_realloc_and_copy(line, buffer, try, &char_readed);
            return (line);
        } else if (char_readed + try == return_buffer - 1)
            line = my_realloc_and_copy(line, buffer, ++try, &char_readed);
    }
}
