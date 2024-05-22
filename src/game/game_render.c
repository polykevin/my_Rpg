/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Game render functions
*/

#include "game.h"

void game_render_menu(game_t *g)
{
    if (g->state == MENU) {
        sfRenderWindow_drawSprite(g->window, g->menu.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->menu.buttons[0]->sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->menu.buttons[1]->sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->menu.buttons[2]->sprite, NULL);
    }
}

void game_render_map(game_t *g)
{
    if (g->state == MAP) {
        sfRenderWindow_drawSprite(g->window, g->map.sprite, NULL);
        for (int i = 0; i < 4; i++) {
            sfRenderWindow_drawSprite(g->window,
                g->tab_ennemy[i]->sprite, NULL);
        }
        sfRenderWindow_drawSprite(g->window, g->player.sprite, NULL);
        if (g->interact.draw)
            sfRenderWindow_drawSprite(g->window, g->interact.sprite, NULL);
    }
}

void game_render_fight(game_t *g)
{
    if (g->state == FIGHT) {
        sfRenderWindow_drawSprite(g->window, g->fight.scene.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.platform1.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.platform2.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.opponent.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.player.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.life.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.life2.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.skills.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.skills2.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.bar.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.paper.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.rock.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.cisor.sprite, NULL);
    }
}
