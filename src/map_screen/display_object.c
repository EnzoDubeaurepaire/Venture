/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_object
*/

#include "../../include/rpg.h"

void get_item_picked_up(game_t *game, map_screen_t *map, int i)
{
    if (i == )
}

void pickup_item(game_t *game, map_screen_t *map)
{
    for (int i = 0; i < 8; i++) {
        if (check_sprite_collision(map->player->sprite, map->object_table[i])
            == true && game->key == sfKeyE) {
            map->is_picked_up[i] = true;
        }
    }
}

void show_bush(game_t *game, map_screen_t *map)
{
    if (sfSprite_getPosition(map->bush_sprite).y <
        sfSprite_getPosition(map->player->sprite).y - 90) {
        sfRenderWindow_drawSprite(game->window, map->bush_sprite, NULL);
        sfRenderWindow_drawSprite(game->window, map->player->sprite, NULL);
    } else {
        sfRenderWindow_drawSprite(game->window, map->player->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, map->bush_sprite, NULL);
    }
}

void display_object(game_t *game, map_screen_t *map)
{
    for (int i = 0; i < 8; i++) {
        sfSprite_setPosition(map->object_table[i], (sfVector2f)
            {map->object_pos[i].x +
        sfSprite_getPosition(map->map_sprite).x, map->object_pos[i].y +
        sfSprite_getPosition(map->map_sprite).y});
        if (map->is_picked_up[0] == false) {
            sfRenderWindow_drawSprite(game->window, map->object_table[i],
                NULL);
        }
    }
}
