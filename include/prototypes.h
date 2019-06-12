/*
** EPITECH PROJECT, 2019
** prototypes.h
** File description:
** prototypes.h
*/

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

//Void
void add_sup(general_t *, char *, int);
void purge_back(char *);
void add_env(general_t *, char **);
void find_the_path(general_t *, char **);
void parser(char **, general_t *);
void supp_env(general_t *, char *);
void analyse(general_t *);
void display_env(general_t *);
void exec_fun(function_t *, general_t *);
void echo_sup(int, char **, int, general_t *);
void add_last(general_t *, int);
void add_history(char **, general_t *);
void check_redirection(general_t *);
void check_local_var(general_t *, char *);
void disp_local(general_t *, int);
void check_local_var(general_t *, char *);
void check_history(function_t *, history_t *);
void pars_inib(function_t *);
void free_all(general_t *, char **);
void parse_array(char **, function_t *);
void my_print_special(char *);
void my_putchar(char);

//Int
int cd_sup(function_t *, general_t *);
int find_add(general_t *, char **, int);
int find_redirect(char *, char **);
int alias_fun(function_t *);
int minishell(general_t *, char **);
int env_fun(general_t *, function_t *);
int check_argument(char *);
int basic_analyse(function_t *, general_t *);
int check_next(function_t *, int);
int nb_array(char **);
int check_error_first(char *);
int check_signe(char *);
int get_case(char *);
int check_add_last(char **, char *);
int exit_fun(function_t *, general_t *);
int cd_fun(function_t *, general_t *);
int setenv_fun(general_t *, function_t *);
int unsetenv_fun(general_t *, function_t *);
int redirection_analyse(function_t *, general_t *);
int analyse_pipe(function_t *);
int message_error(int);
int which_fun(general_t *, function_t *);
int check_env(general_t *);
int my_strlen_env(char **);
int echo_fun(general_t *, function_t *);
int error_redirect(function_t *);
int check_string(char *);
int history_fun(general_t *, function_t *);
int tab_len(char **);
int set_local(general_t *, function_t *);
int exit_redirect(function_t *, general_t *, int);
int double_exit(function_t *, general_t *, int);
int double_entrance(function_t *, general_t *, int);
int entrance_redirect(function_t *, general_t *, int);
int create_file(char *);
int my_strcmp(char const *, char const *);
int find_supp(general_t *, char *);
int my_strcompare(char *, char *);
int my_printf(char *, ...);
int easy_flags_management(int, va_list);
int my_put_nbr_base(unsigned long long, char *);
int my_put_nbr(int nb);
int my_put_str(char const *);
int my_strlen_spe(char *, char);
int my_strlen_space(char *, char);
int my_strlen(char const *);
int flags_with_base_management(int, va_list);
int my_getnbr(char const *str);
int advanced_flags_management(int, va_list);
int none_signed(long);
int error_multiple_redirect(function_t *tmp);

//Char *
char *get_time(void);
char *get_next_line(int);
char *add_down_str(char *);
char *add_up_str(char *);
char *add_option(char *);
char *remove_one_char(char *);
char *get_path(char **, char *);
char *my_strcat(char *, char const *);
char *my_strcat_sp(char *, char const *);
char *my_strcpy(char *, char *);
char *my_strdup(char *);

//Char **
char **sup_env_b(char **, char **, int, int);
char **my_str_to_wordtab(char *, char);
char **my_str_to_wordarray(char *, char);

//Struct
function_t *fun_pipe(function_t *, general_t *);
function_t *advanced_analyse(function_t *, general_t *);
general_t *malloc_local(general_t *, int);
function_t *nv_tmp(function_t *, char **, char *, int);

#endif
