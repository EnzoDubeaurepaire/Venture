/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** check_save_elements.c
*/

#include "../../include/rpg.h"

_Bool check_stat_activ(const char *line, ssize_t size)
{
    if (size > 2)
        return 0;
    if ((line[0] < '0' || line[0] > '3') && line[0] != '\n')
        return 0;
    return 1;
}

_Bool check_uint(const char *line, ssize_t size)
{
    for (ssize_t i = 0; i < size; i++)
        if ((line[i] < '0' || line[i] > '9') && line[i] != '\n')
            return 0;
    return 1;
}

_Bool check_int(const char *line, ssize_t size)
{
    for (ssize_t i = 0; i < size; i++)
        if (line[i] != '-' && (line[i] < '0' || line[i] > '9') &&
            line[i] != '\n')
            return 0;
    return 1;
}
