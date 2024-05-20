/*
** EPITECH PROJECT, 2024
** day04_tek2
** File description:
** ex4_3.c
*/

#include "list.h"

bool list_del_elem_at_front(list_t **front_ptr)
{
    list_t *tmp;

    if (!front_ptr || !*front_ptr)
        return false;
    tmp = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return true;
}

bool list_del_elem_at_back(list_t **front_ptr)
{
    list_t *head;

    if (!front_ptr || !*front_ptr)
        return false;
    if (list_get_size(*front_ptr) == 1)
        return list_del_elem_at_front(front_ptr);
    for (head = *front_ptr; head->next && head->next->next; head = head->next);
    free(head->next);
    head->next = NULL;
    return true;
}

bool list_del_elem_at_position(list_t **front_ptr, unsigned int position)
{
    list_t *head;
    list_t *new_next;

    if (!front_ptr || !*front_ptr || position >= list_get_size(*front_ptr))
        return false;
    if (!position)
        return list_del_elem_at_front(front_ptr);
    head = *front_ptr;
    for (unsigned int i = 1; i < position; i++)
        head = head->next;
    new_next = head->next->next;
    free(head->next);
    head->next = new_next;
    return true;
}
