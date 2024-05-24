/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"
#include "game.h"

void save_stat(main_player_t player)
{
    FILE *file = fopen("data.txt", "w");

    if (file == NULL) {
        perror("Can't open the file");
        exit(84);
    }
    fprintf(file, "Attack\t\t\t  %d\t\t\t", player.attack);
    fprintf(file, "Live\t\t\t\t %d\n\n", player.live);
    fprintf(file, "Attack XP\t\t %d\t\t\t", player.attack_xp);
    fprintf(file, "Money\t\t\t %d\n\n", player.money);
    fprintf(file, "Speed\t\t\t\t %d\n\n", player.speed);
    fprintf(file, "Speed XP\t\t   %d\n\n", player.speed_xp);
    fprintf(file, "Defense\t\t\t%d\n\n", player.defense);
    fprintf(file, "Defense XP\t  %d\n\n", player.defense_xp);
    fclose(file);
}

void load_stat(G_menu_t *menu, game_t *game)
{
    sfVector2f c_pos = sfView_getCenter(game->camera);
    char *content = NULL;

    save_stat(game->player);
    content = open_file("data.txt");
    c_pos.x = c_pos.x - 330;
    c_pos.y = c_pos.y - 100;
    TEXT[7].text = sfText_create();
    sfText_setString(TEXT[7].text, content);
    sfText_setFont(TEXT[7].text, menu->font);
    sfText_setCharacterSize(TEXT[7].text, 30);
    sfText_setPosition(TEXT[7].text, c_pos);
    remove("data.txt");
    free(content);
}

int menu_enter(G_menu_t *menu, level_t *level, game_t *game)
{
    if (menu->menu_nb == 0) {
        menu->bag = ON;
        print_inventory(menu, level, game, SUCCESS);
    }
    if (menu->menu_nb == 1) {
        menu->stat = ON;
        load_stat(menu, game);
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
