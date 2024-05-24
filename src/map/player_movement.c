/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** player movement with arrows
*/
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
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
    sfSprite_setTexture(g->player.player_sprite.sprite,
        g->player_textures[1], sfTrue);
    sfSprite_setTextureRect(g->player.player_sprite.sprite, rect);
    g->player.player_sprite.texture_rect = rect;
    g->player.player_sprite.texture = g->player_textures[1];
    g->player_state = state;
}

static void move_up(game_t *g)
{
    sfColor pixel;
    sfVector2f player_pos;

    change_texture(240, UP, g);
    sfSprite_move(g->player.player_sprite.sprite,
        (sfVector2f){0, -PLAYER_SPEED});
    player_pos = sfSprite_getPosition(g->player.player_sprite.sprite);
    pixel = sfImage_getPixel(g->map_collision,
        player_pos.x / 4 + 40,
        player_pos.y / 4 + 40);
    if (pixel.r == 255 && pixel.g == 255 && pixel.b == 255) {
        sfSprite_setPosition(g->player.player_sprite.sprite,
            (sfVector2f){player_pos.x, player_pos.y + PLAYER_SPEED});
    }
    entity_collision(g, UP);
}

static void move_down(game_t *g)
{
    sfColor pixel;
    sfVector2f player_pos;

    change_texture(160, DOWN, g);
    sfSprite_move(g->player.player_sprite.sprite,
        (sfVector2f){0, PLAYER_SPEED});
    player_pos = sfSprite_getPosition(g->player.player_sprite.sprite);
    pixel = sfImage_getPixel(g->map_collision,
        player_pos.x / 4 + 40,
        player_pos.y / 4 + 40);
    if (pixel.r == 255 && pixel.g == 255 && pixel.b == 255) {
        sfSprite_setPosition(g->player.player_sprite.sprite,
            (sfVector2f){player_pos.x, player_pos.y - PLAYER_SPEED});
    }
    entity_collision(g, DOWN);
}

static void move_right(game_t *g)
{
    sfColor pixel;
    sfVector2f player_pos;

    change_texture(0, RIGHT, g);
    sfSprite_move(g->player.player_sprite.sprite,
        (sfVector2f){PLAYER_SPEED, 0});
    player_pos = sfSprite_getPosition(g->player.player_sprite.sprite);
    pixel = sfImage_getPixel(g->map_collision,
        player_pos.x / 4 + 40,
        player_pos.y / 4 + 40);
    if (pixel.r == 255 && pixel.g == 255 && pixel.b == 255) {
        sfSprite_setPosition(g->player.player_sprite.sprite,
            (sfVector2f){player_pos.x - PLAYER_SPEED, player_pos.y});
    }
    entity_collision(g, RIGHT);
}

static void move_left(game_t *g)
{
    sfColor pixel;
    sfVector2f player_pos;

    change_texture(80, LEFT, g);
    sfSprite_move(g->player.player_sprite.sprite,
        (sfVector2f){-PLAYER_SPEED, 0});
    player_pos = sfSprite_getPosition(g->player.player_sprite.sprite);
    pixel = sfImage_getPixel(g->map_collision,
        player_pos.x / 4 + 40,
        player_pos.y / 4 + 40);
    if (pixel.r == 255 && pixel.g == 255 && pixel.b == 255) {
        sfSprite_setPosition(g->player.player_sprite.sprite,
            (sfVector2f){player_pos.x + PLAYER_SPEED, player_pos.y});
    }
    entity_collision(g, LEFT);
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
    sfSprite_setTexture(g->player.player_sprite.sprite,
        g->player_textures[0], sfTrue);
    sfSprite_setTextureRect(g->player.player_sprite.sprite, rect);
    g->player.player_sprite.texture_rect = rect;
    g->player.player_sprite.texture = g->player_textures[0];
    g->player_state = IDLE;
}

static bool handle_arrow(game_t *g)
{
    bool moved = false;

    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        move_up(g);
        moved = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        move_down(g);
        moved = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        move_right(g);
        moved = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        move_left(g);
        moved = true;
    }
    return moved;
}

static void handle_ui(sfVector2f view_center, sfVector2f player_pos, game_t *g)
{
    sfSprite_setPosition(g->player.life_sprite.sprite,
        (sfVector2f){player_pos.x + 130, player_pos.y + 100});
    sfSprite_setPosition(g->player.coin_sprite.sprite,
        (sfVector2f){view_center.x - 950, view_center.y - 530});
    sfText_setPosition(g->player.money_text.text_obj,
        (sfVector2f){view_center.x - 880, view_center.y - 530});
}

bool player_movement(game_t *g)
{
    sfVector2f view_center = sfView_getCenter(g->camera);
    sfVector2f player_pos;
    sfVector2f new_life_pos;
    sfVector2f life_pos;
    bool moved = handle_arrow(g);

    if (!moved)
        basic_idle(g);
    else
        sprite_animation(&g->player.player_sprite, g, PLAYER_SPRITE_SIZE, 640);
    player_pos = sfSprite_getPosition(g->player.player_sprite.sprite);
    life_pos = sfSprite_getPosition(g->player.life_sprite.sprite);
    view_center.x = lerp(view_center.x, player_pos.x, 0.1) + 20;
    view_center.y = lerp(view_center.y, player_pos.y, 0.1) + 20;
    new_life_pos.x = lerp(life_pos.x, player_pos.x, 0.1);
    new_life_pos.y = lerp(life_pos.y, player_pos.y, 0.1);
    handle_ui(view_center, player_pos, g);
    sfView_setCenter(g->camera, view_center);
    return moved;
}
