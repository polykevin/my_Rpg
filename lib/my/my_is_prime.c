/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** a function that returns 1 if the number is prime and 0 if not
*/
#include "my.h"

int my_is_prime(int nb)
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
