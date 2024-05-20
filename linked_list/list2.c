/*
** EPITECH PROJECT, 2024
** day04_tek2
** File description:
** ex4_2.c
*/

#include "list.h"

void list_clear(list_t **front_ptr)
{
    list_t *head;

    if (!front_ptr || !*front_ptr)
        return;
    while (list_get_size(*front_ptr) != 1) {
        for (head = *front_ptr; head && head->next &&
            head->next->next; head = head->next);
        if (head && head->next) {
            free(head->next);
            head->next = NULL;
        }
    }
    free(*front_ptr);
    *front_ptr = NULL;
}

void *list_get_elem_at_front(list_t *list)
{
    if (!list)
        return 0;
    return list->value;
}

void *list_get_elem_at_back(list_t *list)
{
    if (!list)
        return 0;
    if (list_get_size(list) == 1)
        return list->value;
    for (; list->next; list = list->next);
    return list->value;
}

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    if (!list || list_get_size(list) <= position)
        return 0;
    for (unsigned int i = 0; i < position; i++)
        list = list->next;
    return list->value;
}

bool list_is_empty(list_t *list)
{
    return list_get_size(list) == 0;
}
