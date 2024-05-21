/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** map_screen.h
*/

#ifndef MAP_SCREEN_H
    #define MAP_SCREEN_H
    #include "rpg.h"


/*
 * map_screen.c
*/
void map_renderer(game_t *game, screen_t *screen);
sfVector2f get_pos_rel_to_map(sfVector2f pos, sfVector2f map_pos);

/*
 * init_map_screen.c
*/
screen_t *init_map(void);

#endif
