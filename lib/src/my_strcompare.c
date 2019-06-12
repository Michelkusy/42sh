/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** Reproduce the behavior of the strcmp function.
*/

int my_strlen(char const *);

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == (void *)0 && s2 == (void *)0)
        return (0);
    if (s1 == (void *)0)
        return (1);
    if (s2 == (void *)0)
        return (-1);
    for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return (1);
        else if (s1[i] < s2[i])
            return (-1);
    }
    return (0);
}

int my_strcompare(char const *s1, char const *s2)
{
    int s1_len = my_strlen(s1);
    int s2_len = my_strlen(s2);

    if (s1_len != s2_len) {
        return (0);
    }
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return (0);
        }
    }
    return (1);
}
