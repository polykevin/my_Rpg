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
#include "sprite.h"
#include "game.h"
#include "draw.h"

void game_init(game_t *g, char *filename)
{
    g->mode.width = WIDTH;
    g->mode.height = HEIGHT;
    g->mode.bitsPerPixel = 32;
    g->window = sfRenderWindow_create(g->mode, "RPG",
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(g->window, 60);
    sprite_init(&g->player, "idle.png");
    create_menu(&g->menu);
}

static void poll_events(game_t *g)
{
    while (sfRenderWindow_pollEvent(g->window, &g->event)) {
        if (g->event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
    }
}

static void update(game_t *g)
{
    sprite_animation(&g->player);
}

static void render(game_t *g)
{
    sfRenderWindow_clear(g->window, sfWhite);
    sfRenderWindow_drawSprite(g->window, g->player.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.sprite, NULL);
    //sfRenderWindow_drawSprite(g->window, g->menu.buttons[0]->sprite, NULL);
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
}
