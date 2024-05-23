/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** button
*/
#ifndef BUTTON_H
    #define BUTTON_H
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/CircleShape.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/RectangleShape.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Window/Event.h>
    #include "sprite.h"

typedef enum {
    HOVER,
    PRESSED,
    CLICKED,
    NORMAL
}state_t;

typedef struct button_menu {
    sfSprite *sprite;
    sfTexture *texture;
    state_t state;
    sfBool (*is_clicked)(struct button_menu *b, sfMouseButtonEvent *m);
    sfBool (*is_hover)(struct button_menu *b, sfMouseMoveEvent *m);
}button_menu_t;

typedef struct button {
    sprite_t sprite;
    state_t state;
    sfBool (*is_clicked)(struct button *b, sfMouseButtonEvent *m);
    sfBool (*is_hover)(struct button *b, sfMouseMoveEvent *m);
}button_t;

button_menu_t *create_button(char *texture_filename);
void button_init(button_t *button, char *texture, sfIntRect rect);
void destroy_button(button_menu_t *button);
void free_button(button_t *button);

#endif // !BUTTON_H
