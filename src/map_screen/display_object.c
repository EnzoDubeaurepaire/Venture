/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_object
*/

#include "../../include/rpg.h"

static void get_item_picked_up(game_t *game, int i)
{
    if (i == 7)
        pick_up_item(game, MAP);
    if (i == 6)
        pick_up_item(game, LOG);
    if (i == 0)
        pick_up_item(game, DEBRIS_4);
    if (i == 1)
        pick_up_item(game, DEBRIS_0);
    if (i == 2)
        pick_up_item(game, DEBRIS_3);
    if (i == 3)
        pick_up_item(game, DEBRIS_5);
    if (i == 4)
        pick_up_item(game, DEBRIS_2);
    if (i == 5)
        pick_up_item(game, DEBRIS_1);
}

void pickup_item(game_t *game, map_screen_t *map)
{
    for (int i = 0; i < 8; i++) {
        if (check_sprite_collision(map->player->sprite, map->object_table[i])
            == true && map->is_picked_up[i] == false) {
            map->is_picked_up[i] = true;
            get_item_picked_up(game, i);
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
        if (map->is_picked_up[i] == false) {
            sfRenderWindow_drawSprite(game->window, map->object_table[i],
                NULL);
        }
    }
}

bool get_all_object(map_screen_t *map)
{
    for (int i = 0; i < 6; i++) {
        if (map->is_picked_up[i] == false)
            return false;
    }
    return true;
}
