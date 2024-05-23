/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** show_inventory.c
*/

#include "../../include/rpg.h"

void show_inventory_map(game_t *game, map_screen_t *map_screen)
{
    inventory_t *inventory = map_screen->inventory;

    sfRenderWindow_drawSprite(game->window, inventory->hotbar, NULL);
    for (int i = 0; i < 8; i++) {
        if (inventory->slot_tab[i]->stored_item != NONE) {
            sfRenderWindow_drawSprite(game->window,
            inventory->slot_tab[i]->slot, NULL);
        }
    }
}
