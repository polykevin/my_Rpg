/*
** EPITECH PROJECT, 2023
** sprite
** File description:
** sprite
*/
#ifndef SPRITE_H
    #define SPRITE_H
typedef struct sprite {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect texture_rect;
}sprite_t;
void sprite_init(sprite_t *s, char *texture);
void sprite_draw(sprite_t *s, sfRenderWindow *window);
void sprite_free(sprite_t *s);
#endif
