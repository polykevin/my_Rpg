/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** the main header
*/

#ifndef LS_HEADER_H_
    #define LS_HEADER_H_
    #define WINDOW game->window
    #define EVENT game->event
    #define PLAYER level->player
    #define S_MAP level->map
    #define REC level->rec
    #define BACK menu->back
    #define INV level->inventory
    #define TEXT menu->words
    #define SUCCESS 0
    #define ON 0
    #define OFF 1
    #define LS_HEADER_H_
    #define EXIT_S 0
    #define EXIT_F 84
    #define SUCCESS 0
    #define FAIL -1
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include "game.h"
    #include "snow_level.h"
    #include "game_menu.h"
    #include <stdio.h>
    #include <stdlib.h>


// void snow_map(game_t *game);
int menu_enter(G_menu_t *menu, level_t *level, game_t *game);
int run_action(level_t *level, game_t *game, G_menu_t *menu);
void wait_x_sec(float sec);
void inizialize_snow_level(level_t *level);
void inizialize_game_menu(G_menu_t *menu);
void destroy_snow(level_t *level);
void destroy_game_menu(G_menu_t *menu);
void display_action(game_t *game, level_t *level);
void display_game_menu(game_t *game, G_menu_t *menu, level_t *level);
void idle_animation(level_t *level, game_t *g, int offset, int max);
void map_movement(level_t *level, game_t *game, int direction);
int check_contact(sfVector2f pos_1, sfRectangleShape *box_2);
float time_as_seconds(sfClock *clock);
void start_game_menu(game_t *game, G_menu_t *menu);
void go_down(G_menu_t *menu);
void go_up(G_menu_t *menu);
void default_game(level_t *level, G_menu_t *menu);
void print_inventory(G_menu_t *menu, level_t *level, game_t *game);
void destroy_inventory(Inventory_t *inventory);

#endif /* LS_HEADER_H_ */
