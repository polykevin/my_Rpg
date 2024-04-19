/*
** EPITECH PROJECT, 2023
** my_str_add.c
** File description:
** concantenate
*/
#include <stdlib.h>
#include "my.h"

char *my_str_add(char *str, char *str2)
{
    int len = my_strlen(str) + my_strlen(str2) + 1;
    char *str3 = malloc(sizeof(char) * len);
    int j = 0;

    my_strcpy(str3, str);
    if (str3[my_strlen(str) - 1] == '\n') {
        str3[my_strlen(str) - 1] = ' ';
    }
    for (int i = my_strlen(str); i < len; i++) {
        str3[i] = str2[j];
        j++;
    }
    return str3;
}
