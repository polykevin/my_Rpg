/*
** EPITECH PROJECT, 2023
** put_u
** File description:
** put_u unsigned decimal
*/
#include <stdarg.h>
#include <stdint.h>
#include "my.h"
#include "functions.h"

static void count(int nb, int precision)
{
    int j = 0;

    for (; nb > 0; j++) {
        nb /= 10;
    }
    for (int i = j; i < precision; i++) {
        my_put_nbr(0);
    }
}

int put_u(va_list args, char const *format, int *i, int precision[])
{
    unsigned int nb = va_arg(args, unsigned int);
    int max_uint = 4294967295;
    int cpt = 0;

    if ((int)nb >= 0) {
        if (precision[0] == -6) {
            count(nb, precision[1]);
        }
        my_put_nbr(nb);
    } else {
        nb = (max_uint + (int)nb);
        if (precision[0] == -6) {
            count(nb, precision[1]);
        }
        my_put_nbr_uint(nb);
    }
    return 0;
}
