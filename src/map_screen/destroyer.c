/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** destroyer.c
*/

#include "../../include/rpg.h"

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
    free(map);
    free(screen);
}
