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

static void init_sprite(game_t *g)
{
    sprite_init(&g->player.player_sprite, "resource/player/idle.png",
        (sfIntRect){0, 0, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE});
    g->player_textures[0] = g->player.player_sprite.texture;
    g->player_textures[1] =
        sfTexture_createFromFile("resource/player/walk.png", NULL);
    g->player_state = IDLE;
    g->player.player_sprite.animation_speed = 0.28;
    sprite_init(&g->map, "resource/map/map.png",
        (sfIntRect){0, 0, MAP_WIDTH, MAP_HEIGHT});
    sprite_init(&g->interact, "resource/map/interact.png",
        (sfIntRect){0, 0, INTERACT_WIDTH, INTERACT_HEIGHT});
    sfSprite_setScale(g->map.sprite, (sfVector2f){4, 4});
    g->interact.animation_speed = 0.10;
    sfSprite_setScale(g->player.player_sprite.sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(g->player.player_sprite.sprite,
        (sfVector2f){MAP_WIDTH * 1.87, MAP_HEIGHT * 1.75});
}

static void init_player_asset(game_t *g)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(g->player.player_sprite.sprite);

    sprite_init(&g->player.life_sprite, "resource/fight/h3.png",
        (sfIntRect){0, 0, 64, 16});
    sfSprite_setPosition(g->player.life_sprite.sprite,
        (sfVector2f){pos.left + 130,
        pos.top + 100});
    sprite_init(&g->player.coin_sprite, "resource/map/coin.png",
        (sfIntRect){0, 0, 20, 20});
    sfSprite_setScale(g->player.coin_sprite.sprite,
        (sfVector2f){3, 3});
    sfSprite_setPosition(g->player.coin_sprite.sprite,
        (sfVector2f){pos.left - 750, pos.top - 330});
    g->player.money_text.font =
        sfFont_createFromFile("resource/font/font.ttf");
    g->player.money_text.text_obj = sfText_create();
    sfText_setString(g->player.money_text.text_obj, g->player.money_str);
    sfText_setFont(g->player.money_text.text_obj, g->player.money_text.font);
    sfText_setCharacterSize(g->player.money_text.text_obj, 50);
    sfText_setColor(g->player.money_text.text_obj, sfBlack);
}

static void init_player(game_t *g)
{
    g->player.live = 4;
    g->player.attack = 1;
    g->player.defense = 0;
    g->player.speed = 0;
    g->player.attack_xp = 0;
    g->player.defense_xp = 0;
    g->player.speed_xp = 0;
    g->player.money = 0;
    g->player.money_str = my_int_to_str(g->player.money);
    init_player_asset(g);
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
    init_player(g);
    ennemy_init(g);
    g->opponent_live = 4;
    quete_text(&g->quete);
    create_pnj(&g->quete);
    create_fight(&g->fight, &g->player);
    create_menu(&g->menu);
    well(&g->element);
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
    for (int i = 0; i < 4; i++) {
        sprite_free(g->tab_ennemy[i]);
    }
    destroy_menu(&g->menu);
}
