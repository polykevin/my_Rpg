/*
** EPITECH PROJECT, 2024
** menu
** File description:
** menu
*/
#include "menu.h"
#include "my.h"
#include "game.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>

static void init_texture_filename(menu_t *menu)
{
    menu->texture_filenames[0] = "start.png";
    menu->texture_filenames[1] = "exit.png";
    menu->texture_filenames[2] = "options.png";
}

void create_buttons_menu(menu_t *menu, button_menu_t *button)
{
    sfVector2f pos = (sfVector2f){300, 400};

    for (int i = 0; i < 3; i++) {
        menu->buttons[i] = create_button(menu->texture_filenames[i]);
    }
        sfSprite_setPosition(menu->buttons[0]->sprite, (sfVector2f){300, 400});
}

void create_menu(menu_t *menu)
{
    menu->texture = sfTexture_createFromFile("sky_menu.png", NULL);
    menu->sprite = sfSprite_create();

    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setScale(menu->sprite, (sfVector2f){8, 8});
}
