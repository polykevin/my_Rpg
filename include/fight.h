/*
** EPITECH PROJECT, 2024
** menu
** File description:
** menu
*/
#ifndef FIGHT_H
    #define FIGHT_H
    #include "sprite.h"
    #include "game.h"

typedef struct fight {
    sprite_t scene;
    sprite_t player;
    sprite_t opponent;
    sprite_t skills;
    sprite_t life_player;
    sprite_t life_opponent;
    sprite_t platform1;
    sprite_t platform2;
    sprite_t rock;
    sprite_t paper;
    sprite_t cisor;
} fight_t;

void create_fight(fight_t *fight);
#endif // !FIGHT_H
