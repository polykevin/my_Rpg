/*
** EPITECH PROJECT, 2023
** game
** File description:
** game
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "button.h"
#include "interact.h"
#include "menu.h"
#include "player_movement.h"
#include "snow_header.h"
#include "sprite.h"
#include "game.h"
#include "fight.h"
#include "my.h"

static void poll_events(game_t *g)
{
    while (sfRenderWindow_pollEvent(g->window, &g->event)) {
        if (g->event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        if (g->event.type == sfEvtMouseButtonPressed && g->state == MENU) {
            menu_event(&g->menu, &g->event);
        }
        if (g->event.type == sfEvtMouseMoved && g->state == MENU) {
            menu_event(&g->menu, &g->event);
        }
        if (g->event.type == sfEvtMouseButtonPressed && g->state == FIGHT) {
            fight_event(&g->fight, &g->event);
        }
        if (g->event.type == sfEvtMouseMoved && g->state == FIGHT) {
            fight_event(&g->fight, &g->event);
        }
    }
}

void game_handle_time(game_t *g)
{
    g->last_time = g->time;
    g->time = sfClock_getElapsedTime(g->clock);
    g->delta_time = (g->time.microseconds / 1000000.0)
    - (g->last_time.microseconds / 1000000.0);
}

static int update(game_t *g, G_menu_t *menu, level_t *level)
{
    game_handle_time(g);
    game_update_menu(g);
    if (game_update_map(g, menu, level) == FAIL)
        return FAIL;
    game_update_fight(g);
    return (0);
}

static void render(game_t *g)
{
    sfRenderWindow_clear(g->window, sfWhite);
    game_render_menu(g);
    game_render_map(g);
    game_render_fight(g);
}

void game_loop(game_t *g)
{
    G_menu_t menu;
    level_t level;
    int exit = 0;

    inizialize_game_menu(&menu);
    default_game(&level, &menu);
    while (sfRenderWindow_isOpen(g->window) && exit != FAIL) {
        poll_events(g);
        exit = update(g, &menu, &level);
        render(g);
        display_game_menu(g, &menu, &level);
        sfRenderWindow_display(g->window);
    }
    destroy_game_menu(&menu);
}

void game_free(game_t *g)
{
    sfRenderWindow_destroy(g->window);
    sprite_free(&g->map);
    sprite_free(&g->player.player_sprite);
    for (int i = 0; i < 12; i++) {
        sprite_free(g->tab_ennemy[i]);
    }
    destroy_menu(&g->menu);
}
