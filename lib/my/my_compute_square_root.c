/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** a function that returns the square root (if it is a whole number) of the
** number given as argument. If the square root is nota whole number, the
** function should return 0.
*/
#include "my.h"

int my_compute_square_root(int nb)
{
    int i = 0;
    int find = 0;

    while (!find) {
        i++;
        if ((i * i) == nb) {
            find = 1;
            break;
        }
        if (i > nb) {
            i = 0;
            find = 1;
            break;
        }
    }
    return i;
}
