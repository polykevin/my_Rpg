/*
** EPITECH PROJECT, 2024
** menu
** File description:
** menu
*/
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "menu.h"

static void init_texture_filename(menu_t *menu)
{
    menu->texture_filenames[0] = "start.png";
    menu->texture_filenames[1] = "exit.png";
    menu->texture_filenames[2] = "options.png";
}

void create_buttons_menu(menu_t *menu)
{   
    int x = 765;
    int y = 225;

    for (int i = 0; i < 3; i++) {
        menu->buttons[i] = create_button(menu->texture_filenames[i]);
        sfSprite_setScale(menu->buttons[i]->sprite, (sfVector2f){0.5, 0.5});
        sfSprite_setPosition(menu->buttons[i]->sprite, (sfVector2f){x, y});
        y += 200;
    }
}

void update_menu(menu_t *menu)
{
    for (int i = 0; i < 3; i++) {
        switch (menu->buttons[i]->state) {
            case HOVER:
                sfSprite_setColor(menu->buttons[i]->sprite,
                    (sfColor){150, 150, 150, 255});
                break;
            default:
                sfSprite_setColor(menu->buttons[i]->sprite,
                    (sfColor){255, 255, 255, 255});
        }
    }
}

void menu_event(menu_t *menu, sfEvent *event)
{
    for (int i = 0; i < 3; i++) {
        if (menu->buttons[i]->is_clicked(menu->buttons[i],
            &event->mouseButton)) {
            continue;
        }
        if (menu->buttons[i]->is_hover(menu->buttons[i],
            &event->mouseMove)) {
            continue;
        }
    }
}

void create_menu(menu_t *menu)
{
    menu->buttons = malloc(sizeof(button_menu_t *) * 3);
    menu->texture_filenames = malloc(sizeof(char *) * 3);
    menu->texture = sfTexture_createFromFile("sky_menu.png", NULL);
    menu->sprite = sfSprite_create();

    init_texture_filename(menu);
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setScale(menu->sprite, (sfVector2f){8, 8});
    create_buttons_menu(menu);
}
