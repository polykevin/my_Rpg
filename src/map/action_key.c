/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"


static void inventory_off(level_t *level, game_t *g, G_menu_t *menu)
{
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyS))
        map_movement(level, g, 1);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyW))
        map_movement(level, g, 2);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyA))
        map_movement(level, g, 3);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyD))
        map_movement(level, g, 4);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyB)) {
        wait_x_sec(0.1);
        menu->on_off = ON;
        start_game_menu(g, menu);
    }
}

static void effect(game_t *game, int id)
{
    if (id == 1)
        game->player.live = 4;
    if (id == 2)
        game->player.attack++;
    if (id == 3)
        game->player.defense++;
    if (id == 4)
        game->player.speed++;
}

static int more_down(Inventory_t *inventory, int nb)
{
    if (inventory[0].next == NULL || nb == 0) {
        if (nb != 0)
            return FAIL;
        return SUCCESS;
    }
    return (more_down(inventory[0].next, nb - 1));
}

static void inventory_down(G_menu_t *menu, level_t *level)
{
    sfVector2f c_pos = sfRectangleShape_getPosition(BACK[5].back);

    if (more_down(level->inventory, menu->bag_nb + 1) == FAIL)
        return;
    c_pos.y = c_pos.y + 50;
    sfRectangleShape_setPosition(BACK[5].back, c_pos);
    menu->bag_nb++;
}

static void inventory_up(G_menu_t *menu)
{
    sfVector2f c_pos = sfRectangleShape_getPosition(BACK[5].back);

    if (menu->bag_nb <= 0)
        return;
    c_pos.y = c_pos.y - 50;
    sfRectangleShape_setPosition(BACK[5].back, c_pos);
    menu->bag_nb--;
}

static int object_effect(Inventory_t *inventory, int nb,
    game_t *game, Inventory_t *last)
{
    if (nb != 1)
        return (object_effect(inventory[0].next, nb - 1, game, inventory));
    inventory[0].nb = inventory[0].nb - 1;
    effect(game, inventory->id);
    if (inventory[0].nb == 0) {
        sfText_destroy(INV[0].name);
        sfText_destroy(INV[0].number);
        last[0].next = inventory->next;
        free(inventory);
        return (FAIL);
    }
    return 0;
}

static void use_object(G_menu_t *menu, level_t *level, game_t *g)
{
    if (menu->bag_nb == 0)
        return;
    if (object_effect(level->inventory[0].next, menu->bag_nb,
    g, level->inventory) == FAIL)
        inventory_up(menu);
    destroy_inventory(level->inventory);
    print_inventory(menu, level, g, FAIL);
    update_life(&g->player.life_sprite, &g->fight, g->player.live);
    update_life(&g->fight.life, &g->fight, g->player.live);
    update_life(&g->fight.life2, &g->fight, g->opponent_live);
    wait_x_sec(0.3);
}

static int inventory(G_menu_t *menu, level_t *level, game_t *game)
{
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEscape)) {
        menu->bag = OFF;
        menu->bag_nb = 0;
        destroy_inventory(level->inventory);
        wait_x_sec(0.3);
    }
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEnter)) {
        use_object(menu, level, game);
        wait_x_sec(0.05);
    }
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyDown)) {
        inventory_down(menu, level);
        wait_x_sec(0.2);
    }
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyUp)) {
        inventory_up(menu);
        wait_x_sec(0.2);
    }
    return 0;
}

static int stat(G_menu_t *menu)
{
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfText_destroy(TEXT[7].text);
        menu->stat = OFF;
    }
    return 0;
}

int inventory_on(G_menu_t *menu, level_t *level, game_t *game)
{
    if (menu->bag == ON)
        return (inventory(menu, level, game));
    if (menu->stat == ON)
        return (stat(menu));
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEscape)) {
        menu->on_off = OFF;
    }
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyUp)) {
        go_up_m(menu);
        wait_x_sec(0.15);
    }
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyDown)) {
        go_down_m(menu);
        wait_x_sec(0.15);
    }
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEnter))
        return (menu_enter(menu, level, game));
    return (0);
}
