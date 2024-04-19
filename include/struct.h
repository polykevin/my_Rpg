/*
** EPITECH PROJECT, 2023
** struct
** File description:
** struct
*/
#ifndef STRUCT_H
    #define STRUCT_H
    #define NB_DIVISION 50
typedef struct vec2 {
    int x;
    int y;
}vec2_t;
typedef struct plane {
    sfVector2f start;
    sfVector2f end;
    int speed;
    int delay;
    int exists;
    int id;
    sfTexture *texture;
    sfRectangleShape *rect;
}plane_t;
typedef struct tower {
    sfVector2f pos;
    float radius;
    sfCircleShape *circle;
    sprite_t sprite;
}tower_t;
#endif
