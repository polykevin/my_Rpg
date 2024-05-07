/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"
#include "game.h"

static void run_snow_map(game_t *game, level_t *level)
{
    while (sfRenderWindow_isOpen(WINDOW)){
        // game_handle_time(game);
        // idle_animation(level, game, PLAYER_SPRITE_SIZE, 320);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            run_action(level, game);
        display_action(game, level);
    }
}

void snow_map(game_t *game)
{
    level_t level;

    sfView_setCenter(game->camera, (sfVector2f){MAP_WIDTH * 2,
            MAP_HEIGHT * 2});
    sfRenderWindow_setView(WINDOW, game->camera);
    inizialize_snow_level(&level);
    run_snow_map(game, &level);
    destroy_snow(&level);
}
