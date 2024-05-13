/*
** EPITECH PROJECT, 2024
** player movement
** File description:
** main file
*/

#include "snow_header.h"

int check_contact(sfVector2f pos_1, sfRectangleShape *box_2)
{
    sfVector2f pos_2 = sfRectangleShape_getPosition(box_2);
    sfVector2f scale_2 = sfRectangleShape_getSize(box_2);
    int x2_min = pos_2.x;
    int x2_max = x2_min + scale_2.x;
    int y2_min = pos_2.y;
    int y2_max = y2_min + scale_2.y;
    int x = 0;
    int y = 0;

    if (x2_min <= pos_1.x && x2_max >= pos_1.x)
        x++;
    if (x2_min <= (pos_1.x + 60) && x2_max >= (pos_1.x + 60))
        x++;
    if (y2_min <= pos_1.y && y2_max >= pos_1.y)
        y++;
    if (y2_min <= (pos_1.y + 60) && y2_max >= (pos_1.y + 60))
        y++;
    if (x == 2 && y == 2)
        return SUCCESS;
    return FAIL;
}
