/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_level.h"

void display_action(game_t *game, level_t *level)
{
    sfRenderWindow_clear(WINDOW, sfBlack);
    sfRenderWindow_setView(WINDOW, game->camera);
    sfRenderWindow_drawSprite(WINDOW, S_MAP.sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, PLAYER.sprite, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, REC[0].rec, NULL);
    sfRenderWindow_display(WINDOW);
}
