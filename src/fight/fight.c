/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** fight
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include "button.h"
#include "game.h"
#include "sprite.h"
#include "fight.h"

static void set_scale(fight_t *fight)
{
    sfSprite_setScale(fight->platform1.sprite, (sfVector2f){3.5, 3.5});
    sfSprite_setScale(fight->platform2.sprite, (sfVector2f){3.5, 3.5});
    sfSprite_setScale(fight->player.sprite, (sfVector2f){15, 15});
    sfSprite_setScale(fight->opponent.sprite, (sfVector2f){-15, 15});
    sfSprite_setScale(fight->life.sprite, (sfVector2f){4, 4});
    sfSprite_setScale(fight->life2.sprite, (sfVector2f){4, 4});
    sfSprite_setScale(fight->paper.sprite.sprite, (sfVector2f){0.6, 0.6});
    sfSprite_setScale(fight->cisor.sprite.sprite, (sfVector2f){0.65, 0.65});
    sfSprite_setScale(fight->rock.sprite.sprite, (sfVector2f){0.7, 0.7});
    sfSprite_setScale(fight->skills.sprite, (sfVector2f){2, 2});
    sfSprite_setScale(fight->skills2.sprite, (sfVector2f){2, 2});
    sfSprite_setScale(fight->bar.sprite, (sfVector2f){2.5, 2.5});
}

static void set_position(fight_t *fight)
{
    sfSprite_setPosition(fight->platform1.sprite, (sfVector2f){350, 700});
    sfSprite_setPosition(fight->platform2.sprite, (sfVector2f){1200, 700});
    sfSprite_setPosition(fight->opponent.sprite, (sfVector2f){1670, 420});
    sfSprite_setPosition(fight->player.sprite, (sfVector2f){-30, 20});
    sfSprite_setPosition(fight->life.sprite, (sfVector2f){450, 430});
    sfSprite_setPosition(fight->life2.sprite, (sfVector2f){1300, 430});
    sfSprite_setPosition(fight->rock.sprite.sprite, (sfVector2f){860, 860});
    sfSprite_setPosition(fight->paper.sprite.sprite, (sfVector2f){980, 860});
    sfSprite_setPosition(fight->cisor.sprite.sprite, (sfVector2f){1100, 860});
    sfSprite_setPosition(fight->skills.sprite, (sfVector2f){10, 50});
    sfSprite_setPosition(fight->skills2.sprite, (sfVector2f){1400, 50});
    sfSprite_setPosition(fight->bar.sprite, (sfVector2f){750, 800});
    sfSprite_setPosition(fight->opponent_choice_sprite.sprite,
        (sfVector2f){1060, 240});
    sfSprite_setPosition(fight->player_choice_sprite.sprite,
        (sfVector2f){860, 240});
}

static void init_player(fight_t *fight)
{
    sprite_init(&fight->player, "resource/player/idle.png",
        (sfIntRect){0, 0, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE});
    sprite_init(&fight->opponent, "resource/player/Skeleton.png",
        (sfIntRect){0, 35, 25, 30});
    sprite_init(&fight->platform1, "resource/fight/platform.png",
        (sfIntRect){0, 0, 128, 32});
    sprite_init(&fight->platform2, "resource/fight/platform.png",
        (sfIntRect){0, 0, 128, 32});
    sprite_init(&fight->life, "resource/fight/h3.png",
        (sfIntRect){0, 0, 64, 16});
    sprite_init(&fight->life2, "resource/fight/h3.png",
        (sfIntRect){0, 0, 64, 16});
    sprite_init(&fight->skills, "resource/fight/ui.png",
        (sfIntRect){0, 0, 220, 90});
    sprite_init(&fight->skills2, "resource/fight/ui.png",
        (sfIntRect){0, 0, 220, 90});
}

static int set_stats(int xp)
{
    if (xp == 1)
        return;
    if (xp == 2)
        return;
    if (xp == 3)
        return;
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

static void create_stats(fight_t *fight)
{
    sprite_init(&fight->fire, "resource/fight/ui.png",
        (sfIntRect){230, 0, 150, 40});
    sprite_init(&fight->defense, "resource/fight/ui.png",
        (sfIntRect){230, 40, 150, 20});
    sprite_init(&fight->other, "resource/fight/ui.png",
        (sfIntRect){230, 60, 150, 20});
    sprite_init(&fight->fire2, "resource/fight/ui.png",
        (sfIntRect){230, 0, 150, 40});
    sprite_init(&fight->defense2, "resource/fight/ui.png",
        (sfIntRect){230, 40, 150, 20});
    sprite_init(&fight->other2, "resource/fight/ui.png",
        (sfIntRect){230, 60, 150, 20});
    set_pos_stats(fight);
}

void fight_event(fight_t *fight, sfEvent *event)
{
    fight->rock.is_clicked(&fight->rock, &event->mouseButton);
    fight->paper.is_clicked(&fight->paper, &event->mouseButton);
    fight->cisor.is_clicked(&fight->cisor, &event->mouseButton);
    fight->rock.is_hover(&fight->rock, &event->mouseMove);
    fight->paper.is_hover(&fight->paper, &event->mouseMove);
    fight->cisor.is_hover(&fight->cisor, &event->mouseMove);
}

static void fight_init(fight_t *fight)
{
    sprite_init(&fight->scene, "resource/fight/scene1.png",
        (sfIntRect){0, 0, 1920, 1080});
    sprite_init(&fight->bar, "resource/fight/ui.png",
        (sfIntRect){0, 80, 220, 100});
    sprite_init(&fight->player_bubble, "resource/fight/bubble.png",
        (sfIntRect){0, 0, 95, 125});
    sprite_init(&fight->opponent_bubble, "resource/fight/bubble.png",
        (sfIntRect){0, 0, 95, 125});
    button_init(&fight->rock, "resource/fight/rock.png",
        (sfIntRect){15, 0, 105, 150});
    button_init(&fight->paper, "resource/fight/rock.png",
        (sfIntRect){122, 0, 108, 150});
    button_init(&fight->cisor, "resource/fight/rock.png",
        (sfIntRect){230, 0, 105, 150});
    sprite_init(&fight->opponent_choice_sprite, "resource/fight/rock.png",
        (sfIntRect){15, 0, 105, 150});
    sprite_init(&fight->player_choice_sprite, "resource/fight/rock.png",
        (sfIntRect){15, 0, 105, 150});
}

void set_attack(fight_t *fight)
{
    sprite_init(&fight->case1, "resource/fight/ui.png",
        (sfIntRect){82, 80, 48, 100});
    sprite_init(&fight->case2, "resource/fight/ui.png",
        (sfIntRect){82, 80, 48, 100});
    sfSprite_setPosition(fight->case1.sprite, (sfVector2f){820, 150});
    sfSprite_setPosition(fight->case2.sprite, (sfVector2f){1020, 150});
    sfSprite_setScale(fight->case1.sprite, (sfVector2f){3.5, 3.5});
    sfSprite_setScale(fight->case2.sprite, (sfVector2f){3.5, 3.5});
}

void create_fight(fight_t *fight)
{
    init_player(fight);
    create_stats(fight);
    fight_init(fight);
    set_attack(fight);
    fight->player.animation_speed = 0.18;
    fight->opponent.animation_speed = 0.18;
    fight->opponent_choice = CHOOSING;
    fight->player_choice = CHOOSING;
    fight->opponent_idx = 0;
    set_position(fight);
    set_scale(fight);
}
