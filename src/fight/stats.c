/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** fight
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include "stats.h"
#include "button.h"
#include "game.h"
#include "sprite.h"
#include "fight.h"

static int set_stats(int xp)
{
    if (xp == 1)
        return 40;
    if (xp == 2)
        return 80;
    if (xp == 3)
        return 150;
}

static void set_pos_stats(fight_t *fight)
{
    sfSprite_setPosition(fight->fire.sprite, (sfVector2f){169, 50});
    sfSprite_setPosition(fight->defense.sprite, (sfVector2f){169, 130});
    sfSprite_setPosition(fight->other.sprite, (sfVector2f){169, 170});
    sfSprite_setScale(fight->fire.sprite, (sfVector2f){2, 2});
    sfSprite_setScale(fight->defense.sprite, (sfVector2f){2, 2});
    sfSprite_setScale(fight->other.sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(fight->fire2.sprite, (sfVector2f){1559, 50});
    sfSprite_setPosition(fight->defense2.sprite, (sfVector2f){1559, 130});
    sfSprite_setPosition(fight->other2.sprite, (sfVector2f){1559, 170});
    sfSprite_setScale(fight->fire2.sprite, (sfVector2f){2, 2});
    sfSprite_setScale(fight->defense2.sprite, (sfVector2f){2, 2});
    sfSprite_setScale(fight->other2.sprite, (sfVector2f){2, 2});
}

void create_stats(fight_t *fight)
{
    sprite_init(&fight->fire, "resource/fight/ui.png",
        (sfIntRect){230, 0, 0, 40});
    sprite_init(&fight->defense, "resource/fight/ui.png",
        (sfIntRect){230, 40, 40, 20});
    sprite_init(&fight->other, "resource/fight/ui.png",
        (sfIntRect){230, 60, 150, 20});
    sprite_init(&fight->fire2, "resource/fight/ui.png",
        (sfIntRect){230, 0, 150, 40});
    sprite_init(&fight->defense2, "resource/fight/ui.png",
        (sfIntRect){230, 40, 150, 20});
    sprite_init(&fight->other2, "resource/fight/ui.png",
        (sfIntRect){230, 60, 150, 20});
}

void update_stats(sprite_t *element, int y, int x, int y2)
{
    sfSprite_setTextureRect(element->sprite, (sfIntRect){230, y, x, y2});
}

void change_level_speed(main_player_t *player, fight_t *fight)
{
    if (player->speed_xp == 0)
        update_stats(&fight->other, 60, 0, 20);
    if (player->speed_xp == 1)
        update_stats(&fight->other, 60, 40, 20);
    if (player->speed_xp == 2) {
        update_stats(&fight->other, 60, 80, 20);
    }
    if (player->speed_xp > 3) {
        update_stats(&fight->other, 60, 0, 20);
        player->speed++;
    }
}

void change_level_attack(main_player_t *player, fight_t *fight)
{
    if (player->attack_xp == 0)
        update_stats(&fight->fire, 0, 0, 40);
    if (player->attack_xp == 1)
        update_stats(&fight->fire, 0, 40, 40);
    if (player->attack_xp == 2)
        update_stats(&fight->fire, 0, 80, 40);
    if (player->attack_xp == 3)
        update_stats(&fight->fire, 0, 150, 40);
    if (player->attack_xp > 3) {
        update_stats(&fight->fire, 0, 0, 40);
        player->attack++;
    }
    if (player->speed_xp == 3)
        update_stats(&fight->other, 60, 150, 20);
}

void change_level_defense(main_player_t *player, fight_t *fight)
{
    if (player->defense_xp == 0)
        update_stats(&fight->defense, 40, 0, 20);
    if (player->defense_xp == 1)
        update_stats(&fight->defense, 40, 40, 20);
    if (player->defense_xp == 2)
        update_stats(&fight->defense, 40, 80, 20);
    if (player->defense_xp == 3)
        update_stats(&fight->defense, 40, 150, 20);
    if (player->defense_xp > 3) {
        update_stats(&fight->defense, 40, 0, 20);
        player->defense++;
    }
}

void change_level(main_player_t *player, fight_t *fight)
{
    change_level_attack(player, fight);
    change_level_defense(player, fight);
    change_level_speed(player, fight);
    set_pos_stats(fight);
}
