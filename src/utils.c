/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** utils functions
*/
#include "utils.h"

float lerp(float a, float b, float t)
{
    return a + t * (b - a);
}
