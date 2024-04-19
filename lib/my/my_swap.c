/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** function that swaps the content of two integers, whose addresses are given
** as a parameter.
*/
#include "my.h"

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
