/*
** EPITECH PROJECT, 2019
** test_unitary
** File description:
** test
*/

#include <unistd.h>
#include <signal.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "42sh.h"

extern char **environ;

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_redirect_stdin();
}

Test(my_strcmp, compare_two_str, .init = redirect_all_std)
{
    char *str_a = "dom";
    char *str_b = "ls";
    int dest = my_strcmp(str_a, str_b);

    cr_assert_eq(dest, -1);
}

Test(my_str_to_wordtab, test_str_to_wordtab, .init = redirect_all_std)
{
    char *str = "dom ls";
    char c = ' ';
    char **dest = my_str_to_wordtab(str, c);

    cr_assert_str_eq(dest[0], "dom");
}

Test(my_strcmp, compare_two_str_b, .init = redirect_all_std)
{
    char *str_a = "dom";
    char *str_b = "dom";
    int dest = my_strcmp(str_a, str_b);

    cr_assert_eq(dest, 0);
}

Test(my_strcmp, compare_two_str_c, .init = redirect_all_std)
{
    char *str_a = "dom";
    char *str_b = "wor";
    int dest = my_strcmp(str_a, str_b);

    cr_assert_eq(dest, -1);
}

Test(my_strcat, test_function_strcat, .init = redirect_all_std)
{
    char *str = "dom";
    char *src = "hi";
    char *dest = my_strcat(str, src);

    cr_assert_str_eq(dest, "domhi");
}

Test(my_strcmp, compare_two_str_d, .init = redirect_all_std)
{
    char *str_a = "wor";
    char *str_b = "dom";
    int dest = my_strcmp(str_a, str_b);

    cr_assert_eq(dest, 1);
}

Test(env_fun, bad_env_use, .init = redirect_all_std)
{
    int dest;
    general_t *general = malloc(sizeof(general_t));
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 2);
    function->str[0] = "env";
    function->str[1] = "test";
    general->ret = 0;
    dest = env_fun(general, function);
    cr_assert_eq(dest, 1);
}

Test(echo_sup, inib_arg, .init = redirect_all_std)
{
    int ret = 0;
    char *str[] = { "test", NULL };
    general_t *general = malloc(sizeof(general_t));
    int i = 0;

    find_the_path(general, environ);
    echo_sup(ret, str, i, general);
    cr_assert_stdout_eq_str(" test");
}

Test(echo_sup, return_echo, .init = redirect_all_std)
{
    int ret = 13;
    char *str[] = { "test", "$?", NULL };
    int i = 1;
    general_t *general = malloc(sizeof(general_t));

    find_the_path(general, environ);
    echo_sup(ret, str, i, general);
    cr_assert_stdout_eq_str("13");
}

Test(message_error, seg, .init = redirect_all_std)
{
    int sig = 139;

    message_error(sig);
    cr_assert_stdout_eq_str("Segmentation fault (core dumped)\n");
}

Test(message_error, floating_point, .init = redirect_all_std)
{
    int sig = 136;

    message_error(sig);
    cr_assert_stdout_eq_str("Floating exception (core dumped)\n");
}

Test(message_error, Aborted, .init = redirect_all_std)
{
    int sig = 134;

    message_error(sig);
    cr_assert_stdout_eq_str("Aborted (core dumped)\n");
}

Test(env_fun, several_exit, .init = redirect_all_std)
{
    int dest;
    general_t *general = malloc(sizeof(general_t));
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 2);
    function->str[0] = "exit";
    function->str[1] = NULL;
    function->next = malloc(sizeof(function_t));
    general->ret = 0;
    dest = exit_fun(function, general);
    cr_assert_eq(dest, 1);
}

Test(history_fun, bad_usage, .init = redirect_all_std)
{
    int dest;
    general_t *general = malloc(sizeof(general_t));
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 2);
    function->str[0] = "history";
    function->str[1] = "test";
    general->ret = 0;
    history_fun(general, function);
    dest = general->ret;
    cr_assert_eq(dest, 1);
}


Test(alias_fun, no_args, .init = redirect_all_std)
{
    function_t *function = malloc(sizeof(function_t));
    general_t *general = malloc(sizeof(general_t));
    int dest = 0;

    find_the_path(general, environ);
    function->str = malloc(sizeof(char *) * 3);
    function->str[0] = strdup("alias");
    function->str[1] = NULL;
    function->str[2] = NULL;
    dest = alias_fun(function);
    cr_assert_eq(dest, 1);
}

Test(add_sup, no_dir, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    char *str = "salut";
    int first = 1;

    find_the_path(general, environ);
    add_sup(general, str, first);
    cr_assert_stdout_eq_str(": No such file or directory.\n");
}

Test(cd_sup, no_dir, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    char *str = "salut";
    int first = 1;
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 3);
    function->str[0] = strdup("alias");
    function->str[1] = strdup("zigoui");
    function->str[2] = NULL;
    find_the_path(general, environ);
    cd_sup(function, general);
    cr_assert_stdout_eq_str("zigoui: No such file or directory.\n");
}

