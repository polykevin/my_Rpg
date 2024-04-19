/*
** EPITECH PROJECT, 2024
** button
** File description:
** button
*/
#ifndef BUTTON_H
    #define BUTTON_H
typedef enum {
    HOVER,
    PRESSED,
    CLICKED,
    NORMAL
}state_t;
typedef struct button {
    sfRectangleShape *rect;
    sfTexture *image;
    state_t state;
    sfBool (*is_clicked)(struct button *b, sfMouseButtonEvent *m);
    sfBool (*is_pressed)(struct button *b, sfMouseButtonEvent *m);
    sfBool (*is_hover)(struct button *b, sfMouseMoveEvent *m);
}button_t;
button_t *init_button(sfVector2f position, sfVector2f size, char *filename);
void free_button(button_t *button);
sfBool is_button_hover(button_t *b, sfMouseMoveEvent *m);
sfBool is_button_clicked(button_t *b, sfMouseButtonEvent *m);
sfBool is_button_pressed(button_t *b, sfMouseButtonEvent *m);
#endif // !BUTTON_H
