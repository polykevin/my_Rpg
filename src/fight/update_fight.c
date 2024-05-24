/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** update fight functions
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include "my.h"
#include "button.h"
#include "game.h"
#include "sprite.h"
#include "fight.h"
#include "win.h"

static double end_of_round(fight_t *fight, game_t *g)
{
    static double accumulator = 0.0;

    if (accumulator != 0.0)
        accumulator += g->delta_time;
    if (accumulator >= 1.0) {
        fight->player_choice = CHOOSING;
        fight->opponent_choice = CHOOSING;
        accumulator = 0.0;
    }
    if (fight->player_choice == CHOOSING) {
        return accumulator;
    }
    win_handle(&accumulator, fight, g);
    return accumulator;
}

void update_fight(fight_t *fight, game_t *g)
{
    double accumulator = end_of_round(fight, g);

    if (accumulator == 0.0) {
        select_animation(&fight->rock, (sfVector2f){0.7, 0.7}, fight, ROCK);
        select_animation(&fight->paper, (sfVector2f){0.6, 0.6}, fight, PAPER);
        select_animation(&fight->cisor,
            (sfVector2f){0.65, 0.65}, fight, CISOR);
        choosing_animation(fight, g);
    }
}
