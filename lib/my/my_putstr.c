/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** function that displays, one-by-one, the characters of a string. The address
** of the string's first character will be found in the pointer passed as a
** parameter to the function.
*/
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    my_putchar('\n');
    return 0;
}

int my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_error(str[i]);
        i++;
    }
    my_putchar('\n');
    return 0;
}

int my_putstr_n(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
        count++;
    }
    return count;
}
