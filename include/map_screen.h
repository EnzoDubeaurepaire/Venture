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
 * init_map_screen.c
*/
sfRectangleShape *init_hitbox(entity_t *player);

/*
 * init_map_enemies.c
*/
enemy_t **init_enemies(map_screen_t *map);

/*
 * map_enemies.c
*/
void animate_enemies(game_t *game, map_screen_t *map_screen);
void update_enemies_pos(map_screen_t *map);

/*
 * map_player.c
*/
void animate_player(game_t *game, map_screen_t *map_screen);
void update_player_pos(map_screen_t *map);
void update_player_rect(map_screen_t *map);
void update_direction(map_screen_t *map);

/*
 * health_bar.c
*/
void update_health_bar(map_screen_t *map, game_t *game);

#endif
