/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** game_struct.h
*/

#ifndef COLLISION_H
    #define COLLISION_H
    #include "rpg.h"

/*
 * collsion.c
*/
bool check_collision(map_screen_t *map, int x, int y);
bool check_sprite_collision(sfSprite *sprite1, sfSprite *sprite2);

/*
 * collsion_event.c
*/
void check_direction_event(map_screen_t *map, game_t *game);

#endif //COLLISION_H
