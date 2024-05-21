/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"


static void inventory_off(level_t *level, game_t *g, G_menu_t *menu)
{
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyS))
        map_movement(level, g, 1);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyW))
        map_movement(level, g, 2);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyA))
        map_movement(level, g, 3);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyD))
        map_movement(level, g, 4);
    // if (!player_movement(g)) {
    //         sprite_animation(&g->player, g, PLAYER_SPRITE_SIZE, 320);
    //     }
    //     sfRenderWindow_setView(g->window, g->camera);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyB)) {
        wait_x_sec(0.1);
        menu->on_off = ON;
        start_game_menu(g, menu);
    }
}

static int inventory(G_menu_t *menu, level_t *level)
{
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEscape)) {
        menu->bag = OFF;
        destroy_inventory(level->inventory);
        wait_x_sec(0.3);
    }
    return 0;
}

static int inventory_on(G_menu_t *menu, level_t *level, game_t *game)
{
    if (menu->bag == ON)
        return (inventory(menu, level));
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEscape)) {
        menu->on_off = OFF;
    }
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyUp))
        go_up(menu);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyDown))
        go_down(menu);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEnter))
        return (menu_enter(menu, level, game));
    return (0);
}

int run_action(level_t *level, game_t *game, G_menu_t *menu)
{
    game_handle_time(game);
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (menu->on_off == OFF)
        inventory_off(level, game, menu);
    else
        return (inventory_on(menu, level, game));
    return (0);
}
