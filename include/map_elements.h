/*
** EPITECH PROJECT, 2024
** elements
** File description:
** elements
*/
#ifndef ELEMENT_H
    #define ELEMENT_H
    #include "sprite.h"

typedef struct element {
    sprite_t well;
} element_t;

void ennemy_init(game_t *g);
void well(element_t *element);

#endif // !ELEMENT_H
