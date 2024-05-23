/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** update fight functions
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include "button.h"
#include "game.h"
#include "sprite.h"
#include "fight.h"

static int is_winning(choice_t p1, choice_t p2)
{
    if (p1 == ROCK) {
        if (p2 == PAPER)
            return 0;
        if (p2 == ROCK)
            return 2;
        return 1;
    }
    if (p1 == PAPER) {
        if (p2 == CISOR)
            return 0;
        if (p2 == PAPER)
            return 2;
        return 1;
    }
    if (p1 == CISOR) {
        if (p2 == ROCK)
            return 0;
        if (p2 == CISOR)
            return 2;
        return 1;
    }
    return 0;
}

static void win_handle(double *accumulator, fight_t *fight, game_t *g)
{
    if (*accumulator == 0.0) {
        fight->rock.state = NORMAL;
        fight->paper.state = NORMAL;
        fight->cisor.state = NORMAL;
        if (is_winning(fight->player_choice, fight->opponent_choice) == 1) {
            g->opponent_live -= 30;
        } else {
            g->player_live -= 30;
        }
        if (g->opponent_live <= 0 || g->player_live <= 0)
            g->state = MAP;
        *accumulator += g->delta_time;
    }
}

static void end_of_round(fight_t *fight, game_t *g)
{
    static double accumulator = 0.0;

    if (accumulator != 0.0)
        accumulator += g->delta_time;
    if (accumulator >= 1.0) {
        fight->player_choice = CHOOSING;
        fight->opponent_choice = CHOOSING;
        accumulator = 0.0;
    }
    if (!(fight->opponent_choice != CHOOSING && fight->player_choice != CHOOSING)) {
        return;
    }
    win_handle(&accumulator, fight, g);
}

void update_fight(fight_t *fight, game_t *g)
{
    end_of_round(fight, g);
    select_animation(&fight->rock, (sfVector2f){0.7, 0.7}, fight, ROCK);
    select_animation(&fight->paper, (sfVector2f){0.6, 0.6}, fight, PAPER);
    select_animation(&fight->cisor, (sfVector2f){0.65, 0.65}, fight, CISOR);
    choosing_animation(fight, g);
}

