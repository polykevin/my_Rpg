/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf
*/
#include <stdarg.h>
#include "my.h"
#include "functions.h"

static const char args[] = "discfoxXpu0123456789#+.%";
static const int (*tab[])() = {put_d, put_d, put_s, put_c, put_f, put_o, put_x,
    put_x_maj, put_p, put_u, zero, hashtag, plus, precision, put_percent};

int zero(va_list list, char const *format, int *i, int precision[])
{
    int nb = my_getnbr(format, (*i + 2));
    int nb2 = nb;
    int k = 0;

    precision[0] = -6;
    precision[1] = nb;
    for (; nb2 > 0; k++) {
        nb2 /= 10;
    }
    for (int j = 0; j < 15; j++) {
        if (format[*i] == '%' && format[*i + (2 + k)] == args[j]) {
            (*tab[j])(list, format, i, precision);
            *i += k + 1;
        }
    }
}

int hashtag(va_list list, char const *format, int *i, int precision[])
{
    precision[0] = -5;
    for (int j = 0; j < 15; j++) {
        if (format[*i] == '%' && format[*i + 2] == args[j]) {
            (*tab[j])(list, format, i, precision);
            *i += 1;
        }
    }
}

int plus(va_list list, char const *format, int *i, int precision[])
{
    my_putchar('+');
    for (int j = 0; j < 15; j++) {
        if (format[*i] == '%' && format[*i + 2] == args[j]) {
            (*tab[j])(list, format, i, precision);
            *i += 1;
        }
    }
}

int precision(va_list list, char const *format, int *i, int precision[])
{
    int nb = my_getnbr(format, (*i + 2));
    int nb2 = nb;
    int k = 0;

    precision[0] = nb;
    for (; nb2 > 0; k++) {
        nb2 /= 10;
    }
    for (int j = 0; j < 15; j++) {
        if (format[*i] == '%' && format[*i + (2 + k)] == args[j]) {
            (*tab[j])(list, format, i, precision);
            *i += k + 1;
        }
    }
}

static int check_args(va_list list, const char *format, int *i)
{
    int precision[] = {0, 0};

    for (int j = 0; j < 15; j++) {
        if (format[*i] == '%' && format[*i + 1] == args[j]) {
            (*tab[j])(list, format, i, precision);
            (*i)++;
        }
    }
}

int my_printf(const char *format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            check_args(list, format, &i);
            continue;
        }
        my_putchar(format[i]);
    }
    va_end(list);
    return 0;
}
