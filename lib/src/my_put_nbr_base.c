/*
** EPITECH PROJECT, 2018
** my_putnbr_base.c
** File description:
** printf a number with a base wich is gived as str
*/

int my_strlen(char const *str);
void my_putchar(char c);

int my_put_nbr_base(unsigned long long nb, char *base_str)
{
    unsigned long long len_base = my_strlen(base_str);

    if (nb == 0)
        return (0);
    else
        my_put_nbr_base(nb / len_base, base_str);
    my_putchar(base_str[nb % len_base]);
    return (0);
}
