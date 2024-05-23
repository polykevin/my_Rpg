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

void game_update_map(game_t *g)
{
    bool finished = false;

    if (g->state == MAP) {
        for (int i = 0; i < 9; i++) {
            g->tab_ennemy[i]->animation_speed = 0.22;
            sprite_animation(g->tab_ennemy[i], g, 32, 120);
        }
        if (!player_movement(g)) {
            sprite_animation(&g->player, g, PLAYER_SPRITE_SIZE, 320);
        }
        if (is_interact(g, &finished)) {
            sprite_animation(&g->interact, g, 1023, 7777);
        }
        if (!finished)
            sfRenderWindow_setView(g->window, g->camera);
    }
}

void game_update_fight(game_t *g)
{
    if (g->state == FIGHT) {
        update_fight(&g->fight, g);
        sprite_animation(&g->fight.player, g, 80, 320);
        sprite_animation(&g->fight.opponent, g, 32, 120);
    }
}
