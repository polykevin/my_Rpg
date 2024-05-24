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
    #define INV inventory
    #define TEXT menu->words
    #define SUCCESS 0
    #define ON 0
    #define OFF 1
    #define LS_HEADER_H_
    #define EXIT_S 0
    #define EXIT_F 84
    #define SUCCESS 0
    #define FAIL -1
    #define ERROR_INT -1
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
    #include <stdbool.h>

// void snow_map(game_t *game);
int game_update_map(game_t *g, G_menu_t *menu, level_t *level);
int menu_enter(G_menu_t *menu, level_t *level, game_t *game);
void game_handle_time(game_t *g);
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
void default_game(level_t *level, G_menu_t *menu);
void print_inventory(G_menu_t *menu, level_t *level, game_t *game, int on);
void destroy_inventory(Inventory_t *inventory);
bool player_movement(game_t *g);
int inventory_on(G_menu_t *menu, level_t *level, game_t *game);
char *open_file(char const *filepath);
void free_array(char **array);
char **strtok_to_word_array(char *buffer, char const *separators);
void go_down_m(G_menu_t *menu);
void go_up_m(G_menu_t *menu);

#endif /* LS_HEADER_H_ */
