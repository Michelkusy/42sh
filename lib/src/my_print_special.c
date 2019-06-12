/*
** EPITECH PROJECT, 2018
** my_printf_Special.c
** File description:
** the %S flag on my_printf
*/

int my_strlen(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);

int my_put_nbr_base_special(int nb, char *base_str)
{
    int len_base = my_strlen(base_str);
    if (nb == 0)
        return (0);
    else
        my_put_nbr_base_special(nb / len_base, base_str);
    my_putchar(base_str[nb % len_base]);
    return (0);
}

void none_printable_char(char c)
{
    my_putchar('\\');
    if (c <= 7){
        my_putstr("00");
        my_put_nbr_base_special(c, "01234567");
    } else if (c <= 63) {
        my_putchar('0');
        my_put_nbr_base_special(c, "01234567");
    } else
        my_put_nbr_base_special(c, "01234567");
}

void my_print_special(char *str)
{
    for (int i = 0;str[i] != '\0'; i++){
        if (str[i] >= 32 && str[i] < 127)
            my_putchar(str[i]);
        else
            none_printable_char(str[i]);
    }
}
