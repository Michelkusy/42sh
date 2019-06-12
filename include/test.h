/*
** EPITECH PROJECT, 2019
** prototypes.h
** File description:
** prototypes.h
*/

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

//minishell.c
int minishell(general_t *general, char **env);
int my_strlen_env(char **env);

//get_next_line.c
char *get_next_line(void);

char **sup_env_b(char **, char **, int, int);

//parser.c
void parser(char **order, general_t *general);

//analyse.c
void analyse(general_t *general);

//display_env.c
int env_fun(general_t *general, function_t *tmp);

//check_tools.c
int check_argument(char *);
int nb_array(char **);
int check_error_first(char *);
int check_add_last(char **, char *);

//binary_tree.c
char *add_down_str(char *);
char *add_up_str(char *);
char *add_option(char *);

//exit.c
int exit_fun(function_t *tmp, general_t *general);

//cd.c
int cd_fun(function_t *tmp, general_t *general);
void add_last(general_t *general, int op);

//setenv.c
int setenv_fun(general_t *general, function_t *tmp);
int check_string(char *str);

//unsetenv.c
int unsetenv_fun(general_t *general, function_t *tmp);

//redirection.c
int redirection_analyse(function_t *tmp, general_t *general);
int error_redirect(function_t *tmp, general_t *general);

//display_env.c
void display_env(general_t *general);

//error_exec.c
int analyse_pipe(function_t *tmp);
int message_error(int sig);
int check_env(general_t *general);

//exec.c
void exec_fun(function_t *tmp, general_t *general);

//pipe.c
int fun_pipe(function_t *tmp_left, function_t *tmp_right, general_t *general);

//echo.c
int echo_fun(general_t *general, function_t *tmp);
void echo_sup(int, char **, int, general_t *gen);

//history.c
int history_fun(general_t *general, function_t *tmp);
void add_history(char **str, general_t *general);
void check_redirection(general_t *general);

//utils.c
int tab_len(char **tab);
char *remove_one_char(char *str);

//local.c
void disp_local(general_t *gen, int len);
void check_local_var(general_t *gen, char *str);
general_t *malloc_local(general_t *gen, int len);
int set_local(general_t *gen, function_t *tmp);
void check_local_var(general_t *gen, char *str);


#endif
