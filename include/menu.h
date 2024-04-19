/*
** EPITECH PROJECT, 2024
** menu
** File description:
** menu
*/
#ifndef MENU_H
    #define MENU_H
    #define NB_BUTTON 4
    #include "button.h"

typedef struct menu {
    sfTexture *texture;
    sfSprite *sprite;
    button_menu_t **buttons;
    char **texture_filenames;
} menu_t;

void create_menu(menu_t *menu);

#endif // !MENU_H
