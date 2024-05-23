/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** interact with enemies
*/
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>
#include "interact.h"
#include "game.h"
#include "sprite.h"
#include "utils.h"

static void enemy_init(sfFloatRect *enemy, game_t *g, int i,
    sfVector2f *enemy_pos)
{
    *enemy = sfSprite_getGlobalBounds(g->tab_ennemy[i]->sprite);
    *enemy_pos = sfSprite_getPosition(g->tab_ennemy[i]->sprite);
}

static bool check_enemies(game_t *g, sfFloatRect *player,
    vec2_double_t *vec, int *idx)
{
    sfFloatRect enemy;
    sfVector2f enemy_pos;

    for (int i = 0; i < 12; i++) {
        enemy_init(&enemy, g, i, &enemy_pos);
        if (sfFloatRect_intersects(player, &enemy, NULL)
            && sfKeyboard_isKeyPressed(sfKeyEnter)) {
            vec->y = 1.005;
            vec->x = 15.0 * g->delta_time;
            sfView_rotate(g->camera, vec->x);
            sfView_zoom(g->camera, vec->y);
            *idx = i;
        }
        if (sfFloatRect_intersects(player, &enemy, NULL)) {
            g->interact.draw = true;
            sfSprite_setPosition(g->interact.sprite,
                (sfVector2f){enemy_pos.x + 45, enemy_pos.y + 75});
            return true;
        }
    }
    return false;
}

static void start_fight_animation(vec2_double_t *vec,
    game_t *g)
{
    if (vec->x != 0.0) {
        vec->y += 0.005;
        vec->x += 15.0 * g->delta_time;
        sfView_rotate(g->camera, vec->x);
        sfView_zoom(g->camera, vec->y);
    }
}

static void end_fight_animation(vec2_double_t *vec, int *idx,
    bool *finished, game_t *g)
{
    if (vec->x > 10.0) {
        g->state = FIGHT;
        sfRenderWindow_setView(g->window,
            sfRenderWindow_getDefaultView(g->window));
        *finished = true;
        vec->x = 0.0;
        vec->y = 1.0;
        g->fight.opponent_idx = *idx;
        *idx = 0;
        sfView_reset(g->camera, (sfFloatRect){0, 0, WIDTH, HEIGHT});
        sfView_setCenter(g->camera, (sfVector2f){MAP_WIDTH * 2,
            MAP_HEIGHT * 2});
    }
}

bool is_interact(game_t *g, bool *finished)
{
    sfFloatRect player = sfSprite_getGlobalBounds(g->player.sprite);
    static vec2_double_t vec = {0.0, 1.0};
    static int idx = 0;

    player.left += PLAYER_SPRITE_SIZE;
    player.top += PLAYER_SPRITE_SIZE;
    player.width = PLAYER_SPRITE_SIZE;
    player.height = PLAYER_SPRITE_SIZE;
    end_fight_animation(&vec, &idx, finished, g);
    start_fight_animation(&vec, g);
    if (check_enemies(g, &player, &vec, &idx))
        return true;
    g->interact.draw = false;
    return false;
}
