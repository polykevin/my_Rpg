/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_str_to_word_array.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

int nb_words(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != c && str[i] != '\t' && (str[i + 1] == c || str[i + 1] ==
        '\0' || str[i + 1] == '\t'))
            count++;
    return count;
}

char **my_str_to_word_array(char *s, char c)
{
    char **array = malloc(sizeof(char *) * (nb_words(s, c) + 1));
    int a = 0;
    int j = 0;
    int k = 0;

    for (int i = 0; i < nb_words(s, c); i++) {
        while (s[a] == c || s[a] == '\n' || s[a] == '\t' || s[a] == ' ')
            a++;
        k = a;
        while (s[a] != c && s[a] != '\n' && s[a] != '\0' && s[a] != '\t')
            a++;
        array[i] = malloc(sizeof(char) * (a - k + 1));
        for (j = 0; k < a; j++){
            array[i][j] = s[k];
            k++;
            }
        array[i][j] = '\0';
    }
    array[nb_words(s, c)] = NULL;
    return array;
}
