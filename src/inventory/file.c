/*
** EPITECH PROJECT, 2024
** tail
** File description:
** main file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "snow_header.h"

int add_struct_2(main_player_t *player, char *token)
{
    if (strcmp(token, "Attack XP") == 0) {
        player->attack_xp = atoi(strtok(NULL, "\n"));
        return 0;
    }
    if (strcmp(token, "Defense XP") == 0) {
        player->defense_xp = atoi(strtok(NULL, "\n"));
        return 0;
    }
    if (strcmp(token, "Speed XP") == 0) {
        player->speed_xp = atoi(strtok(NULL, "\n"));
        return 0;
    }
    if (strcmp(token, "Money") == 0) {
        player->money = atoi(strtok(NULL, "\n"));
        return 0;
    }
    return 1;
}

int add_struct(main_player_t *player, char *token)
{
    if (strcmp(token, "Live") == 0) {
        player->live = atoi(strtok(NULL, "\n"));
        return 0;
    }
    if (strcmp(token, "Attack") == 0) {
        player->attack = atoi(strtok(NULL, "\n"));
        return 0;
    }
    if (strcmp(token, "Defense") == 0) {
        player->defense = atoi(strtok(NULL, "\n"));
        return 0;
    }
    if (strcmp(token, "Speed") == 0) {
        player->speed = atoi(strtok(NULL, "\n"));
        return 0;
    }
    return (add_struct_2(player, token));
}

char *load_data(main_player_t *player, fight_t *fight, char **file)
{
    char *token = NULL;

    for (int i = 0; file[i] != NULL; i++) {
        token = strtok(file[i], ":");
        if (add_struct(player, token) == 1)
            return ("corrupt file");
    }
    player->money_str = my_int_to_str(player->money);
    sfText_setString(player->money_text.text_obj,
        player->money_str);
    update_life(&player->life_sprite, fight, player->live);
    update_life(&player->life_sprite, fight, player->live);
    update_life(&fight->life, fight, player->live);
    update_life(&fight->life2, fight, 4);
    free_array(file);
    return ("Load complete");
}

char *load_file(main_player_t *player, fight_t *fight)
{
    char *temp = open_file("save.txt");
    char **file = NULL;
    int x = 0;

    if (temp == NULL)
        return ("Any game save");
    file = strtok_to_word_array(temp, "\n");
    for (int i = 0; file[i] != NULL; i++)
        x++;
    free(temp);
    if (x != 8) {
        free_array(file);
        return ("corrupt file");
    }
    return (load_data(player, fight, file));
}

void save_file(main_player_t player)
{
    FILE *file = fopen("save.txt", "w");

    if (file == NULL) {
        perror("Can't open the file");
        exit(84);
    }
    fprintf(file, "Live: %d\n", player.live);
    fprintf(file, "Attack: %d\n", player.attack);
    fprintf(file, "Defense: %d\n", player.defense);
    fprintf(file, "Speed: %d\n", player.speed);
    fprintf(file, "Attack XP: %d\n", player.attack_xp);
    fprintf(file, "Defense XP: %d\n", player.defense_xp);
    fprintf(file, "Speed XP: %d\n", player.speed_xp);
    fprintf(file, "Money: %d\n", player.money);
    fclose(file);
}
