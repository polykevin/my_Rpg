/*
** EPITECH PROJECT, 2024
** game
** File description:
** game
*/
#ifndef GAME_H
    #define GAME_H
    #define WIDTH 1920
    #define HEIGHT 1080
    #define PLAYER_SPRITE_SIZE 80
    #define MAP_WIDTH 1154
    #define MAP_HEIGHT 1052
    #include <SFML/Graphics.h>
    #include "menu.h"
    #include "list.h"
    #include "sprite.h"

typedef struct text {
    sfText *text_obj;
    sfFont *font;
}text_t;

typedef enum {
    MENU,
    MAP
}game_state_t;

typedef struct game {
    sfVideoMode mode;
    sfRenderWindow *window;
    menu_t menu;
    sfEvent event;
    sprite_t player;
    sprite_t map;
    game_state_t state;
    sfView *camera;
    sfClock *clock;
    sfTime time;
    sfTime last_time;
    double delta_time;
}game_t;

int my_rpg(int argc, char **argv);
void game_init(game_t *g);
void game_loop(game_t *g);
void game_free(game_t *g);
void snow_map(game_t *game);
#endif
