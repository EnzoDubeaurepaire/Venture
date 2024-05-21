/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** collison.c
*/

#include "../../include/rpg.h"

bool is_red_rixel(sfColor color)
{
    return color.r == 255 && color.g == 0 && color.b == 0;
}
