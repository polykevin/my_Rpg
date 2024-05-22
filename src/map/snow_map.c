/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"
#include "game.h"


static void run_snow_map(game_t *game, level_t *level, G_menu_t *menu)
{
    int exit = 0;

    while (sfRenderWindow_isOpen(WINDOW)){
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            exit = run_action(level, game, menu);
        if (exit == FAIL)
            return;
        sfRenderWindow_clear(WINDOW, sfBlack);
        display_action(game, level);
        display_game_menu(game, menu, level);
        sfRenderWindow_display(WINDOW);
    }
}

void snow_map(game_t *game)
{
    level_t level;
    G_menu_t menu;

    sfView_setCenter(game->camera, (sfVector2f){MAP_WIDTH * 2,
            MAP_HEIGHT * 2});
    sfRenderWindow_setView(WINDOW, game->camera);
    inizialize_snow_level(&level);
    inizialize_game_menu(&menu);
    default_game(&level, &menu);
    run_snow_map(game, &level, &menu);
    destroy_snow(&level);
    destroy_game_menu(&menu);
}
