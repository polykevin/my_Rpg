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
#include "struct.h"

void sprite_init(sprite_t *s, char *texture)
{
    s->texture = sfTexture_createFromFile(texture, NULL);
    s->sprite = sfSprite_create();
    s->texture_rect = (sfIntRect){0, 0, 80, 80};
    sfSprite_setTexture(s->sprite, s->texture, sfTrue);
    sfSprite_setTextureRect(s->sprite, s->texture_rect);
    sfSprite_setScale(s->sprite, (sfVector2f){4, 4});
}

void sprite_draw(sprite_t *s, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, s->sprite, NULL);
}

void sprite_animation(sprite_t *s)
{
    if (s->texture_rect.left < 320) {
        s->texture_rect.left += 80;
        sfSprite_setTextureRect(s->sprite, s->texture_rect);
    } else {
        s->texture_rect.left = 0;
    }
}

void sprite_free(sprite_t *s)
{
    sfSprite_destroy(s->sprite);
    sfTexture_destroy(s->texture);
}
