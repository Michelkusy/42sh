/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** local
*/

#include "42sh.h"

static int len = 0;

void disp_local(general_t *gen, int len)
{
    for (int i = 0 ; i != len; i++)
        my_printf("%s\n", gen->local[i]);
}

void check_local_var(general_t *gen, char *str)
{
    char *string = remove_one_char(str);
    char **tab = NULL;

    for (int i = 0 ; i != len ; i++) {
        tab = my_str_to_wordtab(gen->local[i], '=');
        if (my_strcompare(tab[0], string)) {
            if (tab_len(tab) == 2)
                my_printf("%s", tab[1]);
        }
        if (i == len && !my_strcompare(tab[0], string))
            my_printf("%s: Undefined variable.");
    }
}

general_t *malloc_local(general_t *gen, int len)
{
    gen->local = malloc(1000);
    for (int j = 0 ; j != len ; j++)
        gen->local[j] = malloc(100);
    return (gen);
}

int set_local(general_t *gen, function_t *tmp)
{
    if (my_strcompare("set", tmp->str[0])) {
        if (gen->local == NULL) {
            gen = malloc_local(gen, len);
        }
        if (tab_len(tmp->str) == 1) {
            disp_local(gen, len);
            return (1);
        }
        gen->local[len] = tmp->str[1];
        len++;
        return (1);
    }
    return (0);
}
