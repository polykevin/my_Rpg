/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** a function that returns a number, sent to the function as a string.
*/
#include "my.h"

int my_getnbr(char const *str, int idx)
{
    int i = idx;
    int sign = 1;
    long res = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign = -1;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + str[i] - '0';
        if (res * sign > 2147483647 || res * sign < -2147483648) {
            return 0;
        }
        i++;
    }
    return (int) (res * sign);
}
