/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** collisions functions
*/
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>
#include <stdbool.h>
#include "player_movement.h"
#include "game.h"
#include "sprite.h"
#include "utils.h"

static void entity_collision3(game_t *g,
    player_state_t state, sfVector2f *player_pos)
{
    if (state == UP) {
        sfSprite_setPosition(g->player.player_sprite.sprite,
            (sfVector2f){player_pos->x, player_pos->y + PLAYER_SPEED});
    }
    if (state == DOWN) {
        sfSprite_setPosition(g->player.player_sprite.sprite,
            (sfVector2f){player_pos->x, player_pos->y - PLAYER_SPEED});
    }
    if (state == RIGHT) {
        sfSprite_setPosition(g->player.player_sprite.sprite,
            (sfVector2f){player_pos->x - PLAYER_SPEED, player_pos->y});
    }
    if (state == LEFT) {
        sfSprite_setPosition(g->player.player_sprite.sprite,
            (sfVector2f){player_pos->x + PLAYER_SPEED, player_pos->y});
    }
}

static void entity_collision2(sfFloatRect *entity, sfFloatRect *player,
    game_t *g, player_state_t state)
{
    sfVector2f player_pos =
        sfSprite_getPosition(g->player.player_sprite.sprite);

    if (sfFloatRect_intersects(entity, player, NULL)) {
        entity_collision3(g, state, &player_pos);
    }
}

void entity_collision(game_t *g, player_state_t state)
{
    sfFloatRect entity;
    sfFloatRect player =
        sfSprite_getGlobalBounds(g->player.player_sprite.sprite);

    player.left -= 88;
    player.top -= 88;
    player.width -= 88;
    player.height -= 88;
    for (int i = 0; i < 12; i++) {
        if (g->tab_ennemy[i]->dead)
            continue;
        entity = sfSprite_getGlobalBounds(g->tab_ennemy[i]->sprite);
        if ((i >= 6 && i <= 8) || (i >= 9 && i <= 11)) {
            entity.left -= 140;
            entity.top -= 140;
            entity.width -= 140;
            entity.height -= 140;
        }
        entity_collision2(&entity, &player, g, state);
    }
}
