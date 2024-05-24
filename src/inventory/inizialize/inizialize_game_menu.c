/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"

static void malloc_struct(G_menu_t *menu)
{
    menu->back = malloc(sizeof(Background_t) * 6);
    menu->words = malloc(sizeof(words_t) * 8);
}

static void inzialize_text_2(G_menu_t *menu)
{
    TEXT[4].text = sfText_create();
    sfText_setString(TEXT[4].text, "Save");
    sfText_setFont(TEXT[4].text, menu->font);
    sfText_setCharacterSize(TEXT[4].text, 30);
    TEXT[5].text = sfText_create();
    sfText_setString(TEXT[5].text, "Quit");
    sfText_setFont(TEXT[5].text, menu->font);
    sfText_setCharacterSize(TEXT[5].text, 30);
    TEXT[6].text = sfText_create();
    sfText_setString(TEXT[6].text, "Inventory");
    sfText_setFont(TEXT[6].text, menu->font);
    sfText_setCharacterSize(TEXT[6].text, 27);
}

static void inzialize_text(G_menu_t *menu)
{
    menu->font = sfFont_createFromFile("./resource/font/font.ttf");
    TEXT[0].text = sfText_create();
    sfText_setString(TEXT[0].text, "Items");
    sfText_setFont(TEXT[0].text, menu->font);
    sfText_setCharacterSize(TEXT[0].text, 30);
    TEXT[1].text = sfText_create();
    sfText_setString(TEXT[1].text, "Equipment");
    sfText_setFont(TEXT[1].text, menu->font);
    sfText_setCharacterSize(TEXT[1].text, 30);
    TEXT[2].text = sfText_create();
    sfText_setString(TEXT[2].text, "Status");
    sfText_setFont(TEXT[2].text, menu->font);
    sfText_setCharacterSize(TEXT[2].text, 30);
    TEXT[3].text = sfText_create();
    sfText_setString(TEXT[3].text, "Load");
    sfText_setFont(TEXT[3].text, menu->font);
    sfText_setCharacterSize(TEXT[3].text, 30);
    inzialize_text_2(menu);
}

static void inizialize_bag(G_menu_t *menu)
{
    BACK[5].back = sfRectangleShape_create();
    sfRectangleShape_setSize(BACK[5].back,
    (sfVector2f){WIDTH * 0.09, HEIGHT * 0.04});
    sfRectangleShape_setFillColor(BACK[5].back,
    sfColor_fromRGBA(200, 200, 200, 200));
}

static void inizialize_inventory(G_menu_t *menu)
{
    BACK[3].back = sfRectangleShape_create();
    sfRectangleShape_setSize(BACK[3].back,
    (sfVector2f){WIDTH * 0.4, HEIGHT * 0.4});
    sfRectangleShape_setFillColor(BACK[3].back,
    sfColor_fromRGBA(19, 27, 142, 255));
    sfRectangleShape_setOutlineThickness(BACK[3].back, 5);
    sfRectangleShape_setOutlineColor(BACK[3].back,
    sfColor_fromRGBA(250, 250, 250, 250));
    BACK[4].back = sfRectangleShape_create();
    sfRectangleShape_setSize(BACK[4].back,
    (sfVector2f){WIDTH * 0.1, HEIGHT * 0.06});
    sfRectangleShape_setFillColor(BACK[4].back,
    sfColor_fromRGBA(19, 27, 142, 255));
    sfRectangleShape_setOutlineThickness(BACK[4].back, 5);
    sfRectangleShape_setOutlineColor(BACK[4].back,
    sfColor_fromRGBA(250, 250, 250, 250));
}

static void inizialize_background(G_menu_t *menu)
{
    BACK[0].back = sfRectangleShape_create();
    sfRectangleShape_setSize(BACK[0].back, (sfVector2f){WIDTH, HEIGHT});
    sfRectangleShape_setFillColor(BACK[0].back,
    sfColor_fromRGBA(60, 60, 60, 100));
    BACK[1].back = sfRectangleShape_create();
    sfRectangleShape_setSize(BACK[1].back,
    (sfVector2f){WIDTH * 0.12, HEIGHT * 0.3});
    sfRectangleShape_setFillColor(BACK[1].back,
    sfColor_fromRGBA(60, 60, 255, 100));
    sfRectangleShape_setOutlineThickness(BACK[1].back, 5);
    sfRectangleShape_setOutlineColor(BACK[1].back,
    sfColor_fromRGBA(255, 255, 255, 255));
    BACK[2].back = sfRectangleShape_create();
    sfRectangleShape_setSize(BACK[2].back,
    (sfVector2f){WIDTH * 0.1185, HEIGHT * 0.045});
    sfRectangleShape_setFillColor(BACK[2].back,
    sfColor_fromRGBA(255, 250, 255, 60));
    sfRectangleShape_setOutlineThickness(BACK[2].back, 1);
    sfRectangleShape_setOutlineColor(BACK[2].back,
    sfColor_fromRGBA(250, 250, 250, 250));
}

void inizialize_game_menu(G_menu_t *menu)
{
    menu->on_off = OFF;
    menu->bag = OFF;
    menu->menu_nb = 0;
    malloc_struct(menu);
    inizialize_background(menu);
    inizialize_inventory(menu);
    inizialize_bag(menu);
    inzialize_text(menu);
}
