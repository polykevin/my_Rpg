/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Game render functions
*/

#include "fight.h"
#include "game.h"
#include "map_elements.h"
#include <SFML/Graphics/RenderWindow.h>


static void game_render_map_enemies(game_t *g)
{
    for (int i = 0; i < 12; i++) {
        if (!g->tab_ennemy[i]->dead)
            sfRenderWindow_drawSprite(g->window,
                g->tab_ennemy[i]->sprite, NULL);
    }
}

static void game_render_map2(game_t *g)
{
    sfRenderWindow_drawSprite(g->window,
        g->gate.sprite, NULL);
    sfRenderWindow_drawSprite(g->window,
        g->left_light.sprite, NULL);
    sfRenderWindow_drawSprite(g->window,
        g->right_light.sprite, NULL);
    sfRenderWindow_drawSprite(g->window,
        g->player.life_sprite.sprite, NULL);
    sfRenderWindow_drawSprite(g->window,
        g->player.coin_sprite.sprite, NULL);
    if (g->interact.draw)
        sfRenderWindow_drawSprite(g->window, g->interact.sprite, NULL);
}

static void game_render_text(game_t *g)
{
    sfRenderWindow_drawText(g->window, g->quete.quete1, NULL);
    sfRenderWindow_drawText(g->window, g->quete.quete2, NULL);
    sfRenderWindow_drawText(g->window, g->quete.quete3, NULL);
    sfRenderWindow_drawText(g->window, g->quete.quete4, NULL);
    sfRenderWindow_drawText(g->window, g->quete.speed_txt, NULL);
    sfRenderWindow_drawText(g->window, g->quete.attack_txt, NULL);
    sfRenderWindow_drawText(g->window, g->quete.defense_txt, NULL);
}

static void game_render_quete(game_t *g)
{
    sfRenderWindow_drawRectangleShape(g->window, g->quete.rect, NULL);
    sfRenderWindow_drawSprite(g->window, g->quete.character.sprite, NULL);
    if (g->player.attack_xp == 3)
        sfRenderWindow_drawSprite(g->window, g->quete.check1.sprite, NULL);
    if (g->player.defense_xp == 3)
        sfRenderWindow_drawSprite(g->window, g->quete.check2.sprite, NULL);
    if (g->player.speed_xp == 3)
        sfRenderWindow_drawSprite(g->window, g->quete.check3.sprite, NULL);
    if (g->tab_ennemy[9]->dead == true && g->tab_ennemy[10]->dead == true
        && g->tab_ennemy[11]->dead == true)
        sfRenderWindow_drawSprite(g->window, g->quete.check4.sprite, NULL);
}

static void game_render_fight_scene(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->fight.scene.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->fight.platform1.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->fight.platform2.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->fight.life.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->fight.life2.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->fight.skills.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->fight.skills2.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->fight.case1.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->fight.case2.sprite, NULL);
    if (g->fight.player_choice != CHOOSING) {
        sfRenderWindow_drawSprite(g->window,
            g->fight.player_choice_sprite.sprite, NULL);
    }
    sfRenderWindow_drawSprite(g->window,
        g->fight.opponent_choice_sprite.sprite, NULL);
}

static void game_render_fight_ui(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->fight.bar.sprite, NULL);
    sfRenderWindow_drawSprite(g->window,
        g->fight.paper.sprite.sprite, NULL);
    sfRenderWindow_drawSprite(g->window,
        g->fight.rock.sprite.sprite, NULL);
    sfRenderWindow_drawSprite(g->window,
        g->fight.cisor.sprite.sprite, NULL);
    if (g->player.attack_xp != 0) {
        sfRenderWindow_drawSprite(g->window, g->fight.fire.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.fire2.sprite, NULL);
    }
    if (g->player.defense_xp != 0) {
        sfRenderWindow_drawSprite(g->window, g->fight.defense.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.defense2.sprite, NULL);
    }
    if (g->player.speed_xp != 0) {
        sfRenderWindow_drawSprite(g->window, g->fight.other.sprite, NULL);
    }
    sfRenderWindow_drawSprite(g->window, g->fight.other2.sprite, NULL);
}

void game_render_menu(game_t *g)
{
    if (g->state == MENU) {
        sfRenderWindow_drawSprite(g->window, g->menu.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->menu.buttons[0]->sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->menu.buttons[1]->sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->menu.buttons[2]->sprite, NULL);
    }
}

void game_render_map(game_t *g)
{
    if (g->state == MAP) {
        sfRenderWindow_drawSprite(g->window, g->map.sprite, NULL);
        sfRenderWindow_drawText(g->window,
            g->player.money_text.text_obj, NULL);
        game_render_map_enemies(g);
        sfRenderWindow_drawSprite(g->window,
            g->player.player_sprite.sprite, NULL);
        sfRenderWindow_drawSprite(g->window,
            g->player.life_sprite.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->element.well.sprite, NULL);
        sfRenderWindow_drawSprite(g->window,
            g->player.coin_sprite.sprite, NULL);
        game_render_quete(g);
        game_render_text(g);
        if (g->interact.draw)
            sfRenderWindow_drawSprite(g->window, g->interact.sprite, NULL);
    }
}

void game_render_fight(game_t *g)
{
    if (g->state == FIGHT) {
        game_render_fight_scene(g);
        sfRenderWindow_drawSprite(g->window, g->fight.opponent.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->fight.player.sprite, NULL);
        game_render_fight_ui(g);
    }
}
