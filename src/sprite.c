/*
** EPITECH PROJECT, 2023
** sprite
** File description:
** sprite
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "sprite.h"
#include "game.h"

void sprite_init(sprite_t *s, char *texture, sfIntRect rect)
{
    s->texture = sfTexture_createFromFile(texture, NULL);
    s->sprite = sfSprite_create();
    s->texture_rect = rect;
    s->draw = true;
    s->animation_speed = 0.1;
    sfSprite_setTexture(s->sprite, s->texture, sfTrue);
    sfSprite_setTextureRect(s->sprite, s->texture_rect);
}

void sprite_draw(sprite_t *s, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, s->sprite, NULL);
}

void sprite_animation(sprite_t *s, game_t *g, int offset, int max)
{
    if (s->accumulator >= s->animation_speed) {
        s->texture_rect.left += offset;
        if (s->texture_rect.left < max) {
            sfSprite_setTextureRect(s->sprite, s->texture_rect);
        }
        s->accumulator = 0;
    }
    if (s->texture_rect.left >= max) {
        s->texture_rect.left = 0;
    }
    s->accumulator += g->delta_time;
}

void sprite_free(sprite_t *s)
{
    sfSprite_destroy(s->sprite);
    sfTexture_destroy(s->texture);
}
