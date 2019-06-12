/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** get_time for the prompt
*/

#include <time.h>
#include "42sh.h"

char *get_time(void)
{
    time_t my_time = time(NULL);
    char *cur_time = ctime(&my_time);

    cur_time[my_strlen(cur_time) - 9] = '\0';
    cur_time += 11;
    return (cur_time);
}
