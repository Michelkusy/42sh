/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct function_s {
    char *op;
    char **str;
    struct function_s *next;
} function_t;

typedef struct history_s {
    char **history;
    struct tm date;
    struct history_s *next;
} history_t;

typedef struct general_s {
    char **local;
    char **path;
    char *pwd_last;
    char *stock;
    char **env;
    int exit;
    int ret;
    char **alias;
    struct function_s *next;
    struct history_s *next_h;
} general_t;

#endif
