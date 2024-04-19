/*
** EPITECH PROJECT, 2023
** fonctions2
** File description:
** fonctions my_printf
*/
#include <stdarg.h>
#include <stdint.h>
#include "my.h"
#include "functions.h"

int put_d(va_list args, char const *format, int *i, int precision[])
{
    int nb = va_arg(args, int);
    int nb2 = nb;
    int cpt = 0;

    while (nb2 > 0) {
        nb2 /= 10;
        cpt++;
    }
    if (precision[0] == -6) {
        for (int j = 0; j < precision[1] - cpt; j++) {
            my_put_nbr(0);
        }
    }
    my_put_nbr(nb);
    return 0;
}

int put_s(va_list args, char const *format, int *i, int precision[])
{
    char *str = va_arg(args, char *);
    int len = my_strlen(str);

    if (precision[0] == -8) {
        for (int j = len; j < precision[1]; j++) {
            my_putchar(' ');
        }
    }
    my_putstr_n(str);
    return 0;
}

int put_c(va_list args, char const *format, int *i, int precision[])
{
    my_putchar(va_arg(args, int));
    return 0;
}

int put_percent(va_list args, char const *format, int *i, int precision[])
{
    my_putchar('%');
    return 0;
}

static void default_precision(int precision[])
{
    if (precision[0] == 0) {
        precision[0] = 6;
    }
}

static void neg(int nb)
{
    if (nb < 0) {
        my_put_nbr(nb * -1);
    } else {
        my_put_nbr(nb);
    }
}

int put_f(va_list args, char const *format, int *i, int precision[])
{
    double nb = va_arg(args, double);
    double next_nb = 0;

    default_precision(precision);
    my_put_nbr(nb);
    my_putchar('.');
    nb = (nb - (int)nb);
    for (int j = 0; j < precision[0]; j++) {
        nb = nb * 10;
        next_nb = nb;
        next_nb *= 10;
        if ((int)nb == 0) {
            my_put_nbr(0);
        }
        if ((int)next_nb % 10 >= 5 && j == precision[0] - 1) {
            nb++;
        }
    }
    neg(nb);
    return 0;
}
