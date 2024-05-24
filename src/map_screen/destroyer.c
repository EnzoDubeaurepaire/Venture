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

static void destroy_enemies(enemy_t **enemies)
{
    for (int i = 0; i < ENEMIES; i++) {
        destroy_entity(enemies[i]->e);
        free(enemies[i]);
    }
    free(enemies);
}

static void free_slots(slot_t **slot_tab)
{
    for (int i = 0; slot_tab[i] != NULL; i++) {
        sfSprite_destroy(slot_tab[i]->slot);
        free(slot_tab[i]);
    }
    free(slot_tab);
}

static void destroy_free_inventory(map_screen_t *map)
{
    inventory_t *inventory = map->inventory;

    sfTexture_destroy(inventory->hotbar_texture);
    sfTexture_destroy(inventory->items_texture);
    sfSprite_destroy(inventory->hotbar);
    free(inventory->rect_tab);
    free(inventory->pos_tab);
    free_slots(inventory->slot_tab);
    free(inventory);
}

static void destroy_attack(entity_t *entity)
{
    sfSprite_destroy(entity->attack);
    sfTexture_destroy(entity->attack_t);
}

static void destroy_sprite(sfSprite *sprite, sfTexture *texture)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void map_screen_destroyer(screen_t *screen)
{
    map_screen_t *map = screen->screen;

    destroy_free_inventory(map);
    sfSprite_destroy(map->mini_map_player);
    sfRectangleShape_destroy(map->mini_map);
    destroy_sprite(map->map_sprite, map->map_texture);
    sfSprite_destroy(map->collision_sprite);
    sfTexture_destroy(map->collision_texture);
    sfImage_destroy(map->image_collision);
    destroy_attack(map->player);
    destroy_entity(map->player);
    destroy_sprint(map->sprint);
    destroy_enemies(map->enemies);
    sfSprite_destroy(map->bush_sprite);
    sfTexture_destroy(map->bush_texture);
    sfCircleShape_destroy(map->player_reach);
    sfSprite_destroy(map->health_bar);
    sfTexture_destroy(map->health_bar_t);
    free(map);
    free(screen);
}
