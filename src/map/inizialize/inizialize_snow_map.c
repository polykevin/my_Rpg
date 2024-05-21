/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"

void inizialize_player(level_t *level, char *texture, sfIntRect rect)
{
    PLAYER.texture = sfTexture_createFromFile(texture, NULL);
    PLAYER.sprite = sfSprite_create();
    PLAYER.texture_rect = rect;
    sfSprite_setTexture(PLAYER.sprite, PLAYER.texture, sfTrue);
    sfSprite_setTextureRect(PLAYER.sprite, PLAYER.texture_rect);
    sfSprite_setScale(PLAYER.sprite, (sfVector2f){0.3, 0.3});
    sfSprite_setPosition(PLAYER.sprite, (sfVector2f){MAP_WIDTH * 1.87,
    MAP_HEIGHT * 1.75});
}

void inizialize_map(level_t *level, char *texture, sfIntRect rect)
{
    S_MAP.texture = sfTexture_createFromFile(texture, NULL);
    S_MAP.sprite = sfSprite_create();
    S_MAP.texture_rect = rect;
    sfSprite_setTexture(S_MAP.sprite, S_MAP.texture, sfTrue);
    sfSprite_setTextureRect(S_MAP.sprite, S_MAP.texture_rect);
    sfSprite_setScale(S_MAP.sprite, (sfVector2f){4, 4});
}

static void inizialize_rec(level_t *level)
{
    REC = malloc(sizeof(rectangle_t) * 1);
    REC[0].rec = sfRectangleShape_create();
    sfRectangleShape_setSize(REC[0].rec, (sfVector2f){1600, 700});
    sfRectangleShape_setPosition(REC[0].rec, (sfVector2f){1500, 1700});
    sfRectangleShape_setFillColor(REC[0].rec,
    sfColor_fromRGBA(255, 0, 0, 0));
}

void inizialize_snow_level(level_t *level)
{
    inizialize_player(level, "resource/player/idlea.png",
    (sfIntRect){0, 0, 1154, 1052});
    inizialize_map(level, "resource/map/map.png",
    (sfIntRect){0, 0, 1154, 1052});
    inizialize_rec(level);
}
