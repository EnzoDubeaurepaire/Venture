/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** destroyer.c
*/

#include "../../include/rpg.h"

static void destroy_object_sprite(map_screen_t *map)
{
    sfSprite_destroy(map->object_table[0]);
    sfSprite_destroy(map->object_table[1]);
    sfSprite_destroy(map->object_table[2]);
    sfSprite_destroy(map->object_table[3]);
    sfSprite_destroy(map->object_table[4]);
    sfSprite_destroy(map->object_table[5]);
    sfSprite_destroy(map->object_table[6]);
    sfSprite_destroy(map->object_table[7]);
    sfTexture_destroy(map->object_texture[0]);
    sfTexture_destroy(map->object_texture[1]);
    sfTexture_destroy(map->object_texture[2]);
    sfTexture_destroy(map->object_texture[3]);
    sfTexture_destroy(map->object_texture[4]);
    sfTexture_destroy(map->object_texture[5]);
    sfTexture_destroy(map->object_texture[6]);
    sfTexture_destroy(map->object_texture[7]);
}

static void destroy_sprint(sprint_t *sprint)
{
    sfTexture_destroy(sprint->texture);
    sfSprite_destroy(sprint->sprite);
    free(sprint);
}

static void destroy_entity(entity_t *entity)
{
    sfSprite_destroy(entity->sprite);
    sfTexture_destroy(entity->texture);
    sfRectangleShape_destroy(entity->hitbox);
    free(entity);
}

void map_screen_destroyer(screen_t *screen)
{
    map_screen_t *map = screen->screen;

    sfSprite_destroy(map->mini_map_player);
    sfRectangleShape_destroy(map->mini_map);
    sfSprite_destroy(map->map_sprite);
    sfTexture_destroy(map->map_texture);
    sfSprite_destroy(map->collision_sprite);
    sfTexture_destroy(map->collision_texture);
    sfImage_destroy(map->image_collision);
    destroy_entity(map->player);
    destroy_sprint(map->sprint);
    sfSprite_destroy(map->bush_sprite);
    sfTexture_destroy(map->bush_texture);
    destroy_object_sprite(map);
    free(map);
    free(screen);
}
