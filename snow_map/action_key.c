/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"

void run_action(level_t *level, game_t *game)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyS))
        map_movement(level, game, 1);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyW))
        map_movement(level, game, 2);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyA))
        map_movement(level, game, 3);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyD))
        map_movement(level, game, 4);
}
