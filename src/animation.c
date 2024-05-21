/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_level.h"

void game_handle_time(game_t *g)
{
    g->last_time = g->time;
    g->time = sfClock_getElapsedTime(g->clock);
    g->delta_time = (g->time.microseconds / 1000000.0)
    - (g->last_time.microseconds / 1000000.0);
}

void idle_animation(S_LVL_T *level, game_t *g, int offset, int max)
{
    if (PLAYER.texture_rect.left >= max) {
        PLAYER.texture_rect.left = 0;
    }
    if (PLAYER.accumulator >= 0.28) {
        PLAYER.texture_rect.left += offset;
        if (PLAYER.texture_rect.left < max) {
            sfSprite_setTextureRect(PLAYER.sprite, PLAYER.texture_rect);
        }
        PLAYER.accumulator = 0;
    }
    PLAYER.accumulator += g->delta_time;
    PLAYER.texture_rect.left = offset;
    sfSprite_setTextureRect(PLAYER.sprite, PLAYER.texture_rect);
}
