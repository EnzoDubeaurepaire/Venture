/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** set_stats.c
*/

#include "../../include/rpg.h"

void set_hp(game_t *game, int new_hp)
{
    player_stat_t *stat = game->screens[5]->screen;

    if (new_hp > stat->hp)
        stat->actual_hp = stat->hp;
    else
        stat->actual_hp = new_hp;
}
