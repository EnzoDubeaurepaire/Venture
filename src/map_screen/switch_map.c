/*
** EPITECH PROJECT, 2023
** rpg.h
** File description:
** switch_map.c
*/

#include "../../include/rpg.h"

static void switch_image(map_screen_t *map, sfVector2f pos)
{
    map->map_sprite = sfSprite_create();
    sfSprite_setTexture(map->map_sprite, map->map_texture, true);
    sfSprite_setScale(map->map_sprite, (sfVector2f){3, 3});
    sfSprite_setPosition(map->map_sprite, pos);
    sfRectangleShape_setTexture(map->mini_map, map->map_texture, true);
    sfImage_destroy(map->image_collision);
    map->image_collision = sfTexture_copyToImage(map->collision_texture);
}

void switch_map(map_screen_t *map)
{
    sfVector2f pos = sfSprite_getPosition(map->collision_sprite);

    map->got_wood = true;
    sfSprite_destroy(map->collision_sprite);
    sfTexture_destroy(map->collision_texture);
    map->collision_texture = sfTexture_createFromFile(
        "assets/collision.png", NULL);
    map->collision_sprite = sfSprite_create();
    sfSprite_setTexture(map->collision_sprite, map->collision_texture, true);
    sfSprite_setScale(map->collision_sprite, (sfVector2f){3, 3});
    sfSprite_setPosition(map->collision_sprite, pos);
    sfSprite_destroy(map->map_sprite);
    sfTexture_destroy(map->map_texture);
    map->map_texture = sfTexture_createFromFile(
        "assets/map.png", NULL);
    switch_image(map, pos);
}
