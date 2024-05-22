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

static char **set_position(int i)
{
    if (i == 0)
        return my_str_to_word_array("1.87,2.30", ',');
    if (i == 1)
        return my_str_to_word_array("2.7,1.77", ',');
    if (i == 2)
        return my_str_to_word_array("1.02,1.77", ',');
    if (i == 3)
        return my_str_to_word_array("1.87,1.32", ',');
    return NULL;
}

void ennemy_init(game_t *g)
{
    char **pos = NULL;
    sprite_t *ennemy = NULL;
    double x = 0;
    double y = 0;

    g->tab_ennemy = malloc(sizeof(sprite_t *) * 4);
    for (int i = 0; i < 4; i++) {
        ennemy = malloc(sizeof(sprite_t));
        sprite_init(ennemy, "resource/player/idle.png",
            (sfIntRect){0, 0, PLAYER_SPRITE_SIZE, PLAYER_SPRITE_SIZE});
        sfSprite_setScale(g->interact.sprite, (sfVector2f){0.15, 0.15});
        sfSprite_setScale(ennemy->sprite, (sfVector2f){4, 4});
        pos = set_position(i);
        x = atof(pos[0]);
        y = atof(pos[1]);
        sfSprite_setPosition(ennemy->sprite, (sfVector2f){MAP_WIDTH * x,
            MAP_HEIGHT * y});
        g->tab_ennemy[i] = ennemy;
    }
}

void well(element_t *element)
{
    sprite_init(&element->well, "resource/map/well.png",
            (sfIntRect){0, 0, 48, 48});
    sfSprite_setPosition(element->well.sprite, (sfVector2f){MAP_WIDTH * 1.87,
    MAP_HEIGHT * 1.75});
    sfSprite_setScale(element->well.sprite, (sfVector2f){4, 4});
}
