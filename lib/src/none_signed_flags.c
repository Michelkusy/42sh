/*
** EPITECH PROJECT, 2018
** unsigned.c
** File description:
** the function for the %u flag
*/

void my_putchar(char c);

int none_signed(long nb)
{
    if (nb < 0) {
        nb = nb * -1;
        nb = 4294967296 - nb;
    }
    if (nb >= 10) {
        none_signed(nb / 10);
        my_putchar(nb % 10 + 48);
    } else {
        my_putchar(nb + 48);
    }
    return (0);
}
