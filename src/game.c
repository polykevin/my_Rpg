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
#include "menu.h"
#include "sprite.h"
#include "game.h"

void game_init(game_t *g)
{
    g->mode.width = WIDTH;
    g->mode.height = HEIGHT;
    g->mode.bitsPerPixel = 32;
    g->window = sfRenderWindow_create(g->mode, "RPG",
    sfResize | sfClose, NULL);
    g->state = MENU;
    sfRenderWindow_setFramerateLimit(g->window, 60);
    sprite_init(&g->player, "idle.png", (sfIntRect){0, 0, PLAYER_SPRITE_SIZE,
        PLAYER_SPRITE_SIZE});
    sprite_init(&g->map, "map.png", (sfIntRect){0, 0, MAP_WIDTH, MAP_HEIGHT});
    sfSprite_setScale(g->map.sprite, (sfVector2f){4, 4});
    sfSprite_setScale(g->player.sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(g->player.sprite, (sfVector2f){MAP_WIDTH * 1.87,
    MAP_HEIGHT * 1.75});
    create_menu(&g->menu);
    g->camera = sfView_createFromRect((sfFloatRect){0, 0, WIDTH, HEIGHT});
    g->clock = sfClock_create();
    g->time = sfClock_getElapsedTime(g->clock);
}

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
    }
}

static void game_handle_time(game_t *g)
{
    g->last_time = g->time;
    g->time = sfClock_getElapsedTime(g->clock);
    g->delta_time = (g->time.microseconds / 1000000.0)
    - (g->last_time.microseconds / 1000000.0);
}

static void update(game_t *g)
{
    game_handle_time(g);
    if (g->state == MENU)
        update_menu(&g->menu);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        g->menu.buttons[0]->state == CLICKED && g->state == MENU) {
        g->state = MAP;
        sfView_setCenter(g->camera, (sfVector2f){MAP_WIDTH * 2,
            MAP_HEIGHT * 2});
        sfRenderWindow_setView(g->window, g->camera);
    }
    if (g->state == MAP) {
        sprite_animation(&g->player, g, PLAYER_SPRITE_SIZE, 320);
        sfRenderWindow_setView(g->window, g->camera);
    }
}

static void render(game_t *g)
{
    sfRenderWindow_clear(g->window, sfWhite);
    if (g->state == MENU) {
        sfRenderWindow_drawSprite(g->window, g->menu.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->menu.buttons[0]->sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->menu.buttons[1]->sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->menu.buttons[2]->sprite, NULL);
    }
    if (g->state == MAP) {
        sfRenderWindow_drawSprite(g->window, g->map.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->player.sprite, NULL);
    }
    if (g->state == FIGHT) {
    }
    sfRenderWindow_display(g->window);
}

void game_loop(game_t *g)
{
    while (sfRenderWindow_isOpen(g->window)) {
        poll_events(g);
        update(g);
        render(g);
    }
}

void game_free(game_t *g)
{
    sfRenderWindow_destroy(g->window);
    sprite_free(&g->map);
    sprite_free(&g->player);
    destroy_menu(&g->menu);
}
