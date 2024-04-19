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

typedef struct button_menu {
    sfSprite *sprite;
    sfTexture *texture;
}button_menu_t;

button_menu_t *create_button(char *texture_filename);

#endif // !BUTTON_H
