/*
** EPITECH PROJECT, 2023
** put_x.c
** File description:
** putx
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

static void recursive_x(unsigned int quotient)
{
    unsigned int remainder = quotient % 16;

    if (quotient == 0)
        return;
    recursive_x(quotient / 16);
    dosumth(remainder);
}

static void recursive_x_maj(unsigned int quotient)
{
    unsigned int remainder = quotient % 16;

    if (quotient == 0)
        return;
    recursive_x_maj(quotient / 16);
    check_hex(remainder);
}

static void count_x(unsigned int quotient, int *cpt)
{
    unsigned int remainder = quotient % 16;

    if (quotient == 0)
        return;
    count_x(quotient / 16, cpt);
    (*cpt)++;
}

int put_x(va_list args, char const *format, int *i, int precision[])
{
    unsigned int quotient = va_arg(args, unsigned int);
    unsigned int quotient2 = quotient;
    int cpt = 0;

    if (precision[0] == -5) {
        my_putstr_n("0x");
    }
    if (quotient == 0) {
        my_put_nbr(0);
        return 0;
    }
    if (precision[0] == -6) {
        count_x(quotient2, &cpt);
        for (int j = cpt; j < precision[1]; j++) {
            my_put_nbr(0);
        }
    }
    recursive_x(quotient);
}

int put_x_maj(va_list args, char const *format, int *i, int precision[])
{
    unsigned int quotient = va_arg(args, unsigned int);
    unsigned int quotient2 = quotient;
    int cpt = 0;

    if (precision[0] == -5) {
        my_putstr_n("0X");
    }
    if (quotient == 0) {
        my_put_nbr(0);
        return 0;
    }
    if (precision[0] == -6) {
        count_x(quotient2, &cpt);
        for (int j = cpt; j < precision[1]; j++) {
            my_put_nbr(0);
        }
    }
    recursive_x_maj(quotient);
}
