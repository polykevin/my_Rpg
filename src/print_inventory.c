/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"

void create_text(G_menu_t *menu, Inventory_t *inventory)
{
    INV[0].name = sfText_create();
    sfText_setString(INV[0].name, const_inventory[INV[0].id]);
    sfText_setFont(INV[0].name, menu->font);
    sfText_setCharacterSize(INV[0].name, 30);
    INV[0].number = sfText_create();
    sfText_setString(INV[0].number, "XX");
    sfText_setFont(INV[0].number, menu->font);
    sfText_setCharacterSize(INV[0].number, 30);
    if (INV[0].next != NULL)
        return (create_text(menu, INV[0].next));
}

void pos_text(Inventory_t *inventory, sfVector2f c_pos)
{
    sfText_setPosition(INV[0].name, c_pos);
    c_pos.x = c_pos.x + 50;
    sfText_setPosition(INV[0].number, c_pos);
    c_pos.x = c_pos.x - 50;
    c_pos.y = c_pos.y + 50;
    if (INV[0].next != NULL)
        return (pos_text(INV[0].next, c_pos));
}

void print_inventory(G_menu_t *menu, level_t *level, game_t *game)
{
    sfVector2f c_pos = sfView_getCenter(game->camera);

    create_text(menu, level->inventory);
    pos_text(level->inventory, c_pos);
}

void destroy_inventory(Inventory_t *inventory)
{
    sfText_destroy(INV[0].name);
    sfText_destroy(INV[0].number);
    if (INV[0].next != NULL)
        return (destroy_inventory(INV[0].next));
}
