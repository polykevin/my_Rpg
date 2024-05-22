/*
** EPITECH PROJECT, 2024
** RPG
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
    #define INTERACT_WIDTH 625
    #define INTERACT_HEIGHT 320
    #include <SFML/Graphics.h>
    #include "menu.h"
    #include "list.h"
    #include "sprite.h"
    #include "fight.h"
    #include "map_elements.h"

typedef struct text {
    sfText *text_obj;
    sfFont *font;
}text_t;

typedef enum {
    MENU,
    MAP,
    FIGHT
}game_state_t;

typedef enum {
    UP,
    DOWN,
    RIGHT,
    LEFT,
    IDLE
}player_state_t;

typedef struct game {
    sfVideoMode mode;
    sfRenderWindow *window;
    menu_t menu;
    fight_t fight;
    element_t element;
    sfEvent event;
    sprite_t player;
    player_state_t player_state;
    sfTexture *player_textures[2];
    sprite_t map;
    sprite_t **tab_ennemy;
    sprite_t interact;
    game_state_t state;
    sfView *camera;
    sfClock *clock;
    sfTime time;
    sfTime last_time;
    double delta_time;
}game_t;

void game_init(game_t *g);
int game_loop(game_t *g);
void game_free(game_t *g);
void snow_map(game_t *game);
void game_update_fight(game_t *g);
void game_update_map(game_t *g);
void game_update_menu(game_t *g);
void game_render_menu(game_t *g);
void game_render_map(game_t *g);
void game_render_fight(game_t *g);
#endif
