/*
** EPITECH PROJECT, 2023
** my_int_to_str
** File description:
** int to str
*/
#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static int count(int nb)
{
    int len = 0;
    int nb2 = nb;

    while (nb2) {
        nb2 /= 10;
        len++;
    }
    return len;
}

static void fix_string(char *str, int i)
{
    str[i] = '\0';
    my_revstr(str);
    str[i] = ' ';
    str[i + 1] = '\0';
}

char *my_int_to_str(int nb)
{
    char *str = NULL;
    int len = 0;
    int nb2 = nb;
    int i = 0;

    if (nb != 0) {
        len = count(nb);
        str = malloc(sizeof(char) * len + 2);
        while (nb) {
            str[i] = (nb % 10) + '0';
            nb /= 10;
            i++;
        }
        fix_string(str, i);
    } else {
        str = malloc(sizeof(char) * 3);
        str = "0 ";
    }
    return str;
}
