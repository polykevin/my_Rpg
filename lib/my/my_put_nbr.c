/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** a function that displays the number given as a parameter. It mush be able
** to display all the possible values of an int
*/
#include "my.h"

static int aux_while(int count, int count1, int nbsave, int nb)
{
    int print_count = 0;

    while (nb > 0){
        nb = nb / 10;
        count++;
    }
    nb = nbsave;
    while (nb > 0){
        if ((count - 1) == count1){
            my_putchar(nb % 10 + '0');
            print_count++;
            nb = nbsave;
            count1 = 0;
            count--;
        }
        nb = nb / 10;
        count1++;
    }
    return print_count;
}

static int max_fix(int max, int nbsave, int nb, int *print_count)
{
    if (max) {
        my_putchar((nbsave % 10 + '0') + 1);
        (*print_count)++;
    } else if (nb > 9) {
        my_putchar(nbsave % 10 + '0');
        (*print_count)++;
    }
    if (nb == 0) {
        my_putchar('0');
        (*print_count)++;
    }
    return *print_count;
}

static int aux_while_uint(int count, int count1, unsigned int nbsave,
    unsigned int nb)
{
    int print_count = 0;

    while (nb > 0){
        nb = nb / 10;
        count++;
    }
    nb = nbsave;
    while (nb > 0){
        if ((count - 1) == count1){
            my_putchar(nb % 10 + '0');
            print_count++;
            nb = nbsave;
            count1 = 0;
            count--;
        }
        nb = nb / 10;
        count1++;
    }
    return print_count;
}

static int max_fix_uint(int max, unsigned int nbsave, unsigned int nb,
    int *print_count)
{
    if (max) {
        my_putchar((nbsave % 10 + '0') + 1);
        (*print_count)++;
    } else if (nb > 9) {
        my_putchar(nbsave % 10 + '0');
        (*print_count)++;
    }
    if (nb == 0) {
        my_putchar('0');
        (*print_count)++;
    }
    return *print_count;
}

static int neg_check(int neg)
{
    if (neg == 1) {
        my_putchar('-');
    }
    return 0;
}

int my_put_nbr(int nb)
{
    int count = 0;
    int count1 = 0;
    int nbsave = nb;
    int neg = 0;
    int max = 0;
    int print_count = 0;

    if (nb < 0){
        if (nb == -2147483648) {
            max = 1;
            nb = 2147483647;
        } else {
            nb = nb * (-1);
        }
        neg = 1;
        nbsave = nb;
    }
    neg_check(neg);
    print_count += aux_while(count, count1, nbsave, nb);
    return max_fix(max, nbsave, nb, &print_count);
}

int my_put_nbr_uint(unsigned int nb)
{
    int count = 0;
    int count1 = 0;
    unsigned int nbsave = nb;
    int neg = 0;
    int max = 0;
    int print_count = 0;

    print_count += aux_while_uint(count, count1, nbsave, nb);
    return max_fix_uint(max, nbsave, nb, &print_count);
}
