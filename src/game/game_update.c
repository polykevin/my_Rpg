/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** game update functions
*/
#include "fight.h"
#include "game.h"
#include "player_movement.h"
#include "interact.h"
#include "snow_header.h"

void game_update_menu(game_t *g)
{
    if (g->state == MENU)
        update_menu(&g->menu);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        g->menu.buttons[0]->state == CLICKED && g->state == MENU) {
        g->state = MAP;
        sfView_setCenter(g->camera, (sfVector2f){MAP_WIDTH * 2,
            MAP_HEIGHT * 2});
        sfRenderWindow_setView(g->window, g->camera);
    }
}

void inventory_off(game_t *g, G_menu_t *menu)
{
    bool finished = false;

    if (!player_movement(g)) {
        sprite_animation(&g->player, g, PLAYER_SPRITE_SIZE, 320);
    }
    if (is_interact(g, &finished)) {
        sprite_animation(&g->interact, g, 1023, 7777);
    }
    if (!finished)
        sfRenderWindow_setView(g->window, g->camera);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyB)) {
        wait_x_sec(0.1);
        menu->on_off = ON;
        start_game_menu(g, menu);
    }
}

int game_update_map(game_t *g, G_menu_t *menu, level_t *level)
{
    if (g->state == MAP) {
        if (menu->on_off == OFF)
            inventory_off(g, menu);
        else
            return (inventory_on(menu, level, g));
    }
    return 0;
}

void game_update_fight(game_t *g)
{
    if (g->state == FIGHT) {
        update_fight(&g->fight, g);
        sprite_animation(&g->fight.player, g, 80, 320);
        sprite_animation(&g->fight.opponent, g, 32, 120);
    }
}
