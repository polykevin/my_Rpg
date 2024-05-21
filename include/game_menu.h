/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** the main header
*/

#include "snow_header.h"

#ifndef G_MENU_H_
    #define G_MENU_H_
    #define S_SET level->settings

typedef struct Background_s {
    sfRectangleShape *back;
} Background_t;

typedef struct words_s {
    sfText* text;
} words_t;

typedef struct P_sprite_s {
    sfTexture *texture;
    sfSprite *sprite;
} P_sprite_t;

typedef struct G_menu_s {
    Background_t *back;
    words_t *words;
    P_sprite_t *sprite;
    sfFont* font;
    int menu_nb;
    int on_off;
} G_menu_t;

#endif /* G_MENU_H_ */
