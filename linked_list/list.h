/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** list.h
*/

#ifndef LIST_H
    #define LIST_H
    #include "../include/rpg.h"
    #include "stdbool.h"

typedef struct list_s {
    void *value;
    struct list_s *next;
} list_t;
unsigned int list_get_size(list_t *list);
bool list_is_empty(list_t *list);
typedef void (*value_displayer_t)(const void *value);
void list_dump(list_t *list, value_displayer_t val_disp);
bool list_add_elem_at_front(list_t **front_ptr, void *elem);
bool list_add_elem_at_back(list_t **front_ptr, void *elem);
bool list_add_elem_at_position(list_t **front_ptr, void *elem,
                               unsigned int position);
bool list_del_elem_at_front(list_t **front_ptr);
bool list_del_elem_at_back(list_t **front_ptr);
bool list_del_elem_at_position(list_t **front_ptr, unsigned int position);
void list_clear(list_t **front_ptr);
void *list_get_elem_at_front(list_t *list);
void *list_get_elem_at_back(list_t *list);
void *list_get_elem_at_position(list_t *list, unsigned int position);
#endif
