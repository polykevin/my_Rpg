/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"

void start_game_menu_2(G_menu_t *menu, sfVector2f c_pos)
{
    sfText_setPosition(TEXT[1].text, c_pos);
    c_pos.y = c_pos.y + 50;
    sfText_setPosition(TEXT[2].text, c_pos);
    c_pos.y = c_pos.y + 50;
    sfText_setPosition(TEXT[3].text, c_pos);
    c_pos.y = c_pos.y + 50;
    sfText_setPosition(TEXT[4].text, c_pos);
    c_pos.y = c_pos.y + 50;
    sfText_setPosition(TEXT[5].text, c_pos);
}

void set_menu(G_menu_t *menu, sfVector2f c_pos)
{
    c_pos.x = c_pos.x - (WIDTH / 5);
    c_pos.y = c_pos.y - (HEIGHT / 6);
    sfRectangleShape_setPosition(BACK[3].back, c_pos);
    c_pos.x = c_pos.x + 576;
    c_pos.y = c_pos.y - 70;
    sfRectangleShape_setPosition(BACK[4].back, c_pos);
    c_pos.x = c_pos.x + 5;
    c_pos.y = c_pos.y + 10;
    sfText_setPosition(TEXT[6].text, c_pos);
    menu->bag_nb = 0;
}

void start_game_menu(game_t *game, G_menu_t *menu)
{
    sfVector2f c_pos = sfView_getCenter(game->camera);

    set_menu(menu, c_pos);
    menu->menu_nb = 0;
    c_pos.x = c_pos.x - (WIDTH / 2);
    c_pos.y = c_pos.y - (HEIGHT / 2);
    sfRectangleShape_setPosition(BACK[0].back, c_pos);
    c_pos.x = c_pos.x + 5;
    c_pos.y = c_pos.y + 5;
    sfRectangleShape_setPosition(BACK[1].back, c_pos);
    c_pos.x = c_pos.x + 1;
    c_pos.y = c_pos.y + 1;
    sfRectangleShape_setPosition(BACK[2].back, c_pos);
    c_pos.x = c_pos.x + 20;
    c_pos.y = c_pos.y + 5;
    sfText_setPosition(TEXT[0].text, c_pos);
    c_pos.y = c_pos.y + 50;
    start_game_menu_2(menu, c_pos);
}
