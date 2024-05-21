/*
** EPITECH PROJECT, 2023
** PRG
** File description:
** the main header
*/

#include "snow_header.h"

#ifndef S_LEVEL_H_
    #define S_LEVEL_H_
    #define S_SET level->settings

typedef struct PARAMETER_S {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect texture_rect;
} parameter_t;

typedef struct S_PLAYER {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect texture_rect;
    double accumulator;
} player_t;

typedef struct REC_S {
    sfRectangleShape *rec;
} rectangle_t;

typedef struct S_LVL {
    player_t player;
    parameter_t map;
    rectangle_t *rec;
} level_t;

#endif /* S_LEVEL_H_ */
