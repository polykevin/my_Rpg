/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"

void destroy_game_menu(G_menu_t *menu)
{
    sfRectangleShape_destroy(BACK[0].back);
    sfRectangleShape_destroy(BACK[1].back);
    sfRectangleShape_destroy(BACK[2].back);
    sfFont_destroy(menu->font);
    for (int i = 0; i != 6; i++)
        sfText_destroy(TEXT[i].text);
    free(BACK);
    free(TEXT);
}

void destroy_snow(level_t *level)
{
    sfTexture_destroy(PLAYER.texture);
    sfTexture_destroy(S_MAP.texture);
    sfSprite_destroy(PLAYER.sprite);
    sfSprite_destroy(S_MAP.sprite);
    sfRectangleShape_destroy(REC[0].rec);
    free(REC);
}