Test(cd_fun, no_dir, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    char *str = "salut";
    int first = 1;
    char *env[] = { "bad env", "test", NULL };
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 3);
    function->str[0] = strdup("cd");
    function->str[1] = strdup("test");
    function->str[2] = NULL;
    find_the_path(general, env);
    cd_fun(function, general);
    cr_assert_stdout_eq_str("invalid env\n");
}

Test(cd_fun, cd_tomuch_arg, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    char *str = "salut";
    int first = 1;
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 3);
    function->str[0] = strdup("cd");
    function->str[1] = strdup("test");
    function->str[2] = strdup("to much");
    function->str[3] = NULL;
    find_the_path(general, environ);
    cd_fun(function, general);
    cr_assert_stdout_eq_str("cd: Too many arguments.\n");
}

Test(check_string, void_s)
{
    char *str = NULL;
    int dest = check_string(str);

    printf("%d\n", dest);
    cr_assert_eq(dest, 2);
}

Test(check_string, slash)
{
    char *str = "tkt/";
    int dest = check_string(str);

    cr_assert_eq(dest, 1);
}

Test(check_string, block)
{
    char *str = "[test]";
    int dest = check_string(str);

    cr_assert_eq(dest, 1);
}

Test(check_string, spe_a)
{
    char *str = "@maz";
    int dest = check_string(str);

    cr_assert_eq(dest, 1);
}

Test(find_add, add_to_env)
{
    general_t *general = malloc(sizeof(general_t));
    int a = 28;
    int dest = 0;
    char *command[] = { "test", "HOME", "test" };

    find_the_path(general, environ);
    dest = find_add(general, command, a);
    cr_assert_eq(dest, 1);
}

Test(add_env, add_to_env, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    int a = 28;
    char *test = "setenv: Variable name must contain " \
        "alphanumeric characters.\n";
    char *command[] = { "test", "HOM@E", "test" };

    find_the_path(general, environ);
    add_env(general, command);
    cr_assert_stdout_eq_str(test);
}

Test(add_env, normal_use, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    char *command[] = { "test", "HOME", "test" };

    find_the_path(general, environ);
    add_env(general, command);
}

Test(set_env_fun, to_many_arg, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    char *command[] = { "test", "HOME", "test" };
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 4);
    function->str[0] = strdup("setenv");
    function->str[1] = strdup("test");
    function->str[2] = strdup("to much");
    function->str[3] = strdup("to much");
    function->str[4] = NULL;
    find_the_path(general, environ);
    setenv_fun(general, function);
    cr_assert_stdout_eq_str("setenv: Too many arguments.\n");
}

Test(find_supp, True_unset, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    int dest = 0;

    find_the_path(general, environ);
    dest = find_supp(general, "PATH");
    cr_assert_eq(dest, 14);
}

Test(supp_env, True_unset, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    int dest = 0;

    find_the_path(general, environ);
    supp_env(general, "OLDPWD");
}

Test(get_path, src, .init = redirect_all_std)
{
    char *binary = "src";
    char *dest;
    char *path[] = { "/usr", "bin", "home", NULL};

    dest = get_path(path, binary);
    cr_assert_str_eq(dest, "/usr/src");
}

Test(get_path, no_path, .init = redirect_all_std)
{
    char *binary = "src";
    char *dest;
    char *path[] = { "usr", "bin", "home", NULL};

    dest = get_path(path, binary);
    cr_assert_null(dest);
}

Test(which_fun, to_few, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    char *command[] = { "test", "HOME", "test" };
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 2);
    function->str[0] = my_strdup("which");
    function->str[2] = NULL;
    find_the_path(general, environ);
    which_fun(general, function);
    cr_assert_stdout_eq_str("which: Too few arguments\n");
}

Test(which_fun, good_use, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 3);
    function->str[0] = my_strdup("which");
    function->str[1] = "src";
    function->str[2] = NULL;
    find_the_path(general, environ);
    general->path = malloc(sizeof(char *) * 2);
    general->path[0] = "usr";
    general->path[1] = NULL;
    which_fun(general, function);
    cr_assert_stdout_eq_str("src: Command not found\n");
}

Test(which_fun, bad_use, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 3);
    function->str[0] = my_strdup("which");
    function->str[1] = "src";
    function->str[2] = NULL;
    find_the_path(general, environ);
    general->path = malloc(sizeof(char *) * 2);
    general->path[0] = "/usr";
    general->path[1] = NULL;
    which_fun(general, function);
    cr_assert_stdout_eq_str("/usr/src\n");
}

Test(basic_analyse, set_local, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    int dest = 0;
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 4);
    function->str[0] = strdup("set");
    function->str[1] = strdup("maz");
    function->str[2] = strdup("to much");
    function->str[3] = NULL;
    find_the_path(general, environ);
    dest = basic_analyse(function, general);
    cr_assert_eq(dest, 1);
}

Test(basic_analyse, alias, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    int dest = 0;
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 4);
    function->str[0] = strdup("alias");
    function->str[1] = NULL;
    function->str[2] = NULL;
    find_the_path(general, environ);
    dest = basic_analyse(function, general);
    cr_assert_eq(dest, 1);
}

