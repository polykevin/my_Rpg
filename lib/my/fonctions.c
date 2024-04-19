/*
** EPITECH PROJECT, 2023
** fonctions.c
** File description:
** fonctions
*/
#include <stdarg.h>
#include <stdint.h>
#include "my.h"
#include "functions.h"

static int dosumth2(int remainder)
{
    if (remainder == 13) {
        my_putchar('d');
        return 0;
    }
    if (remainder == 14) {
        my_putchar('e');
        return 0;
    }
    if (remainder == 15) {
        my_putchar('f');
        return 0;
    }
    my_put_nbr(remainder);
}

static int dosumth(int remainder)
{
    if (remainder == 10) {
        my_putchar('a');
        return 0;
    }
    if (remainder == 11) {
        my_putchar('b');
        return 0;
    }
    if (remainder == 12) {
        my_putchar('c');
        return 0;
    }
    dosumth2(remainder);
}

static int check_hex2(int remainder)
{
    if (remainder == 13) {
        my_putchar('D');
        return 0;
    }
    if (remainder == 14) {
        my_putchar('E');
        return 0;
    }
    if (remainder == 15) {
        my_putchar('F');
        return 0;
    }
    my_put_nbr(remainder);
}

static int check_hex(int remainder)
{
    if (remainder == 10) {
        my_putchar('A');
        return 0;
    }
    if (remainder == 11) {
        my_putchar('B');
        return 0;
    }
    if (remainder == 12) {
        my_putchar('C');
        return 0;
    }
    check_hex2(remainder);
}

static void recursive_o(unsigned int quotient)
{
    if (quotient == 0) {
        return;
    }
    recursive_o(quotient / 8);
    my_put_nbr(quotient % 8);
    return;
}

static void count_o(unsigned int quotient, int *cpt)
{
    if (quotient == 0) {
        return;
    }
    count_o(quotient / 8, cpt);
    (*cpt)++;
    return;
}

static void check_hashtag(int precision)
{
    if (precision == -5)
        my_put_nbr(0);
}

static void put_zeros(int cpt, int precision[])
{
    if (precision[0] == -6) {
        for (int j = cpt; j < precision[1]; j++) {
            my_put_nbr(0);
        }
    }
}

static void case_zero(unsigned int quotient)
{
    if (quotient == 0) {
        my_put_nbr(0);
        return;
    }
}

int put_o(va_list args, char const *format, int *i, int precision[])
{
    unsigned int quotient = va_arg(args, unsigned int);
    unsigned int quotient2 = quotient;
    int cpt = 0;

    check_hashtag(precision[0]);
    if (precision[0] > 0 && quotient == 0) {
        for (int j = 0; j <= precision[0]; j++) {
            my_put_nbr(0);
        }
        return 0;
    }
    case_zero(quotient);
    count_o(quotient2, &cpt);
    for (int j = cpt; j < precision[0]; j++) {
        my_put_nbr(0);
    }
    put_zeros(cpt, precision);
    recursive_o(quotient);
}
