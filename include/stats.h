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

/*
 * get_stats.c
*/
int get_att(game_t *game);
int get_hp(game_t *game);
int get_max_hp(game_t *game);
int get_res(game_t *game);
double get_as(game_t *game);

/*
 * set_stats.c
*/
void set_hp(game_t *game, int new_hp);
void give_xp(game_t *game, int xp);
void regen_hp(game_t *game);

#endif
