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
    sfRectangleShape *rect;
    sfVector2f pos;
    button_t *buttons[NB_BUTTON];
    char *texture_filenames[NB_BUTTON];
}menu_t;
menu_t *init_menu(sfVector2f *pos);
void draw_menu(menu_t *menu, sfRenderWindow *window);
void menu_event(menu_t *menu, sfEvent *event);
void update_menu(menu_t *menu);
void free_menu(menu_t *menu);
#endif // !MENU_H
