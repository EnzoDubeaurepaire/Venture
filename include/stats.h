/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** stats.h
*/

#ifndef STATS_H
    #define STATS_H
    #include "rpg.h"


/*
 * init_stats.c
*/
screen_t *init_stats(void);

/*
 * stats_renderer.c
*/
void stats_renderer(game_t *game, screen_t *screen);

#endif
