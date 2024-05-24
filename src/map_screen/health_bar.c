/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** health_bar.c
*/

#include "../../include/rpg.h"

void update_health_bar(map_screen_t *map, game_t *game)
{
    double ratio = (double)get_hp(game) / (double)get_max_hp(game);

    if (ratio == 1)
        map->health_rect.top = 40;
    if (ratio < 1)
        map->health_rect.top = 32;
    if (ratio < 0.75)
        map->health_rect.top = 24;
    if (ratio < 0.5)
        map->health_rect.top = 16;
    if (ratio < 0.25)
        map->health_rect.top = 8;
    if (ratio <= 0)
        map->health_rect.top = 0;
    sfSprite_setTextureRect(map->health_bar, map->health_rect);
}