Test(basic_analyse, which, .init = redirect_all_std)
{
    general_t *general = malloc(sizeof(general_t));
    int dest = 0;
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 4);
    function->str[0] = strdup("which");
    function->str[1] = strdup("maz");
    function->str[2] = strdup("to much");
    function->str[3] = NULL;
    find_the_path(general, environ);
    dest = basic_analyse(function, general);
    cr_assert_eq(dest, 1);
}

Test(check_next, null, .init = redirect_all_std)
{
    int dest = 0;
    int ret = 0;
    function_t *function = NULL;

    dest = check_next(function, ret);
    cr_assert_eq(dest, 1);
}

Test(check_next, and, .init = redirect_all_std)
{
    int dest = 0;
    function_t *function = malloc(sizeof(function_t));
    int ret = 1;

    function->op = "&&";
    dest = check_next(function, ret);
    cr_assert_eq(dest, 1);
}

Test(check_next, or, .init = redirect_all_std)
{
    int dest = 0;
    function_t *function = malloc(sizeof(function_t));
    int ret = 0;

    function->op = "||";
    dest = check_next(function, ret);
    cr_assert_eq(dest, 1);
}

Test(pars_inib, purge, .init = redirect_all_std)
{
    function_t *function = malloc(sizeof(function_t));

    function->str = malloc(sizeof(char *) * 2);
    function->str[0] = my_strdup("te\\sts");
    function->str[1] = NULL;
    pars_inib(function);
    cr_assert_str_eq(function->str[0], "tets");
}

Test(add_up_str, seperator, .init = redirect_all_std)
{
    char *order = "salut; test | cd;cd-";
    char *dest = add_up_str(order);

    cr_assert_str_eq(dest, "salut");
}

Test(add_up_str, null, .init = redirect_all_std)
{
    char *order = ";salut; test | cd;cd-";
    char *dest = add_up_str(order);

    cr_assert_null(dest);
}

Test(add_down_str, test, .init = redirect_all_std)
{
    char *order = "salut; test && cd;cd-";
    char *dest = add_down_str(order);

    cr_assert_str_eq(dest, " test && cd;cd-");
}

Test(nv_tmp, basic, .init = redirect_all_std)
{
    function_t *function = malloc(sizeof(function_t));
    char *str[] = { "test", "cd", "ls" };
    char *order = "|salut; test && cd;cd-";
    int b = 3;
    function_t *dest = NULL;

    function->op = "||";
    dest = nv_tmp(function, str, order, b);
    cr_assert_not_null(dest);
}

Test(check_signe, pipe)
{
    int dest = 0;
    char *str = "||";

    dest = check_signe(str);
    cr_assert_eq(dest, 1);
}

Test(check_signe, and)
{
    int dest = 0;
    char *str = "&&";

    dest = check_signe(str);
    cr_assert_eq(dest, 1);
}

Test(get_case, simple)
{
    int dest = 0;
    char *str = "test |";

    dest = get_case(str);
    cr_assert_eq(dest, 2);
}

Test(get_case, seperator)
{
    int dest = 0;
    char *str = "test ;";

    dest = get_case(str);
    cr_assert_eq(dest, 2);
}

Test(get_case, hard_seperator)
{
    int dest = 0;
    char *str = "test ; ls";

    dest = get_case(str);
    cr_assert_eq(dest, 3);
}

Test(get_case, simple_double_pipe)
{
    int dest = 0;
    char *str = "test ||";

    dest = get_case(str);
    cr_assert_eq(dest, 2);
}

Test(get_case, double_pipe)
{
    int dest = 0;
    char *str = "test || ls";

    dest = get_case(str);
    cr_assert_eq(dest, 3);
}

Test(get_case, and)
{
    int dest = 0;
    char *str = "test &&";

    dest = get_case(str);
    cr_assert_eq(dest, 2);
}

Test(get_case, and_hard)
{
    int dest = 0;
    char *str = "test && ls";

    dest = get_case(str);
    cr_assert_eq(dest, 3);
}

Test(error_redirect, invalid_null, .init = redirect_all_std)
{
    function_t *function = malloc(sizeof(function_t));
    int dest = 0;

    function->str = malloc(sizeof(char *) * 2);
    function->str[0] = my_strdup(">>");
    function->str[1] = NULL;
    dest = error_redirect(function);
    cr_assert_stdout_eq_str("Invalid null command.\n");
}

Test(error_redirect, missing_name, .init = redirect_all_std)
{
    function_t *function = malloc(sizeof(function_t));
    int dest = 0;

    function->str = malloc(sizeof(char *) * 4);
    function->str[0] = my_strdup("cd");
    function->str[1] = my_strdup(">");
    function->str[2] = NULL;
    function->str[3] = NULL;
    dest = error_redirect(function);
    cr_assert_stdout_eq_str("Missing name for redirect.\n");
}

Test(check_add_last, truee)
{
    int dest = 0;
    char *str[] = { "salut", "les", "amis" };
    char *order = "test && ls";

    dest = check_add_last(str, order);
    cr_assert_eq(dest, 1);
}
