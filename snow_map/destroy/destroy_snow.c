/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"

void destroy_snow(level_t *level)
{
    sfTexture_destroy(PLAYER.texture);
    sfTexture_destroy(S_MAP.texture);
    sfSprite_destroy(PLAYER.sprite);
    sfSprite_destroy(S_MAP.sprite);
    sfRectangleShape_destroy(REC[0].rec);
}
