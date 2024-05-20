/*
** EPITECH PROJECT, 2023
** my_pong_header
** File description:
** the main header
*/

#include "snow_header.h"


#ifndef S_LEVEL_H_
    #define S_LEVEL_H_
    #define S_SET level->settings

static const char *const_inventory[] = {
    "Potion",
    "Potion L",
    "Potion XL",
    "Potion XXL",
    "Mana Potion",
    0
};

typedef struct PARAMETER_S {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect texture_rect;
} parameter_t;

typedef struct Inventory_s {
    int nb;
    int id;
    sfText* name;
    sfText* number;
    struct Inventory_s *next;
} Inventory_t;

typedef struct def_inventory_s {
    sfSprite *sprite;
    sfTexture *texture;
} def_inventory_t;

typedef struct S_PLAYER {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect texture_rect;
    double accumulator;
    int exp;
    int max_exp;
    int hp;
    int hp_max;
    int gold;
} player_t;

typedef struct REC_S {
    sfRectangleShape *rec;
} rectangle_t;

typedef struct S_LVL {
    player_t player;
    parameter_t map;
    rectangle_t *rec;
    Inventory_t *inventory;
    def_inventory_t def_inventory;
} level_t;

#endif /* S_LEVEL_H_ */
