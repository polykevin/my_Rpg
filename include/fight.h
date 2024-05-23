/*
** EPITECH PROJECT, 2024
** menu
** File description:
** menu
*/
#ifndef FIGHT_H
    #define FIGHT_H
    #include "button.h"
    #include "sprite.h"

typedef enum choice {
    ROCK,
    PAPER,
    CISOR,
    CHOOSING
}choice_t;

typedef struct fight {
    sprite_t scene;
    sprite_t player;
    sprite_t opponent;
    sprite_t skills;
    sprite_t skills2;
    sprite_t bar;
    sprite_t life_player;
    sprite_t life_opponent;
    sprite_t platform1;
    sprite_t platform2;
    button_t rock;
    button_t paper;
    button_t cisor;
    sprite_t life;
    sprite_t life2;
    sprite_t fire;
    sprite_t defense;
    sprite_t other;
    sprite_t fire2;
    sprite_t defense2;
    sprite_t other2;
    sprite_t player_bubble;
    sprite_t opponent_bubble;
    sprite_t opponent_choice_sprite;
    sprite_t player_choice_sprite;
    int opponent_idx;
    choice_t player_choice;
    choice_t opponent_choice;
} fight_t;

void create_fight(fight_t *fight);
void fight_event(fight_t *fight, sfEvent *event);
void update_fight(fight_t *fight, game_t *g);
void choosing_animation(fight_t *fight, game_t *g);
void select_animation(button_t *button, sfVector2f scale,
    fight_t *fight, choice_t choice);
#endif // !FIGHT_H
