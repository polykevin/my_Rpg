/*
** EPITECH PROJECT, 2024
** game
** File description:
** game
*/
#ifndef GAME_H
    #define GAME_H
    #define NB_CIRCLES 600
    #define WIDTH 1920
    #define HEIGHT 1080
    #include <SFML/Graphics.h>
    #include "sprite.h"
    #include "struct.h"
    #include "sprite.h"
    #include "menu.h"
    #include "list.h"
typedef struct text {
    sfText *text_obj;
    sfFont *font;
}text_t;
typedef struct game {
    sfVideoMode mode;
    sfRenderWindow *window;
    menu_t menu;
    sfEvent event;
    sprite_t player;
}game_t;
void game_init(game_t *g, char *filename);
void game_loop(game_t *g);
void game_free(game_t *g);
#endif
