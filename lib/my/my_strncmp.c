/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** string n compare
*/
#include "my.h"
int my_strncmp(char const *s1, char const *s2, int n)
{
    int s1_power = 0;
    int s2_power = 0;

    for (int i = n; (s1[i] != '\0') || (s2[i] != '\0'); i++) {
        s1_power += s1[i];
        s2_power += s2[i];
    }
    if (s1_power > s2_power)
        return 1;
    if (s1_power < s2_power)
        return -1;
    if (s1_power == s2_power)
        return 0;
}
