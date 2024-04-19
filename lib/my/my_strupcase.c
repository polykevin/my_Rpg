/*
** EPITECH PROJECT, 2023
** my_strupcase
** File description:
** a function that puts every letter of every word in it in uppercase.
*/
#include "my.h"
char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
