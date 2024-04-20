/*
** EPITECH PROJECT, 2024
** button
** File description:
** button
*/
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include "button.h"
#include "game.h"
#include "menu.h"

sfBool is_button_clicked(button_menu_t *b, sfMouseButtonEvent *m)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(b->sprite);

    if (m->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&rect, m->x, m->y) &&
    b->state == CLICKED) {
        b->state = NORMAL;
        return sfTrue;
    }
    if (m->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&rect, m->x, m->y)) {
        b->state = CLICKED;
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_button_hover(button_menu_t *b, sfMouseMoveEvent *m)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(b->sprite);

    if (b->state == CLICKED)
        return sfFalse;
    if (m->type == sfEvtMouseMoved &&
        sfFloatRect_contains(&rect, m->x, m->y)) {
        b->state = HOVER;
        return sfTrue;
    }
    b->state = NORMAL;
    return sfFalse;
}

button_menu_t *create_button(char *texture_filename)
{
    button_menu_t *button = malloc(sizeof(button_menu_t));

    button->texture = sfTexture_createFromFile(texture_filename, NULL);
    button->sprite = sfSprite_create();
    button->is_clicked = is_button_clicked;
    button->is_hover = is_button_hover;
    button->state = NORMAL;
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setScale(button->sprite, (sfVector2f){1, 1});
    return button;
}
