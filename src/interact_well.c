/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** well interact
*/
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/System/Vector2.h>
#include "game.h"
#include "my.h"

static void interact_well2(game_t *g)
{
    if (g->player.money >= 10) {
        g->player.money -= 10;
        g->player.live++;
        g->player.money_str = my_int_to_str(g->player.money);
        sfText_setString(g->player.money_text.text_obj,
            g->player.money_str);
        update_life(&g->player.life_sprite, &g->fight, g->player.live);
        update_life(&g->fight.life, &g->fight, g->player.live);
        update_life(&g->fight.life2, &g->fight, g->opponent_live);
    }
}

static void setup_player(sfFloatRect *player)
{
    player->left += 170;
    player->top += 170;
    player->width = PLAYER_SPRITE_SIZE;
    player->height = PLAYER_SPRITE_SIZE;
}

void interact_well(game_t *g)
{
    sfFloatRect player =
        sfSprite_getGlobalBounds(g->player.player_sprite.sprite);
    sfFloatRect well_pos = sfSprite_getGlobalBounds(g->element.well.sprite);
    sfVector2f pos_well = sfSprite_getPosition(g->element.well.sprite);

    setup_player(&player);
    if (sfFloatRect_intersects(&player, &well_pos, NULL)
        && sfKeyboard_isKeyPressed(sfKeyEnter)) {
        interact_well2(g);
    }
    if (sfFloatRect_intersects(&player, &well_pos, NULL)) {
        g->element.draw = true;
        sfText_setPosition(g->element.text,
            (sfVector2f){pos_well.x + well_pos.width / 2,
            pos_well.y - well_pos.height / 3});
    } else {
        g->element.draw = false;
    }
}
