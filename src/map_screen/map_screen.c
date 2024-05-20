/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** map_screen.c
*/

#include "../../include/rpg.h"

static void update_player_rect(map_screen_t *map)
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

static void update_stam_bar(float time_diff, map_screen_t *map)
{
    if (!sfKeyboard_isKeyPressed(sfKeyLShift) && map->sprint->stamina < 1)
        map->sprint->stamina += time_diff * 0.0725f;
    if (sfKeyboard_isKeyPressed(sfKeyLShift) && map->sprint->stamina > 0)
        map->sprint->stamina = (map->sprint->stamina - time_diff * 0.15f <= 0)
            ? -.2f : map->sprint->stamina - time_diff * 0.15f;
    if (map->sprint->stamina > 1)
        map->sprint->stamina = 1;
    if (map->sprint->stamina == 1)
        map->sprint->rect.top = 40;
    if (map->sprint->stamina < 1)
        map->sprint->rect.top = 32;
    if (map->sprint->stamina < 0.75)
        map->sprint->rect.top = 24;
    if (map->sprint->stamina < 0.5)
        map->sprint->rect.top = 16;
    if (map->sprint->stamina < 0.25)
        map->sprint->rect.top = 8;
    if (map->sprint->stamina <= 0)
        map->sprint->rect.top = 0;
}

static void update_direction(map_screen_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        map->player_direction.x -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        map->player_direction.x += 1;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        map->player_direction.y -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        map->player_direction.y += 1;
}

static void update_position(game_t *game, map_screen_t *map)
{
    float time_diff = ((float)(sfClock_getElapsedTime
        (game->clock).microseconds - game->last_frame_time)) / 1000000;
    _Bool sprinting;

    update_stam_bar(time_diff, map);
    sprinting = map->sprint->stamina > 0 &&
        sfKeyboard_isKeyPressed(sfKeyLShift);
    map->player_direction.x = 0;
    map->player_direction.y = 0;
    update_direction(map);
    if (map->player_direction.x != 0 && map->player_direction.y != 0) {
        map->player_direction.x *= 1.f / (float)(M_SQRT2);
        map->player_direction.y *= 1.f / (float)(M_SQRT2);
    }
    sfSprite_move(map->map_sprite, (sfVector2f){-map->player_direction.x * (
        map->speed * (float)!sprinting + map->sprint_speed * (float)sprinting)
        * time_diff, -map->player_direction.y * (map->speed * (float)!
        sprinting + map->sprint_speed * (float)sprinting) * time_diff});
    update_player_rect(map);
}

static void show_map(game_t *game, map_screen_t *map)
{
    sfSprite_setTextureRect(map->sprint->sprite, map->sprint->rect);
    sfRenderWindow_drawSprite(game->window, map->map_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, map->player->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, map->sprint->sprite, NULL);
}

static void animate_player(game_t *game, map_screen_t *map_screen)
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

static void update_map(game_t *game, map_screen_t *map_screen)
{
    update_position(game, map_screen);
    animate_player(game, map_screen);
    show_map(game, map_screen);
}

void map_renderer(game_t *game, screen_t *screen)
{
    update_map(game, screen->screen);
}
