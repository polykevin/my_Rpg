/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_level.h"

void display_game_menu(game_t *game, G_menu_t *menu)
{
    if (menu->on_off == ON) {
        sfRenderWindow_drawRectangleShape(WINDOW, BACK[0].back, NULL);
        sfRenderWindow_drawRectangleShape(WINDOW, BACK[1].back, NULL);
        sfRenderWindow_drawRectangleShape(WINDOW, BACK[2].back, NULL);
        for (int i = 0; i != 6; i++)
            sfRenderWindow_drawText(WINDOW, TEXT[i].text, NULL);
    }
}

void display_action(game_t *game, level_t *level)
{
    sfRenderWindow_setView(WINDOW, game->camera);
    sfRenderWindow_drawSprite(WINDOW, S_MAP.sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, PLAYER.sprite, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, REC[0].rec, NULL);
}
