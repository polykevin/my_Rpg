/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** a function that splits a string into words. Separators will all be
** non-alphanumeric characters. The function returns an array in which each
** cell contains the address of a string (representing a word). The last cell
** must be null to terminate the array.
*/
#include "my.h"
#include <stdlib.h>

static int my_char_isalphanum(const char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    if (c == '.')
        return 0;
    return 0;
}

static int count_words(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_char_isalphanum(str[i]) && my_char_isalphanum(str[i + 1]))
            count++;
    }
    return count + 1;
}

static int alpha_numerical(int not_alphanum, int is_alphanum, char const *str,
    int i)
{
        not_alphanum = !my_char_isalphanum(str[i]);
        is_alphanum = my_char_isalphanum(str[i + 1]);
        return (not_alphanum && is_alphanum);
}

static char **fill_array(char **word_array, char const *str)
{
    int str_len = my_strlen(str);
    int not_alphanum = 0;
    int is_alphanum = 0;
    int is_correct = 0;
    int cpt = 0;
    int cpt_char = 0;

    for (int i = 0; i <= str_len; i++) {
        is_correct = alpha_numerical(not_alphanum, is_alphanum, str, i);
        if (is_correct || i == str_len) {
            word_array[cpt][cpt_char + 1] = '\0';
            cpt++;
            cpt_char = 0;
            continue;
        }
        word_array[cpt][cpt_char] = str[i];
        cpt_char++;
    }
    word_array[cpt] = 0;
    return word_array;
}

char **my_str_to_word_array(char const *str)
{
    char **word_array = malloc(sizeof(char *) * count_words(str));
    int not_alphanum = 0;
    int is_alphanum = 0;
    int is_correct = 0;
    int str_len = my_strlen(str);
    int word_len = 0;
    int cpt_char = 0;
    int cpt = 0;

    for (int i = 0; i <= str_len; i++) {
        is_correct = alpha_numerical(not_alphanum, is_alphanum, str, i);
        if (is_correct || i == str_len) {
            word_array[cpt] = malloc(sizeof(char) * word_len + 1);
            word_len = 0;
            cpt++;
            continue;
        }
        word_len++;
    }
    return fill_array(word_array, str);
}
