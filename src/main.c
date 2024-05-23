/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** main
*/
#include "stats.h"
#include "fight.h"
#include "game.h"

int main(int argc, char **argv)
{
    game_t my_rpg = {0};

    game_init(&my_rpg);
    game_loop(&my_rpg);
    game_free(&my_rpg);
    return (0);
}
