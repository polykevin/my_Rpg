/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** sprite
*/

#ifndef SPRITE_H
    #define SPRITE_H
    #include <stdbool.h>

typedef struct sprite {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect texture_rect;
    bool draw;
    double animation_speed;
    double accumulator;
}sprite_t;

typedef struct game game_t;

void sprite_init(sprite_t *s, char *texture, sfIntRect rect);
void sprite_draw(sprite_t *s, sfRenderWindow *window);
void sprite_animation(sprite_t *s, game_t *g, int offset, int max);
void sprite_free(sprite_t *s);

#endif
