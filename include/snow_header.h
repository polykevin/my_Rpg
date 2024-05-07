/*
** EPITECH PROJECT, 2023
** MiniShell_header
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
    #include "snow_level.h"
    #include "game.h"
    #include <stdio.h>
    #include <stdlib.h>


// void snow_map(game_t *game);
void inizialize_snow_level(level_t *level);
void destroy_snow(level_t *level);
void run_action(level_t *level, game_t *game);
void display_action(game_t *game, level_t *level);
void idle_animation(level_t *level, game_t *g, int offset, int max);
void map_movement(level_t *level, game_t *game, int direction);
int check_contact(sfVector2f pos_1, sfVector2f scale_1,
    sfRectangleShape *box_2);
float time_as_seconds(sfClock *clock);
#endif /* LS_HEADER_H_ */
