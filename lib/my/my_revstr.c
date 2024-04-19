/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** a function that reverses a string. It must be prototyped the following way
*/
#include "my.h"
int len_str(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_revstr(char *str)
{
    int len = len_str(str) - 1;
    int i = 0;
    int j = len;
    char swap;

    while (i < j) {
        swap = str[i];
        str[i] = str[j];
        str[j] = swap;
        i++;
        j--;
    }
    return str;
}
