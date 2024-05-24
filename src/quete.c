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

static void set_pos_pnj(quete_t *quete)
{
    sfRectangleShape_setSize(quete->rect, (sfVector2f){380, 130});
    sfRectangleShape_setFillColor(quete->rect, sfWhite);
    sfRectangleShape_setOutlineColor(quete->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(quete->rect, 5);
    sfRectangleShape_setPosition(quete->rect, (sfVector2f){2480, 1745});
    sfSprite_setPosition(quete->character.sprite, (sfVector2f){2380, 1795});
    sfSprite_setScale(quete->character.sprite, (sfVector2f){6, 6});
    sfSprite_setPosition(quete->check1.sprite, (sfVector2f){2795, 1748});
    sfSprite_setScale(quete->check1.sprite, (sfVector2f){0.05, 0.05});
    sfSprite_setPosition(quete->check2.sprite, (sfVector2f){2813, 1780});
    sfSprite_setScale(quete->check2.sprite, (sfVector2f){0.05, 0.05});
    sfSprite_setPosition(quete->check3.sprite, (sfVector2f){2780, 1810});
    sfSprite_setScale(quete->check3.sprite, (sfVector2f){0.05, 0.05});
    sfSprite_setPosition(quete->check4.sprite, (sfVector2f){2709, 1840});
    sfSprite_setScale(quete->check4.sprite, (sfVector2f){0.05, 0.05});
}

static void set_flag(quete_t *quete)
{
    sfText_setPosition(quete->attack_txt, (sfVector2f){1785, 2092});
    sfText_setCharacterSize(quete->attack_txt, 50);
    sfText_setPosition(quete->defense_txt, (sfVector2f){2650, 2092});
    sfText_setCharacterSize(quete->defense_txt, 50);
    sfText_setPosition(quete->speed_txt, (sfVector2f){2420, 2250});
    sfText_setCharacterSize(quete->speed_txt, 50);
    sfText_setOutlineColor(quete->speed_txt, sfBlack);
    sfText_setOutlineThickness(quete->speed_txt, 5);
    sfText_setOutlineColor(quete->attack_txt, sfBlack);
    sfText_setOutlineThickness(quete->attack_txt, 5);
    sfText_setOutlineColor(quete->defense_txt, sfBlack);
    sfText_setOutlineThickness(quete->defense_txt, 5);
    sfText_setColor(quete->quete1, sfBlack);
    sfText_setColor(quete->quete2, sfBlack);
    sfText_setColor(quete->quete3, sfBlack);
    sfText_setColor(quete->quete4, sfBlack);
}

static void set_text(quete_t *quete)
{
    sfText_setPosition(quete->quete1, (sfVector2f){2500, 1750});
    sfText_setCharacterSize(quete->quete1, 20);
    sfText_setPosition(quete->quete2, (sfVector2f){2500, 1780});
    sfText_setCharacterSize(quete->quete2, 20);
    sfText_setPosition(quete->quete3, (sfVector2f){2500, 1810});
    sfText_setCharacterSize(quete->quete3, 20);
    sfText_setPosition(quete->quete4, (sfVector2f){2500, 1840});
    sfText_setCharacterSize(quete->quete4, 20);
    set_flag(quete);
}

static void create_flag(quete_t *quete, sfFont *font)
{
    quete->speed_txt = sfText_create();
    sfText_setFont(quete->speed_txt, font);
    sfText_setString(quete->speed_txt, "S\np\ne\ne\nd");
    quete->attack_txt = sfText_create();
    sfText_setFont(quete->attack_txt, font);
    sfText_setString(quete->attack_txt, "Attack");
    quete->defense_txt = sfText_create();
    sfText_setFont(quete->defense_txt, font);
    sfText_setString(quete->defense_txt, "Defense");
}

void quete_text(quete_t *quete)
{
    sfFont *font = sfFont_createFromFile("resource/font/font.ttf");

    quete->quete1 = sfText_create();
    sfText_setFont(quete->quete1, font);
    sfText_setString(quete->quete1, "win 3 level in attack");
    quete->quete2 = sfText_create();
    sfText_setFont(quete->quete2, font);
    sfText_setString(quete->quete2, "win 3 level in defense");
    quete->quete3 = sfText_create();
    sfText_setFont(quete->quete3, font);
    sfText_setString(quete->quete3, "win 3 level in speed");
    quete->quete4 = sfText_create();
    sfText_setFont(quete->quete4, font);
    sfText_setString(quete->quete4, "Fight the boss");
    create_flag(quete, font);
    set_text(quete);
}

void create_pnj(quete_t *quete)
{
    sprite_init(&quete->character, "resource/player/quete.png"
        , (sfIntRect){5, 0, 20, 30});
    sprite_init(&quete->check1, "resource/map/check.png"
        , (sfIntRect){0, 0, 512, 512});
    sprite_init(&quete->check2, "resource/map/check.png"
        , (sfIntRect){0, 0, 512, 512});
    sprite_init(&quete->check3, "resource/map/check.png"
        , (sfIntRect){0, 0, 512, 512});
    sprite_init(&quete->check4, "resource/map/check.png"
        , (sfIntRect){0, 0, 512, 512});
    quete->rect = sfRectangleShape_create();
    set_pos_pnj(quete);
    quete_text(quete);
}
