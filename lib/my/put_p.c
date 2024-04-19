/*
** EPITECH PROJECT, 2023
** put_p
** File description:
** put_p
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

static void recursive_p(void *quotient)
{
    unsigned int remainder = (intptr_t)quotient % 16;

    if (((intptr_t)quotient) == 0)
        return;
    recursive_p((void *)((intptr_t)quotient / 16));
    dosumth(remainder);
}

int put_p(va_list args, char const *format, int *i, int precision[])
{
    void *quotient = va_arg(args, void *);
    unsigned int remainder = (intptr_t)quotient;

    if (remainder == 0) {
        my_put_nbr(0);
        return 0;
    }
    my_putstr_n("0x");
    recursive_p(quotient);
}
