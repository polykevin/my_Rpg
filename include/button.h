/*
** EPITECH PROJECT, 2024
** button
** File description:
** button
*/
#ifndef BUTTON_H
    #define BUTTON_H
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/CircleShape.h>
    #include <SFML/Graphics/RectangleShape.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Window/Event.h>

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

button_menu_t *create_button(char *texture_filename);

#endif // !BUTTON_H
