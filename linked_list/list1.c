/*
** EPITECH PROJECT, 2024
** day04_tek2
** File description:
** ex4.c
*/

#include "list.h"

unsigned int list_get_size(list_t *list)
{
    unsigned int size = 0;

    for (; list; list = list->next)
        size++;
    return size;
}

void list_dump(list_t *list, value_displayer_t val_disp)
{
    for (; list; list = list->next)
        val_disp(list->value);
}

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *new = malloc(sizeof(list_t));

    if (!new)
        return false;
    if (!front_ptr) {
        free(new);
        return false;
    }
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return true;
}

bool list_add_elem_at_back(list_t **front_ptr, void *elem)
{
    list_t *new = malloc(sizeof(list_t));
    list_t *head;

    if (!new)
        return false;
    if (!front_ptr) {
        free(new);
        return false;
    }
    new->value = elem;
    head = *front_ptr;
    if (!*front_ptr) {
        *front_ptr = new;
        return true;
    }
    for (; head->next; head = head->next);
    head->next = new;
    return true;
}

bool list_add_elem_at_position(list_t **front_ptr, void *elem,
    unsigned int position)
{
    list_t *new = malloc(sizeof(list_t));
    list_t *head;

    if (!new)
        return false;
    if (!front_ptr || list_get_size(*front_ptr) < position) {
        free(new);
        return false;
    }
    if (!position) {
        free(new);
        return list_add_elem_at_front(front_ptr, elem);
    }
    new->value = elem;
    head = *front_ptr;
    for (unsigned int i = 0; i < position - 1; i++)
        head = head->next;
    new->next = head->next;
    head->next = new;
    return true;
}
