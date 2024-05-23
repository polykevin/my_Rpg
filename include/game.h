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
    #include "snow_header.h"
    #include "sprite.h"
    #include "map_elements.h"

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

typedef struct text {
    sfText *text_obj;
    sfFont *font;
}text_t;

typedef struct main_player {
    int live;
    int attack;
    int defense;
    int speed;
    int attack_xp;
    int defense_xp;
    int speed_xp;
    int money;
    sprite_t player_sprite;
    sprite_t life_sprite;
    sprite_t coin_sprite;
    char *money_str;
    text_t money_text;
}main_player_t;

typedef enum choice {
    ROCK,
    PAPER,
    CISOR,
    CHOOSING
}choice_t;

typedef struct fight {
    sprite_t scene;
    sprite_t player;
    sprite_t opponent;
    sprite_t skills;
    sprite_t skills2;
    sprite_t bar;
    sprite_t life_player;
    sprite_t life_opponent;
    sprite_t platform1;
    sprite_t platform2;
    button_t rock;
    button_t paper;
    button_t cisor;
    sprite_t life;
    sprite_t life2;
    sprite_t fire;
    sprite_t defense;
    sprite_t other;
    sprite_t fire2;
    sprite_t defense2;
    sprite_t other2;
    sprite_t opponent_choice_sprite;
    sprite_t player_choice_sprite;
    sprite_t case1;
    sprite_t case2;
    int opponent_idx;
    choice_t player_choice;
    choice_t opponent_choice;
    sfTexture *live_texture[5];
} fight_t;

typedef struct game {
    sfVideoMode mode;
    sfRenderWindow *window;
    menu_t menu;
    fight_t fight;
    element_t element;
    sfEvent event;
    main_player_t player;
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
    int opponent_live;
}game_t;

typedef enum {
    DEATH,
    ONE_HEART,
    TWO_HEART,
    THREE_HEART,
    FOUR_HEART,
} texture_idx_t;


void game_init(game_t *g);
void game_loop(game_t *g);
void game_free(game_t *g);
void snow_map(game_t *game);
void game_update_fight(game_t *g);
void game_update_menu(game_t *g);
void game_render_menu(game_t *g);
void game_render_map(game_t *g);
void game_render_fight(game_t *g);

void create_stats(fight_t *fight);
void change_level(main_player_t *player, fight_t *fight);
void create_fight(fight_t *fight, main_player_t *player);
void fight_event(fight_t *fight, sfEvent *event);
void update_fight(fight_t *fight, game_t *g);
void choosing_animation(fight_t *fight, game_t *g);
void select_animation(button_t *button, sfVector2f scale,
    fight_t *fight, choice_t choice);
#endif
