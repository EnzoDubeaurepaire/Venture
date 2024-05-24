/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** inventory.h
*/

#ifndef INVENTORY_H
    #define INVENTORY_H
    #include "rpg.h"
    #include "struct.h"

/*
 * init_inventory.c
*/
void init_inventory(map_screen_t *map);

/*
 * show_inventory.c
*/
void show_inventory_map(game_t *game, map_screen_t *map_screen);

/*
 * pick_up_item.c
*/
void pick_up_item(game_t *game, enum items item);

#endif
