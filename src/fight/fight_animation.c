/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** fight animation
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include "button.h"
#include "sprite.h"
#include "fight.h"
#include "game.h"

static void change_choice_sprite2(fight_t *fight, choice_t choice)
{
    if (choice == ROCK) {
        sfSprite_setTexture(fight->player_choice_sprite.sprite,
            fight->rock.sprite.texture, sfTrue);
        sfSprite_setTextureRect(fight->player_choice_sprite.sprite,
            (sfIntRect){15, 0, 105, 150});
        sfSprite_setScale(fight->player_choice_sprite.sprite,
            (sfVector2f){1, 1});
    }
    if (choice == PAPER) {
        sfSprite_setTexture(fight->player_choice_sprite.sprite,
            fight->paper.sprite.texture, sfTrue);
        sfSprite_setTextureRect(fight->player_choice_sprite.sprite,
            (sfIntRect){122, 0, 108, 150});
        sfSprite_setScale(fight->player_choice_sprite.sprite,
            (sfVector2f){0.8, 0.8});
    }
}

static void change_choice_sprite(fight_t *fight, choice_t choice)
{
    change_choice_sprite2(fight, choice);
    if (choice == CISOR) {
        sfSprite_setTexture(fight->player_choice_sprite.sprite,
            fight->cisor.sprite.texture, sfTrue);
        sfSprite_setTextureRect(fight->player_choice_sprite.sprite,
            (sfIntRect){230, 0, 105, 150});
        sfSprite_setScale(fight->player_choice_sprite.sprite,
            (sfVector2f){0.8, 0.8});
    }
}

void select_animation(button_t *button, sfVector2f scale,
    fight_t *fight, choice_t choice)
{
    switch (button->state) {
        case HOVER:
            sfSprite_setScale(button->sprite.sprite, (sfVector2f){1.15, 1.15});
            break;
        case CLICKED:
            fight->player_choice = choice;
            change_choice_sprite(fight, choice);
            break;
        default:
            sfSprite_setScale(button->sprite.sprite, scale);
    }
}

static void case_rock_and_paper(fight_t *fight, double choice)
{
    if (choice >= 0 && choice < 1) {
        sfSprite_setTexture(fight->opponent_choice_sprite.sprite,
            fight->rock.sprite.texture, sfTrue);
        sfSprite_setTextureRect(fight->opponent_choice_sprite.sprite,
            (sfIntRect){15, 0, 105, 150});
        sfSprite_setScale(fight->opponent_choice_sprite.sprite,
            (sfVector2f){1, 1});
        fight->opponent_choice = ROCK;
    }
    if (choice >= 1 && choice < 2) {
        sfSprite_setTexture(fight->opponent_choice_sprite.sprite,
            fight->paper.sprite.texture, sfTrue);
        sfSprite_setTextureRect(fight->opponent_choice_sprite.sprite,
            (sfIntRect){122, 0, 108, 150});
        sfSprite_setScale(fight->opponent_choice_sprite.sprite,
            (sfVector2f){0.8, 0.8});
        fight->opponent_choice = PAPER;
    }
}

static void change_sprite(fight_t *fight, game_t *g)
{
    static double choice = 0.0;

    case_rock_and_paper(fight, choice);
    if (choice >= 2 && choice < 3) {
        sfSprite_setTexture(fight->opponent_choice_sprite.sprite,
            fight->cisor.sprite.texture, sfTrue);
        sfSprite_setTextureRect(fight->opponent_choice_sprite.sprite,
            (sfIntRect){230, 0, 105, 150});
        sfSprite_setScale(fight->opponent_choice_sprite.sprite,
            (sfVector2f){0.8, 0.8});
        fight->opponent_choice = CISOR;
    }
    if (choice >= 3)
        choice = 0.0;
    choice += g->delta_time * 8;
}

void choosing_animation(fight_t *fight, game_t *g)
{
    if (fight->player_choice == CHOOSING) {
        change_sprite(fight, g);
    }
}
