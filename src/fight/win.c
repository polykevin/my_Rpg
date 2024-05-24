/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** win functions
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

int is_winning(choice_t p1, choice_t p2)
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
    if (life_nb >= 4) {
        sfSprite_setTexture(life->sprite,
            fight->live_texture[FOUR_HEART], sfTrue);
    }
}

void update_life(sprite_t *life, fight_t *fight, int life_nb)
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

static void level_up(fight_t *fight, game_t *g)
{
    if (fight->opponent_idx >= 0 && fight->opponent_idx <= 2)
        g->player.speed_xp++;
    if (fight->opponent_idx >= 3 && fight->opponent_idx <= 5)
        g->player.defense_xp++;
    if (fight->opponent_idx >= 6 && fight->opponent_idx <= 8) {
        g->player.attack_xp++;
    }
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
        sfSprite_setPosition(g->player.player_sprite.sprite,
            (sfVector2f){MAP_WIDTH * 1.87, MAP_HEIGHT * 1.75});
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
            update_life(&fight->life, fight, g->player.live);
            g->opponent_live = 4;
            update_life(&fight->life2, fight, g->opponent_live);
            level_up(fight, g);
            change_level(&g->player, &g->fight);
        }
        loose_handle_player(fight, g);
        g->state = MAP;
        wait_x_sec(0.1);
    }
}

static void win_handle2(fight_t *fight, game_t *g)
{
    int total = g->opponent_attack - g->player.defense;
    int total_opp = g->player.attack - g->opponent_defense;

    if (total <= 0)
        total = 1;
    if (total_opp <= 0)
        total_opp = 1;
    if (is_winning(fight->player_choice, fight->opponent_choice) == 1) {
        g->opponent_live -= total_opp;
        update_life(&fight->life, fight, g->player.live);
        update_life(&fight->life2, fight, g->opponent_live);
    }
    if (is_winning(fight->player_choice, fight->opponent_choice) == 0){
        g->player.live -= total;
        update_life(&fight->life, fight, g->player.live);
        update_life(&fight->life2, fight, g->opponent_live);
        update_life(&g->player.life_sprite, fight, g->player.live);
    }
    loose_handle(fight, g);
}

void win_handle(double *accumulator, fight_t *fight, game_t *g)
{
    if (*accumulator == 0.0) {
        fight->rock.state = NORMAL;
        fight->paper.state = NORMAL;
        fight->cisor.state = NORMAL;
        win_handle2(fight, g);
        *accumulator += g->delta_time;
    }
}
