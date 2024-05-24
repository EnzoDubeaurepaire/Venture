/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** init_map_screen.c
*/

#include "../../include/rpg.h"

void init_combat(map_screen_t *map)
{
    sfColor transparentRed = {255, 0, 0, 100};
    sfVector2f position = {1920 / 2.0f - 100, 1080 / 2.0f - 100};

    map->player_reach = sfCircleShape_create();
    sfCircleShape_setRadius(map->player_reach, 100);
    sfCircleShape_setPosition(map->player_reach, position);
    sfCircleShape_setFillColor(map->player_reach, transparentRed);
}
