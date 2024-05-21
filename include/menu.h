/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** menu
*/
#ifndef MENU_H
    #define MENU_H
    #define NB_BUTTON 3
    #include "button.h"

typedef struct menu {
    sfTexture *texture;
    sfSprite *sprite;
    button_menu_t **buttons;
    char **texture_filenames;
} menu_t;

void create_menu(menu_t *menu);
void menu_event(menu_t *menu, sfEvent *event);
void update_menu(menu_t *menu);
void destroy_menu(menu_t *menu);

#endif
