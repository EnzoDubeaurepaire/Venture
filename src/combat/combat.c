/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** combat.c
*/

#include "../../include/rpg.h"

void combat_system(game_t *game, map_screen_t *map)
{
    long long time = sfClock_getElapsedTime(game->clock).microseconds -
        game->last_frame_time;
    static long long elapsed_time = 0;
    sfFloatRect player_reach_bounds =
        sfCircleShape_getGlobalBounds(map->player_reach);
    sfFloatRect enemy_hitbox_bounds;

    elapsed_time += time;
    sfRenderWindow_drawCircleShape(game->window, map->player_reach, NULL);
    for (int i = 0; i < ENEMIES; i++) {
        enemy_hitbox_bounds =
            sfRectangleShape_getGlobalBounds(map->enemies[i]->e->hitbox);
        if (sfFloatRect_intersects(
            &player_reach_bounds, &enemy_hitbox_bounds, NULL)) {
            printf("> %d, %lld\n", i, elapsed_time);
        }
    }
}
