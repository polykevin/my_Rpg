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

static int is_winning2(choice_t p1, choice_t p2)
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
    return 3;
}

static int is_winning(choice_t p1, choice_t p2)
{
    int ret = 0;

    ret = is_winning2(p1, p2);
    if (ret != 3)
        return ret;
    if (p1 == CISOR) {
        if (p2 == ROCK)
            return 0;
        if (p2 == CISOR)
            return 2;
        return 1;
    }
    return 0;
}

static void update_life2(sprite_t *life, fight_t *fight, int life_nb)
{
    if (life_nb == 2) {
        sfSprite_setTexture(life->sprite,
            fight->live_texture[TWO_HEART], sfTrue);
    }
    if (life_nb == 3) {
        sfSprite_setTexture(life->sprite,
            fight->live_texture[THREE_HEART], sfTrue);
    }
    if (life_nb == 4) {
        sfSprite_setTexture(life->sprite,
            fight->live_texture[FOUR_HEART], sfTrue);
    }
}

static void update_life(sprite_t *life, fight_t *fight, int life_nb)
{
    if (life_nb == 0) {
        sfSprite_setTexture(life->sprite,
            fight->live_texture[DEATH], sfTrue);
    }
    if (life_nb == 1) {
        sfSprite_setTexture(life->sprite,
            fight->live_texture[ONE_HEART], sfTrue);
    }
    update_life2(life, fight, life_nb);
}

static void loose_handle_player(fight_t *fight, game_t *g)
{
    if (g->player.live <= 0) {
        for (int i = 0; i < 12; i++) {
            g->tab_ennemy[i]->dead = false;
        }
        g->player.money = 0;
        g->player.live = 4;
        g->opponent_live = 4;
        g->player.money_str = my_int_to_str(g->player.money);
        sfText_setString(g->player.money_text.text_obj,
            g->player.money_str);
        update_life(&g->player.life_sprite, fight, g->player.live);
        update_life(&fight->life, fight, g->player.live);
        update_life(&fight->life2, fight, g->opponent_live);
    }
}

static void loose_handle(fight_t *fight, game_t *g)
{
    if (g->opponent_live <= 0 || g->player.live <= 0) {
        if (g->opponent_live <= 0) {
            g->player.money += 5;
            g->player.money_str = my_int_to_str(g->player.money);
            sfText_setString(g->player.money_text.text_obj,
                g->player.money_str);
            g->tab_ennemy[g->fight.opponent_idx]->dead = true;
            g->opponent_live = 4;
            update_life(&fight->life, fight, g->player.live);
            update_life(&fight->life2, fight, g->opponent_live);
            if (fight->opponent_idx >= 0 && fight->opponent_idx <= 2)
                g->player.speed_xp++;
            if (fight->opponent_idx >= 3 && fight->opponent_idx <= 5)
                g->player.defense_xp++;
            if (fight->opponent_idx >= 6 && fight->opponent_idx <= 8)
                g->player.attack_xp++;
            change_level(&g->player, fight);
        }
        loose_handle_player(fight, g);
        g->state = MAP;
    }
}

static void win_handle2(fight_t *fight, game_t *g)
{
    if (is_winning(fight->player_choice, fight->opponent_choice) == 1) {
        g->opponent_live -= g->player.attack;
        update_life(&fight->life2, fight, g->opponent_live);
    }
    if (is_winning(fight->player_choice, fight->opponent_choice) == 0){
        g->player.live--;
        update_life(&fight->life, fight, g->player.live);
        update_life(&g->player.life_sprite, fight, g->player.live);
    }
    loose_handle(fight, g);
}

static void win_handle(double *accumulator, fight_t *fight, game_t *g)
{
    if (*accumulator == 0.0) {
        fight->rock.state = NORMAL;
        fight->paper.state = NORMAL;
        fight->cisor.state = NORMAL;
        win_handle2(fight, g);
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
    if (fight->player_choice == CHOOSING) {
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
