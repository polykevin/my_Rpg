/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "game.h"

int main(int argc, char *argv[])
{
    game_t my_paint = {0};
    char *filename = NULL;

    game_init(&my_paint);
    game_loop(&my_paint);
    game_free(&my_paint);
    return 0;
}
