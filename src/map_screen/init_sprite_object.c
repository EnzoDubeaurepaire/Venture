/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_sprite_object.c
*/

#include "../../include/rpg.h"

static void set_texture(map_screen_t *map)
{
    map->object_texture[0] = sfTexture_createFromFile
        ("assets/inventory/piece1.png", NULL);
    map->object_texture[1] = sfTexture_createFromFile
        ("assets/inventory/piece2.png", NULL);
    map->object_texture[2] = sfTexture_createFromFile
        ("assets/inventory/piece3.png", NULL);
    map->object_texture[3] = sfTexture_createFromFile
        ("assets/inventory/piece4.png", NULL);
    map->object_texture[4] = sfTexture_createFromFile
        ("assets/inventory/piece5.png", NULL);
    map->object_texture[5] = sfTexture_createFromFile
        ("assets/inventory/piece6.png", NULL);
    map->object_texture[6] = sfTexture_createFromFile
        ("assets/inventory/log.png", NULL);
    map->object_texture[7] = sfTexture_createFromFile
        ("assets/inventory/mini_map.png", NULL);
}

static void set_next_sprite(map_screen_t *map)
{
    sfSprite_setTexture(map->object_table[4], map->object_texture[4], 1);
    sfSprite_setOrigin(map->object_table[4], (sfVector2f){
        (float)sfTexture_getSize(map->object_texture[4]).x / 2,
        (float)sfTexture_getSize(map->object_texture[4]).y / 2});
    sfSprite_setTexture(map->object_table[5], map->object_texture[5], 1);
    sfSprite_setOrigin(map->object_table[5], (sfVector2f){
        (float)sfTexture_getSize(map->object_texture[5]).x / 2,
        (float)sfTexture_getSize(map->object_texture[5]).y / 2});
    sfSprite_setTexture(map->object_table[6], map->object_texture[6], 1);
    sfSprite_setOrigin(map->object_table[6], (sfVector2f){
        (float)sfTexture_getSize(map->object_texture[6]).x / 2,
        (float)sfTexture_getSize(map->object_texture[6]).y / 2});
    sfSprite_setTexture(map->object_table[7], map->object_texture[7], 1);
    sfSprite_setOrigin(map->object_table[7], (sfVector2f){
        (float)sfTexture_getSize(map->object_texture[7]).x / 2,
        (float)sfTexture_getSize(map->object_texture[7]).y / 2});
}

static void set_sprite(map_screen_t *map)
{
    sfSprite_setTexture(map->object_table[0], map->object_texture[0], 1);
    sfSprite_setOrigin(map->object_table[0], (sfVector2f){
        (float)sfTexture_getSize(map->object_texture[0]).x / 2,
        (float)sfTexture_getSize(map->object_texture[0]).y / 2});
    sfSprite_setTexture(map->object_table[1], map->object_texture[1], 1);
    sfSprite_setOrigin(map->object_table[1], (sfVector2f){
        (float)sfTexture_getSize(map->object_texture[1]).x / 2,
        (float)sfTexture_getSize(map->object_texture[1]).y / 2});
    sfSprite_setTexture(map->object_table[2], map->object_texture[2], 1);
    sfSprite_setOrigin(map->object_table[2], (sfVector2f){
        (float)sfTexture_getSize(map->object_texture[2]).x / 2,
        (float)sfTexture_getSize(map->object_texture[2]).y / 2});
    sfSprite_setTexture(map->object_table[3], map->object_texture[3], 1);
    sfSprite_setOrigin(map->object_table[3], (sfVector2f){
        (float)sfTexture_getSize(map->object_texture[3]).x / 2,
        (float)sfTexture_getSize(map->object_texture[3]).y / 2});
}

static void init_pos_object(map_screen_t *map)
{
    map->object_pos[0] = (sfVector2f){1150, 4450};
    map->object_pos[1] = (sfVector2f){3000, 9000};
    map->object_pos[2] = (sfVector2f){7550, 100};
    map->object_pos[3] = (sfVector2f){5500, 6550};
    map->object_pos[4] = (sfVector2f){9000, 9000};
    map->object_pos[5] = (sfVector2f){5000, 4800};
    map->object_pos[6] = (sfVector2f){700, 600};
    map->object_pos[7] = (sfVector2f){1800, 1000};
    for (int i = 0; i < 8; i++) {
        sfSprite_setPosition(map->object_table[i], map->object_pos[i]);
        map->is_picked_up[i] = false;
    }
}

void init_sprite_object(map_screen_t *map)
{
    set_texture(map);
    map->object_table[0] = sfSprite_create();
    map->object_table[1] = sfSprite_create();
    map->object_table[2] = sfSprite_create();
    map->object_table[3] = sfSprite_create();
    map->object_table[4] = sfSprite_create();
    map->object_table[5] = sfSprite_create();
    map->object_table[6] = sfSprite_create();
    map->object_table[7] = sfSprite_create();
    set_sprite(map);
    set_next_sprite(map);
    init_pos_object(map);
    map->bridge_repared = false;
    map->is_end = false;
}
