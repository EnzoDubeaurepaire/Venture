/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** map_screen.c
*/

#include "../../include/rpg.h"

void update_player_rect(map_screen_t *map)
{
    if (map->player_direction.y == -1)
        map->player->rect.left = 32;
    if (map->player_direction.y == 1)
        map->player->rect.left = 0;
    if (map->player_direction.x == -1)
        map->player->rect.left = 96;
    if (map->player_direction.x == 1)
        map->player->rect.left = 64;
    sfSprite_setTextureRect(map->player->sprite, map->player->rect);
}

void update_direction(map_screen_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        if (check_collision(map, map->player, -1, 0) == false)
        map->player_direction.x -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        if (check_collision(map, map->player, 1, 0) == false)
        map->player_direction.x += 1;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        if (check_collision(map, map->player, 0, -1) == false)
        map->player_direction.y -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        if (check_collision(map, map->player, 0, 1) == false)
        map->player_direction.y += 1;
}

void update_player_pos(map_screen_t *map)
{
    map->map_position = sfSprite_getPosition(map->map_sprite);
    map->player->pos_rel_to_map = get_pos_rel_to_map(map->player->position,
        map->map_position);
    sfSprite_setPosition(map->mini_map_player, (sfVector2f){1620 +
        map->player->pos_rel_to_map.x * (25.f / 960), 50 +
        map->player->pos_rel_to_map.y * (25.f / 960)});
}

void animate_player(game_t *game, map_screen_t *map_screen)
{
    long long time = sfClock_getElapsedTime(game->clock).microseconds -
        game->last_frame_time;
    static long long elapsed_time = 0;

    elapsed_time += time;
    if (elapsed_time > 250000 - 125000 * (sfKeyboard_isKeyPressed(sfKeyLShift)
        && map_screen->sprint->stamina > 0) &&
        (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyZ)
        || sfKeyboard_isKeyPressed(sfKeyS) ||
        sfKeyboard_isKeyPressed(sfKeyD))) {
        elapsed_time = 0;
        map_screen->player->rect.top += 32;
        map_screen->player->rect.top = map_screen->player->rect.top % 96;
    }
}
