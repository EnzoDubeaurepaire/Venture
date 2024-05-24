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

    elapsed_time += time;
    sfRenderWindow_drawCircleShape(game->window, map->player_reach, NULL);
    sfFloatRect player_reach_bounds =
        sfCircleShape_getGlobalBounds(map->player_reach);
    for (int i = 0; i < ENEMIES; i++) {
        sfFloatRect enemy_hitbox_bounds =
            sfRectangleShape_getGlobalBounds(map->enemies[i]->e->hitbox);
        if (sfFloatRect_intersects(
            &player_reach_bounds, &enemy_hitbox_bounds, NULL)) {
            printf("> %d, %lld\n", i, elapsed_time);
        }
    }
}
