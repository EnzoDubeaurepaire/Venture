/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** regen_player.c
*/

#include "../../include/rpg.h"

void regen_hp(game_t *game)
{
    player_stat_t *stat = game->screens[5]->screen;
    static long long last_heal = 0;
    long long time = sfClock_getElapsedTime(game->clock).microseconds
        / 1000000;

    if (time - last_heal >= 5) {
        stat->actual_hp += 5;
        last_heal = time;
    }
    if (stat->actual_hp > stat->hp)
        stat->actual_hp = stat->hp;
}
