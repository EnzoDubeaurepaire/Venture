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
 * map_renderer.c
*/
void map_renderer(game_t *game, screen_t *screen);

/*
 * map_screen.c
*/
sfVector2f get_pos_rel_to_map(sfVector2f pos, sfVector2f map_pos);
void update_map(game_t *game, map_screen_t *map_screen);

/*
 * init_map_screen.c
*/
screen_t *init_map(void);

/*
 * switch_map.c
*/
void switch_map(map_screen_t *map);

/*
 * display_object.c
*/
void show_bush(game_t *game, map_screen_t *map);

/*
 * init_sprite_object
*/
void init_sprite_object(map_screen_t *map);

/*
 * health_bar.c
*/
void update_health_bar(map_screen_t *map, game_t *game);

#endif
