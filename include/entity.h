/*
** EPITECH PROJECT, 2023
** entity.h
** File description:
** entity object
*/
#ifndef ENTITY_H_
    #define ENTITY_H_
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdio.h>
typedef struct object {
    sfTexture* texture;
    sfSprite* sprite;
} entity;
void entity_constructor(entity *ent, int texture_rect[], const char *texture);
void entity_set_texture(entity *ent, const char *file);
void entity_handle_time(entity *ent);
void entity_animate(entity *ent, int offset, int max);
void entity_translate(entity *ent, sfVector2f offset);
void entity_set_texture_rect(entity *ent, int arr[]);
void entity_free(entity *ent);
void entity_initialize_time(entity *ent);
#endif
