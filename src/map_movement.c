/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

void wait_x_sec(float sec)
{
    sfClock *clock;
    float seconds = 0;
    int x = 0;

    clock = sfClock_create();
    while (seconds < sec) {
        seconds = time_as_seconds(clock);
        x++;
    }
    sfClock_destroy(clock);
}

static void make_the_movement(level_t *level, game_t *game,
    sfVector2f c_pos, sfVector2f text_pos)
{
    sfView_setCenter(game->camera, c_pos);
    sfRectangleShape_setPosition(REC[0].rec, text_pos);
}

static void move_map(level_t *level, game_t *game, int code)
{
    sfVector2f c_pos = sfView_getCenter(game->camera);
    sfVector2f text_pos = sfRectangleShape_getPosition(REC[0].rec);

    if (code == 1) {
        c_pos.y = c_pos.y - 500;
        text_pos.y = text_pos.y - 500;
    }
    if (code == 2) {
        c_pos.y = c_pos.y + 500;
        text_pos.y = text_pos.y + 500;
    }
    if (code == 3) {
        c_pos.x = c_pos.x - 1000;
        text_pos.x = text_pos.x - 1000;
    }
    if (code == 4) {
        c_pos.x = c_pos.x + 1000;
        text_pos.x = text_pos.x + 1000;
    }
    make_the_movement(level, game, c_pos, text_pos);
}

static void map_up(level_t *level, game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(PLAYER.sprite);

    while (sfKeyboard_isKeyPressed(sfKeyW)) {
        pos = sfSprite_getPosition(PLAYER.sprite);
        pos.y = pos.y - 4;
        if (check_contact(pos, REC[0].rec) == FAIL)
            move_map(level, game, 1);
        else
            sfSprite_setPosition(PLAYER.sprite, pos);
        wait_x_sec(0.01);
    }
}

static void map_down(level_t *level, game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(PLAYER.sprite);

    while (sfKeyboard_isKeyPressed(sfKeyS)) {
        pos = sfSprite_getPosition(PLAYER.sprite);
        pos.y = pos.y + 4;
        if (check_contact(pos, REC[0].rec) == FAIL)
            move_map(level, game, 2);
        else
            sfSprite_setPosition(PLAYER.sprite, pos);
        wait_x_sec(0.01);
    }
}

static void map_left(level_t *level, game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(PLAYER.sprite);

    while (sfKeyboard_isKeyPressed(sfKeyA)) {
        pos = sfSprite_getPosition(PLAYER.sprite);
        pos.x = pos.x - 4;
        if (check_contact(pos, REC[0].rec) == FAIL)
            move_map(level, game, 3);
        else
            sfSprite_setPosition(PLAYER.sprite, pos);
        wait_x_sec(0.01);
    }
}

static void map_right(level_t *level, game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(PLAYER.sprite);

    while (sfKeyboard_isKeyPressed(sfKeyD) != sfFalse) {
        pos = sfSprite_getPosition(PLAYER.sprite);
        pos.x = pos.x + 4;
        if (check_contact(pos, REC[0].rec) == FAIL)
            move_map(level, game, 4);
        else
            sfSprite_setPosition(PLAYER.sprite, pos);
        wait_x_sec(0.01);
    }
}

void map_movement(level_t *level, game_t *game, int direction)
{
    if (direction == 1)
        return (map_down(level, game));
    if (direction == 2)
        return (map_up(level, game));
    if (direction == 3)
        return (map_left(level, game));
    if (direction == 4)
        return (map_right(level, game));
}
