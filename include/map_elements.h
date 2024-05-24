/*
** EPITECH PROJECT, 2024
** elements
** File description:
** elements
*/
#ifndef ELEMENT_H
    #define ELEMENT_H
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/Rect.h>
    #include "sprite.h"

typedef struct element {
    sprite_t well;
    sfText *text;
    sfFont *font;
    bool draw;
} element_t;

void ennemy_init(game_t *g);
void well(element_t *element);
void interact_well(game_t *g);

#endif // !ELEMENT_H
