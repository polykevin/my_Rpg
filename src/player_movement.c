/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** player movement with arrows
*/
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>
#include <stdbool.h>
#include "player_movement.h"
#include "game.h"
#include "sprite.h"
#include "utils.h"

static void change_texture(int y, player_state_t state, game_t *g)
{
    sfIntRect rect;

    if (g->player_state == state)
        return;
    rect = (sfIntRect){0, y, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE};
    sfSprite_setTexture(g->player.sprite, g->player_textures[1], sfTrue);
    sfSprite_setTextureRect(g->player.sprite, rect);
    g->player.texture_rect = rect;
    g->player.texture = g->player_textures[1];
    g->player_state = state;
}

static void go_up(game_t *g)
{
    change_texture(240, UP, g);
    sfSprite_move(g->player.sprite, (sfVector2f){0, -PLAYER_SPEED});
}

static void go_down(game_t *g)
{
    change_texture(160, DOWN, g);
    sfSprite_move(g->player.sprite, (sfVector2f){0, PLAYER_SPEED});
}

static void go_right(game_t *g)
{
    change_texture(0, RIGHT, g);
    sfSprite_move(g->player.sprite, (sfVector2f){PLAYER_SPEED, 0});
}

static void go_left(game_t *g)
{
    change_texture(80, LEFT, g);
    sfSprite_move(g->player.sprite, (sfVector2f){-PLAYER_SPEED, 0});
}

static sfIntRect idle_direction(game_t *g)
{
    if (g->player_state == RIGHT) {
        return (sfIntRect){0, 0, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE};
    }
    if (g->player_state == LEFT) {
        return (sfIntRect){0, 80, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE};
    }
    if (g->player_state == DOWN) {
        return (sfIntRect){0, 160, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE};
    }
    if (g->player_state == UP) {
        return (sfIntRect){0, 240, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE};
    }
    return (sfIntRect){0, 0, 0, 0};
}

static void basic_idle(game_t *g)
{
    sfIntRect rect;

    if (g->player_state == IDLE)
        return;
    rect = idle_direction(g);
    sfSprite_setTexture(g->player.sprite, g->player_textures[0], sfTrue);
    sfSprite_setTextureRect(g->player.sprite, rect);
    g->player.texture_rect = rect;
    g->player.texture = g->player_textures[0];
    g->player_state = IDLE;
}

static bool handle_arrow(game_t *g)
{
    bool moved = false;

    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        go_up(g);
        moved = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        go_down(g);
        moved = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        go_right(g);
        moved = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        go_left(g);
        moved = true;
    }
    return moved;
}

bool player_movement(game_t *g)
{
    sfVector2f view_center = sfView_getCenter(g->camera);
    sfVector2f player_pos;
    bool moved = handle_arrow(g);

    if (!moved)
        basic_idle(g);
    else
        sprite_animation(&g->player, g, PLAYER_SPRITE_SIZE, 640);
    player_pos = sfSprite_getPosition(g->player.sprite);
    view_center.x = lerp(view_center.x, player_pos.x, 0.1) + 20;
    view_center.y = lerp(view_center.y, player_pos.y, 0.1) + 20;
    sfView_setCenter(g->camera, view_center);
    return moved;
}
