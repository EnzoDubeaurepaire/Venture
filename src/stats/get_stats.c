/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** get_stats.c
*/

#include "../../include/rpg.h"

int get_att(game_t *game)
{
    player_stat_t *stat = game->screens[5]->screen;

    return stat->att;
}

int get_max_hp(game_t *game)
{
    player_stat_t *stat = game->screens[5]->screen;

    return stat->hp;
}

int get_res(game_t *game)
{
    player_stat_t *stat = game->screens[5]->screen;

    return stat->res;
}

double get_as(game_t *game)
{
    player_stat_t *stat = game->screens[5]->screen;

    return stat->as;
}

int get_hp(game_t *game)
{
    player_stat_t *stat = game->screens[5]->screen;

    return stat->actual_hp;
}
