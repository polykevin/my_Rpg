/*
** EPITECH PROJECT, 2023
** functions
** File description:
** protoype
*/
#include "my.h"
#ifndef FONCTIONS_H_
    #define FONCTIONS_H_
int zero(va_list list, char const *format, int *i, int precision[]);
int spaces(va_list list, char const *format, int *i, int precision[]);
int hashtag(va_list list, char const *format, int *i, int precision[]);
int plus(va_list list, char const *format, int *i, int precision[]);
int precision(va_list list, char const *format, int *i, int precision[]);
int put_d(va_list args, char const *format, int *i, int precision[]);
int put_p(va_list args, char const *format, int *i, int precision[]);
int put_s(va_list args, char const *format, int *i, int precision[]);
int put_c(va_list args, char const *format, int *i, int precision[]);
int put_percent(va_list args, char const *format, int *i, int precision[]);
int put_f(va_list args, char const *format, int *i, int precision[]);
int put_o(va_list args, char const *format, int *i, int precision[]);
int put_x(va_list args, char const *format, int *i, int precision[]);
int put_x_maj(va_list args, char const *format, int *i, int precision[]);
int put_u(va_list args, char const *format, int *i, int precision[]);
#endif
