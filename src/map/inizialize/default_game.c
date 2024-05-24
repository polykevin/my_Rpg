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

void default_game(level_t *level, G_menu_t *menu)
{
    level->inventory = malloc(sizeof(level->inventory[0]) * 1);
    level->inventory[0].id = 0;
    level->inventory[0].nb = 5;
    level->inventory[0].next = NULL;
    level->inventory[0].next = malloc(sizeof(level->inventory[0]) * 1);
    level->inventory[0].next[0].id = 1;
    level->inventory[0].next[0].nb = 10;
    level->inventory[0].next[0].next = NULL;
    level->player.exp = 0;
    level->player.max_exp = 10;
    level->player.hp = 200;
    level->player.hp_max = 200;
    level->player.gold = 200;
    menu->bag_nb = 0;
    inizialize_obj(level, "./resource/items/bag.png");
}
