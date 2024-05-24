/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** give_xp.c
*/

#include "../../include/rpg.h"

void give_xp(game_t *game, int xp)
{
    player_stat_t *stats = game->screens[5]->screen;
    char value[5];

    stats->needed_exp -= xp;
    if (stats->needed_exp <= 0) {
        stats->level++;
        stats->needed_exp = 100;
        stats->total_points += 2;
        sprintf(value, "%d", stats->level);
        sfText_setString(stats->level_text, value);
        sprintf(value, "%d", stats->total_points);
        sfText_setString(stats->points_text, value);
    }
}
