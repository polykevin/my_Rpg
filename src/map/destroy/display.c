/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_level.h"

void display_inventory(Inventory_t *inventory, game_t *game)
{
    sfRenderWindow_drawText(WINDOW, inventory[0].name, NULL);
    sfRenderWindow_drawText(WINDOW, inventory[0].number, NULL);
    if (inventory[0].next != NULL)
        return (display_inventory(inventory[0].next, game));
}

void display_game_menu(game_t *game, G_menu_t *menu, level_t *level)
{
    if (menu->on_off == ON) {
        sfRenderWindow_drawRectangleShape(WINDOW, BACK[0].back, NULL);
        sfRenderWindow_drawRectangleShape(WINDOW, BACK[1].back, NULL);
        sfRenderWindow_drawRectangleShape(WINDOW, BACK[2].back, NULL);
        if (menu->bag == ON) {
            sfRenderWindow_drawRectangleShape(WINDOW, BACK[3].back, NULL);
            sfRenderWindow_drawRectangleShape(WINDOW, BACK[4].back, NULL);
            sfRenderWindow_drawText(WINDOW, TEXT[6].text, NULL);
            display_inventory(level->inventory, game);
        }
        for (int i = 0; i != 6; i++)
            sfRenderWindow_drawText(WINDOW, TEXT[i].text, NULL);
    }
}

void display_action(game_t *game, level_t *level)
{
    sfRenderWindow_setView(WINDOW, game->camera);
    sfRenderWindow_drawSprite(WINDOW, S_MAP.sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, PLAYER.sprite, NULL);
    // sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, REC[0].rec, NULL);
}
