/*
** EPITECH PROJECT, 2024
** textbox
** File description:
** textbox
*/
#ifndef TEXTBOX_H
    #define TEXTBOX_H
typedef struct textbox {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    text_t text;
}textbox_t;
void textbox_create(textbox_t *textbox, game_t *g, char *msg);
#endif // !TEXTBOX_H
