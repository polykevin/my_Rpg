/*
** EPITECH PROJECT, 2023
** my_find_prime_sup.c
** File description:
** a function that returns the smallest prime number that is greater than, or
** equal to, the number given as a paramater.
*/
#include "my.h"

int is_prime(int nb)
{
    int i = 1;
    int nb_divisor = 0;

    if (nb <= 1)
        return 0;
    while (i <= nb) {
        if (nb % i == 0)
            nb_divisor++;
        i++;
    }
    if (nb_divisor <= 2)
        return 1;
    return 0;
}

int my_find_prime_sup(int nb)
{
    int i = nb;

    while (!is_prime(i)) {
        i++;
    }
    return i;
}
