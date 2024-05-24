/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_object
*/

#include "../../include/rpg.h"

void show_bush(game_t *game, map_screen_t *map)
{
    static int display = 0;

    if (check_sprite_collision(map->player->sprite, map->bush_sprite) == true
        && game->key == sfKeyE) {
        map->got_wood = 1;
        display = 1;
    }
    if (display == 1) {
        sfRenderWindow_drawSprite(game->window, map->player->sprite, NULL);
        return;
    }
    if (sfSprite_getPosition(map->bush_sprite).y <
        sfSprite_getPosition(map->player->sprite).y - 90) {
        sfRenderWindow_drawSprite(game->window, map->bush_sprite, NULL);
        sfRenderWindow_drawSprite(game->window, map->player->sprite, NULL);
    } else {
        sfRenderWindow_drawSprite(game->window, map->player->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, map->bush_sprite, NULL);
    }
}

