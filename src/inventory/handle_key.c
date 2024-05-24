/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"
#include "game.h"

int menu_enter(G_menu_t *menu, level_t *level, game_t *game)
{
    if (menu->menu_nb == 0) {
        menu->bag = ON;
        print_inventory(menu, level, game, SUCCESS);
    }
    if (menu->menu_nb == 3)
        load_file(&game->player, &game->fight);
    if (menu->menu_nb == 4)
        save_file(game->player);
    if (menu->menu_nb == 5)
        return FAIL;
    return (0);
}

void go_down_m(G_menu_t *menu)
{
    sfVector2f c_pos;

    if (menu->menu_nb < 5) {
        c_pos = sfRectangleShape_getPosition(BACK[2].back);
        c_pos.y = c_pos.y + 50;
        sfRectangleShape_setPosition(BACK[2].back, c_pos);
        menu->menu_nb++;
    }
}

void go_up_m(G_menu_t *menu)
{
    sfVector2f c_pos;

    if (menu->menu_nb > 0) {
        c_pos = sfRectangleShape_getPosition(BACK[2].back);
        c_pos.y = c_pos.y - 50;
        sfRectangleShape_setPosition(BACK[2].back, c_pos);
        menu->menu_nb--;
    }
}
