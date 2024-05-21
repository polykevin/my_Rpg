/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_
typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} linked_list_t;
void push_to_list(linked_list_t **list, void *data);
#endif
