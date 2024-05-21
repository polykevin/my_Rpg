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

static void enemy_init(sfFloatRect *enemy, game_t *g, int i,
    sfVector2f *enemy_pos)
{
    *enemy = sfSprite_getGlobalBounds(g->tab_ennemy[i]->sprite);
    enemy->top += PLAYER_SPRITE_SIZE;
    enemy->left += PLAYER_SPRITE_SIZE;
    enemy->width = PLAYER_SPRITE_SIZE;
    enemy->height = PLAYER_SPRITE_SIZE;
    *enemy_pos = sfSprite_getPosition(g->tab_ennemy[i]->sprite);
}

static bool check_enemies(game_t *g, sfFloatRect *player,
    double *zoom_factor, double *angle)
{
    sfFloatRect enemy;
    sfVector2f enemy_pos;

    for (int i = 0; i < 4; i++) {
        enemy_init(&enemy, g, i, &enemy_pos);
        if (sfFloatRect_intersects(player, &enemy, NULL)
            && sfKeyboard_isKeyPressed(sfKeyEnter)) {
            *zoom_factor = 1.005;
            *angle = 15.0 * g->delta_time;
            sfView_rotate(g->camera, *angle);
            sfView_zoom(g->camera, *zoom_factor);
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

bool is_interact(game_t *g, bool *finished)
{
    sfFloatRect player = sfSprite_getGlobalBounds(g->player.sprite);
    static double angle = 0.0;
    static double zoom_factor = 1.0;

    player.left += PLAYER_SPRITE_SIZE;
    player.top += PLAYER_SPRITE_SIZE;
    player.width = PLAYER_SPRITE_SIZE;
    player.height = PLAYER_SPRITE_SIZE;
    if (angle > 10.0) {
        g->state = FIGHT;
        sfRenderWindow_setView(g->window,
            sfRenderWindow_getDefaultView(g->window));
        *finished = true;
    }
    if (angle != 0.0) {
        zoom_factor += 0.005;
        angle += 15.0 * g->delta_time;
        sfView_rotate(g->camera, angle);
        sfView_zoom(g->camera, zoom_factor);
    }
    if (check_enemies(g, &player, &zoom_factor, &angle))
        return true;
    g->interact.draw = false;
    return false;
}
