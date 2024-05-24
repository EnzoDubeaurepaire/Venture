/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** map_screen.c
*/

#include "../../include/rpg.h"

sfVector2f get_pos_rel_to_map(sfVector2f pos, sfVector2f map_pos)
{
    return (sfVector2f){-map_pos.x + pos.x, -map_pos.y + pos.y};
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

static void move_map(game_t *game, map_screen_t *map,
    _Bool sprinting, float time_diff)
{
    float speed_modifier = map->speed *
        (float)!sprinting + map->sprint_speed * (float)sprinting;
    sfVector2f offset = {
        -map->player_direction.x * speed_modifier * time_diff,
        -map->player_direction.y * speed_modifier * time_diff
    };

    sfSprite_move(map->map_sprite, offset);
    sfSprite_move(map->collision_sprite, offset);
    for (int i = 0; i < 20; i++) {
        sfSprite_move(map->enemies[i]->e->sprite, offset);
        sfRectangleShape_move(map->enemies[i]->e->hitbox, offset);
    }
}

static void update_bush(map_screen_t *map)
{
    sfSprite_setPosition(map->bush_sprite, (sfVector2f){500 +
        sfSprite_getPosition(map->map_sprite).x, 500 +
        sfSprite_getPosition(map->map_sprite).y});
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
    move_map(game, map, sprinting, time_diff);
    update_player_rect(map);
    update_player_pos(map);
    update_enemies_pos(map);
    update_bush(map);
}

static void show_entities(game_t *game, map_screen_t *map)
{
    if (sfSprite_getPosition(map->bush_sprite).y <
        sfSprite_getPosition(map->player->sprite).y - 90) {
        sfRenderWindow_drawSprite(game->window, map->bush_sprite, NULL);
        sfRenderWindow_drawSprite(game->window, map->player->sprite, NULL);
    } else {
        sfRenderWindow_drawSprite(game->window, map->player->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, map->bush_sprite, NULL);
    }
    if (map->player->is_hitbox == sfTrue)
        sfRenderWindow_drawRectangleShape(
            game->window, map->player->hitbox, NULL);
    for (int i = 0; i < ENEMIES; i++)
        sfRenderWindow_drawSprite(game->window,
            map->enemies[i]->e->sprite, NULL);
}

static void show_map(game_t *game, map_screen_t *map)
{
    sfRenderWindow_drawSprite(game->window, map->collision_sprite, NULL);
    sfSprite_setTextureRect(map->sprint->sprite, map->sprint->rect);
    sfRenderWindow_drawSprite(game->window, map->map_sprite, NULL);
    show_entities(game, map);
    sfRenderWindow_drawSprite(game->window, map->sprint->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, map->health_bar, NULL);
    sfRenderWindow_drawRectangleShape(game->window, map->mini_map, NULL);
    sfRenderWindow_drawSprite(game->window, map->mini_map_player, NULL);
}

void update_map(game_t *game, map_screen_t *map_screen)
{
    update_position(game, map_screen);
    update_health_bar(map_screen, game);
    animate_player(game, map_screen);
    animate_enemies(game, map_screen);
    show_map(game, map_screen);
    show_inventory_map(game, map_screen);
}
