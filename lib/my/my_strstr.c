/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** find a string in a string
*/
#include "my.h"
int loop_word(int index, char *str, char const *to_find)
{
    int found = 0;

    for (int i = 0; to_find[i] != '\0'; i++) {
        if (str[index + i] == to_find[i])
            found = 1;
        else {
            found = 0;
        }
    }
    return found;
}

char *my_strstr(char *str, char const *to_find)
{
    int idx = 0;
    int found = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[0]) {
            found = loop_word(i, str, to_find);
        }
        if (found) {
            idx = i;
            break;
        }
    }
    return str + idx;
}
