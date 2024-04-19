/*
** EPITECH PROJECT, 2023
** main
** File description:
** a function that displays either N if the integer passed as parameter is
** negative or P, if positive or null.
*/
#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    if (n >= 0)
        my_putchar('P');
    my_putchar('\n');
    return 0;
}
