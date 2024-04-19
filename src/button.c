/*
** EPITECH PROJECT, 2024
** button
** File description:
** button
*/
#include "button.h"
#include "game.h"
#include "menu.h"

button_menu_t *create_button(char **texture_filename)
{
    button_menu_t *button = malloc(sizeof(button_menu_t));

    button->texture = sfTexture_createFromFile(texture_filename, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setScale(button->sprite, (sfVector2f){1, 1});
    return button;
}
