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

static void effect(level_t *level, int id)
{
    if (id == 1) {
        level->player.hp = level->player.hp_max;
    }
}

static int more_down(Inventory_t *inventory, int nb)
{
    if (inventory[0].next == NULL) {
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
    level_t *level, Inventory_t *last)
{
    if (nb != 1)
        return (object_effect(inventory[0].next, nb - 1, level, inventory));
    inventory[0].nb = inventory[0].nb - 1;
    effect(level, inventory->id);
    if (inventory[0].nb == 0) {
        sfText_destroy(INV[0].name);
        sfText_destroy(INV[0].number);
        last[0].next = inventory->next;
        free(inventory);
        return (FAIL);
    }
    return 0;
}

static void use_object(G_menu_t *menu, level_t *level, game_t *game)
{
    if (menu->bag_nb == 0)
        return;
    if (object_effect(level->inventory[0].next, menu->bag_nb,
    level, level->inventory) == FAIL)
        inventory_up(menu);
    destroy_inventory(level->inventory);
    print_inventory(menu, level, game, FAIL);
    wait_x_sec(0.3);
}

static int inventory(G_menu_t *menu, level_t *level, game_t *game)
{
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEscape)) {
        menu->bag = OFF;
        destroy_inventory(level->inventory);
        wait_x_sec(0.3);
    }
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEnter)) {
        use_object(menu, level, game);
        wait_x_sec(0.05);
    }
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyDown)) {
        inventory_down(menu, level);
        wait_x_sec(0.05);
    }
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyUp)) {
        inventory_up(menu);
        wait_x_sec(0.05);
    }
    return 0;
}

int inventory_on(G_menu_t *menu, level_t *level, game_t *game)
{
    if (menu->bag == ON)
        return (inventory(menu, level, game));
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

int run_action(level_t *level, game_t *game, G_menu_t *menu)
{
    game_handle_time(game);
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (menu->on_off == OFF)
        inventory_off(level, game, menu);
    else
        return (inventory_on(menu, level, game));
    return (0);
}
