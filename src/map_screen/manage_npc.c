/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_npc
*/

#include "../../include/rpg.h"

void init_npc(map_screen_t *map)
{
    map->npc = sfSprite_create();
    sfSprite_setTexture(map->npc, map->player->texture, 0);
    sfSprite_setTextureRect(map->npc, (sfIntRect){64, 0, 32, 32});
    sfSprite_setPosition(map->npc, (sfVector2f){3000, 9000});
    sfSprite_setScale(map->npc, (sfVector2f){3, 3});
}

void display_npc(game_t *game, map_screen_t *map)
{
    sfVector2f pos;

    sfSprite_setPosition(map->npc, (sfVector2f){6 +
        sfSprite_getPosition(map->map_sprite).x, 6910 +
        sfSprite_getPosition(map->map_sprite).y});
    sfRenderWindow_drawSprite(game->window, map->npc, NULL);
}
