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
#include "sprite.h"
#include "game.h"
#include "fight.h"
#include "my.h"

char **set_position(int i)
{
    if (i == 0)
        return my_str_to_word_array("1.87,2.30", ',');
    if (i == 1)
        return my_str_to_word_array("2.7,1.77", ',');
    if (i == 2)
        return my_str_to_word_array("1.02,1.77", ',');
    if (i == 3)
        return my_str_to_word_array("1.87,1.32", ',');
    return NULL;
}

void ennemy_init(game_t *g)
{
    char **pos = NULL;
    sprite_t *ennemy = NULL;
    double x = 0;
    double y = 0;

    g->tab_ennemy = malloc(sizeof(sprite_t *) * 4);
    for (int i = 0; i < 4; i++) {
        ennemy = malloc(sizeof(sprite_t));
        sprite_init(ennemy, "resource/player/idle.png",
            (sfIntRect){0, 0, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE});
        sfSprite_setScale(g->interact.sprite, (sfVector2f){0.15, 0.15});
        sfSprite_setScale(ennemy->sprite, (sfVector2f){4, 4});
        pos = set_position(i);
        x = atof(pos[0]);
        y = atof(pos[1]);
        sfSprite_setPosition(ennemy->sprite, (sfVector2f){MAP_WIDTH * x,
            MAP_HEIGHT * y});
        g->tab_ennemy[i] = ennemy;
    }
}

static void init_sprite(game_t *g)
{
    sprite_init(&g->player, "resource/player/idle.png",
        (sfIntRect){0, 0, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE});
    g->player_textures[0] = g->player.texture;
    g->player_textures[1] =
        sfTexture_createFromFile("resource/player/walk.png", NULL);
    g->player_state = IDLE;
    g->player.animation_speed = 0.28;
    sprite_init(&g->map, "resource/map/map.png",
        (sfIntRect){0, 0, MAP_WIDTH, MAP_HEIGHT});
    sprite_init(&g->interact, "resource/interact.png",
        (sfIntRect){0, 0, INTERACT_WIDTH, INTERACT_HEIGHT});
    sfSprite_setScale(g->map.sprite, (sfVector2f){4, 4});
    g->interact.animation_speed = 0.10;
    sfSprite_setScale(g->player.sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(g->player.sprite, (sfVector2f){MAP_WIDTH * 1.87,
    MAP_HEIGHT * 1.75});
}

void game_init(game_t *g)
{
    g->mode.width = WIDTH;
    g->mode.height = HEIGHT;
    g->mode.bitsPerPixel = 32;
    g->window = sfRenderWindow_create(g->mode, "RPG",
    sfResize | sfClose, NULL);
    g->state = MENU;
    sfRenderWindow_setFramerateLimit(g->window, 60);
    init_sprite(g);
    ennemy_init(g);
    create_fight(&g->fight);
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
    bool finished = false;

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
        if (!player_movement(g)) {
            sprite_animation(&g->player, g, PLAYER_SPRITE_SIZE, 320);
        }
        if (is_interact(g, &finished)) {
            sprite_animation(&g->interact, g, 1023, 7777);
        }
        if (!finished)
            sfRenderWindow_setView(g->window, g->camera);
    }
    if (g->state == FIGHT) {
        sprite_animation(g->fight.player.sprite, g, 30, 320);
      //  sprite_animation(g->fight.opponent.sprite, g, 25, 384);
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
        for (int i = 0; i < 4; i++) {
            sfRenderWindow_drawSprite(g->window,
                g->tab_ennemy[i]->sprite, NULL);
        }
        sfRenderWindow_drawSprite(g->window, g->player.sprite, NULL);
        if (g->interact.draw)
            sfRenderWindow_drawSprite(g->window, g->interact.sprite, NULL);
    }
    if (g->state == FIGHT) {
            sfRenderWindow_drawSprite(g->window, g->fight.scene.sprite, NULL);
           sfRenderWindow_drawSprite(g->window, g->fight.platform1.sprite, NULL);
           sfRenderWindow_drawSprite(g->window, g->fight.platform2.sprite, NULL);
           sfRenderWindow_drawSprite(g->window, g->fight.opponent.sprite, NULL);
             sfRenderWindow_drawSprite(g->window, g->fight.player.sprite, NULL);
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
    for (int i = 0; i < 4; i++) {
        sprite_free(g->tab_ennemy[i]);
    }
    destroy_menu(&g->menu);
}
