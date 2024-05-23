/*
** EPITECH PROJECT, 2024
** strtok_to_word_array.c
** File description:
** str to word array using strtok
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "snow_header.h"

static int nb_of_separation(char const *string, char const *delim)
{
    char *temp = strdup(string);
    char *token = NULL;
    int res = 0;

    if (temp == NULL) {
        dprintf(2, "[ERROR] Unable to duplicate string\n");
        return ERROR_INT;
    }
    token = strtok(temp, delim);
    while (token != NULL) {
        res += 1;
        token = strtok(NULL, delim);
    }
    free(temp);
    return res;
}

static int loop(char *token, char **res, char const *delim)
{
    int counter = 0;

    while (token != NULL) {
        res[counter] = strdup(token);
        if (res[counter] == NULL) {
            dprintf(2, "[ERROR] Unable to duplicate string\n");
            return ERROR_INT;
        }
        token = strtok(NULL, delim);
        counter += 1;
    }
    return 0;
}

char **strtok_to_word_array(char *string_og, char const *delim)
{
    char *string = strdup(string_og);
    int malloc_size = nb_of_separation(string, delim);
    char *token = strtok(string, delim);
    char **res = NULL;

    if (malloc_size == ERROR_INT) {
        return NULL;
    }
    res = malloc(sizeof(char *) * (malloc_size + 1));
    if (res == NULL) {
        dprintf(2, "[ERROR] Unable to allocate memory\n");
        return NULL;
    }
    res[malloc_size] = NULL;
    if (loop(token, res, delim) == ERROR_INT) {
        return NULL;
    }
    free(string);
    return res;
}
