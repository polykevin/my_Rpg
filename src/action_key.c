/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"

static void inventory_off(level_t *level, game_t *game, G_menu_t *menu)
{
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyS))
        map_movement(level, game, 1);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyW))
        map_movement(level, game, 2);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyA))
        map_movement(level, game, 3);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyD))
        map_movement(level, game, 4);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyB)) {
        wait_x_sec(0.1);
        menu->on_off = ON;
        start_game_menu(game, menu);
    }
}

static int inventory_on(G_menu_t *menu)
{
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEscape)) {
        menu->on_off = OFF;
    }
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyUp))
        go_up(menu);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyDown))
        go_down(menu);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEnter))
        return (menu_enter(menu));
    return (0);
}

int run_action(level_t *level, game_t *game, G_menu_t *menu)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (menu->on_off == OFF)
        inventory_off(level, game, menu);
    else
        return (inventory_on(menu));
    return (0);
}
