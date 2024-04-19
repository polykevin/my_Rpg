/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** put a char
*/
#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_error(char c)
{
    write(2, &c, 1);
}
