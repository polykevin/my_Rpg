/*
** EPITECH PROJECT, 2024
** fight
** File description:
** fight
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "button.h"
#include "interact.h"
#include "menu.h"
#include "player_movement.h"
#include "sprite.h"
#include "game.h"
#include "fight.h"
#include "my.h"

static char **set_position2(int i)
{
    if (i == 8)
        return my_str_to_word_array("0.125,1.86", ',');
    if (i == 9)
        return my_str_to_word_array("1.65,0.55", ',');
    if (i == 10)
        return my_str_to_word_array("1.925,0.55", ',');
    if (i == 11)
        return my_str_to_word_array("2.2,0.55", ',');
    return NULL;
}

static char **set_position(int i)
{
    if (i == 0)
        return my_str_to_word_array("1.955, 2.65", ',');
    if (i == 1)
        return my_str_to_word_array("1.955,3.2", ',');
    if (i == 2)
        return my_str_to_word_array("1.955,3.75", ',');
    if (i == 3)
        return my_str_to_word_array("2.79,1.86", ',');
    if (i == 4)
        return my_str_to_word_array("3.29,1.86", ',');
    if (i == 5)
        return my_str_to_word_array("3.79,1.86", ',');
    if (i == 6)
        return my_str_to_word_array("1.125,1.86", ',');
    if (i == 7)
        return my_str_to_word_array("0.625,1.86", ',');
    return set_position2(i);
    return NULL;
}

static char *set_boss(int i)
{
    if (i == 9)
        return "resource/boss1.png";
    if (i == 10)
        return "resource/boss2.png";
    if (i == 11)
        return "resource/boss3.png";
}

void ennemy_init_boss(game_t *g, sprite_t *ennemy, int i)
{
    char *image = NULL;

    if (i >= 9) {
        image = set_boss(i);
        sprite_init(ennemy, image,
            (sfIntRect){0, 65, 75, 65});
        sfSprite_setScale(g->interact.sprite, (sfVector2f){0.15, 0.15});
        sfSprite_setScale(ennemy->sprite, (sfVector2f){3, 3});
    }
}

void ennemy_init_pnj(game_t *g, sprite_t *ennemy, int i)
{
    char *image = "resource/player/Skeleton.png";

    if (i < 9) {
    sprite_init(ennemy, image,
        (sfIntRect){0, 35, 25, 30});
    sfSprite_setScale(g->interact.sprite, (sfVector2f){0.15, 0.15});
    sfSprite_setScale(ennemy->sprite, (sfVector2f){4.2, 4.2});
    }
}

void ennemy_init(game_t *g)
{
    char **pos = NULL;
    sprite_t *ennemy = NULL;
    double x = 0;
    double y = 0;

    g->tab_ennemy = malloc(sizeof(sprite_t *) * 12);
    for (int i = 0; i < 12; i++) {
        ennemy = malloc(sizeof(sprite_t));
        pos = set_position(i);
        ennemy_init_boss(g, ennemy, i);
        ennemy_init_pnj(g, ennemy, i);
        x = atof(pos[0]);
        y = atof(pos[1]);
        sfSprite_setPosition(ennemy->sprite, (sfVector2f){MAP_WIDTH * x,
            MAP_HEIGHT * y});
        ennemy->dead = false;
        g->tab_ennemy[i] = ennemy;
    }
}

void well(element_t *element)
{
    sprite_init(&element->well, "resource/map/well.png",
            (sfIntRect){0, 0, 48, 48});
    sfSprite_setPosition(element->well.sprite, (sfVector2f){MAP_WIDTH * 1.82,
    MAP_HEIGHT * 1.755});
    sfSprite_setScale(element->well.sprite, (sfVector2f){4, 4}); 
}
