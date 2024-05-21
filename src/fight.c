/*
** EPITECH PROJECT, 2024
** fight
** File description:
** fight
*/
#include "game.h"
#include "fight.h"

void create_fight(fight_t *fight)
{
    sprite_init(&fight->scene, "scene1.png",
        (sfIntRect){0, 0, 1920, 1080});
    sprite_init(&fight->platform1, "resource/platform.png",
        (sfIntRect){0, 0, 128, 32});
    sprite_init(&fight->platform2, "resource/platform.png",
        (sfIntRect){0, 0, 128, 32});
    sprite_init(&fight->player, "resource/player/idle.png",
        (sfIntRect){0, 0, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE});
    sprite_init(&fight->opponent, "resource/player/Skeleton.png",
        (sfIntRect){0, 35, 25, 30});
    fight->player.animation_speed = 0.48;
    set_size(fight);
}

void set_size(fight_t *fight)
{
    sfSprite_setScale(fight->platform1.sprite, (sfVector2f){3.5, 3.5});
    sfSprite_setScale(fight->platform2.sprite, (sfVector2f){3.5, 3.5});
    sfSprite_setScale(fight->player.sprite, (sfVector2f){15, 15});
    sfSprite_setScale(fight->opponent.sprite, (sfVector2f){-15, 15});
    sfSprite_setPosition(fight->platform1.sprite, (sfVector2f){350, 700});
    sfSprite_setPosition(fight->platform2.sprite, (sfVector2f){1200, 700});
    sfSprite_setPosition(fight->opponent.sprite, (sfVector2f){1670, 420});
    sfSprite_setPosition(fight->player.sprite, (sfVector2f){-30, 20});
}
