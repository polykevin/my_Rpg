/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "game.h"

int my_rpg(int argc, char **argv)
{
    game_t my_rpg = {0};

    game_init(&my_rpg);
    game_loop(&my_rpg);
    game_free(&my_rpg);
    return (0);
}
