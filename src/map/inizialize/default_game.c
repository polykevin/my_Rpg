/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"
#include "game.h"

static void inizialize_obj(level_t *level, char *img)
{
    level->def_inventory.texture = sfTexture_createFromFile(img, NULL);
    level->def_inventory.sprite = sfSprite_create();
    sfSprite_setTexture(level->def_inventory.sprite,
    level->def_inventory.texture, sfTrue);
}

static void add_item(Inventory_t *inventory, int id, int nb)
{
    if (inventory[0].next != NULL)
        return add_item(inventory[0].next, id, nb);
    inventory[0].next = malloc(sizeof(Inventory_t));
    inventory[0].next->id = id;
    inventory[0].next->nb = nb;
    inventory[0].next[0].next = NULL;
}

void default_game(level_t *level, G_menu_t *menu)
{
    level->inventory = malloc(sizeof(level->inventory[0]) * 1);
    level->inventory[0].id = 0;
    level->inventory[0].nb = 1;
    level->inventory[0].next = NULL;
    add_item(level->inventory, 1, 5);
    add_item(level->inventory, 2, 5);
    add_item(level->inventory, 3, 5);
    add_item(level->inventory, 4, 5);
    menu->bag_nb = 0;
    menu->stat = OFF;
    inizialize_obj(level, "./resource/items/bag.png");
}
