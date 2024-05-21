/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"

static int free_inventory(Inventory_t *inventory)
{
    if (inventory[0].next == NULL)
        return 0;
    free_inventory(inventory[0].next);
    free(inventory);
    return 0;
}

void destroy_game_menu(G_menu_t *menu)
{
    for (int i = 0; i != 5; i++)
        sfRectangleShape_destroy(BACK[i].back);
    sfFont_destroy(menu->font);
    for (int i = 0; i != 6; i++)
        sfText_destroy(TEXT[i].text);
    free(BACK);
    free(TEXT);
}

void destroy_snow(level_t *level)
{
    sfTexture_destroy(PLAYER.texture);
    sfTexture_destroy(S_MAP.texture);
    sfSprite_destroy(PLAYER.sprite);
    sfSprite_destroy(S_MAP.sprite);
    sfTexture_destroy(level->def_inventory.texture);
    sfSprite_destroy(level->def_inventory.sprite);
    sfRectangleShape_destroy(REC[0].rec);
    free(REC);
    if (level->inventory[0].next != NULL) {
        free_inventory(level->inventory[0].next);
        free(level->inventory);
    }
}
