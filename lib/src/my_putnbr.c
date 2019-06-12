/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Write a function that displays the number given as a parameter.
** It must be able to display all the possible values of
** an int.
*/

void my_putchar(char);

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_putnbr(-nb);
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    } else
        my_putchar(nb + '0');
}
