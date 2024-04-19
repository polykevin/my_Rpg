/*
** EPITECH PROJECT, 2024
** menu
** File description:
** menu
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "menu.h"
#include "my.h"
#include "game.h"

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
