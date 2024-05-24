/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pick_up_item.c
*/

#include "../../include/rpg.h"

sfIntRect get_rect(inventory_t *inventory, enum items item)
{
    return inventory->rect_tab[item];
}

void pick_up_item(game_t *game, enum items item)
{
    map_screen_t *map = game->screens[2]->screen;
    inventory_t *inventory = map->inventory;

    for (int i = 0; i < 8; i++) {
        if ((item >= NONE && item <= DEBRIS_5)
        && inventory->slot_tab[i]->stored_item == NONE) {
            inventory->slot_tab[i]->stored_item = item;
            sfSprite_setTextureRect(inventory->slot_tab[i]->slot,
            get_rect(inventory, item));
            return;
        }
    }
}
