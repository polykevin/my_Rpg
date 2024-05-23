/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** fight
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Vector2.h>
#include "button.h"
#include "game.h"
#include "sprite.h"
#include "fight.h"

void fight_event(fight_t *fight, sfEvent *event)
{
    fight->rock.is_clicked(&fight->rock, &event->mouseButton);
    fight->paper.is_clicked(&fight->paper, &event->mouseButton);
    fight->cisor.is_clicked(&fight->cisor, &event->mouseButton);
    fight->rock.is_hover(&fight->rock, &event->mouseMove);
    fight->paper.is_hover(&fight->paper, &event->mouseMove);
    fight->cisor.is_hover(&fight->cisor, &event->mouseMove);
}
