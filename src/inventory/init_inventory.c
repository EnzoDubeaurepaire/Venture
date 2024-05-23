/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory.c
*/

#include "../../include/rpg.h"

static sfVector2f *init_pos_tab(void)
{
    sfVector2f *tab = malloc(sizeof(sfVector2f) * 8);

    tab[0] = (sfVector2f){0, 0};
    tab[1] = (sfVector2f){0, 0};
    tab[2] = (sfVector2f){0, 0};
    tab[3] = (sfVector2f){0, 0};
    tab[4] = (sfVector2f){0, 0};
    tab[5] = (sfVector2f){0, 0};
    tab[6] = (sfVector2f){0, 0};
    tab[7] = (sfVector2f){0, 0};
    return tab;
}

static slot_t **init_slots(void)
{
    slot_t **slot_tab = malloc(sizeof(slot_t) * 9);

    for (int i = 0; i < 8; i++) {
        slot_tab[i] = malloc(sizeof());
    }
    return slot_tab;
}

void init_inventory(map_screen_t *map)
{
    inventory_t *new_inventory;

    new_inventory = malloc(sizeof(inventory_t));
    new_inventory->hotbar_texture = sfTexture_createFromFile(
    "assets/inventory/hotbar.png", NULL);
    new_inventory->hotbar = create_sprite(new_inventory->hotbar_texture,
    (sfVector2f){0, 0}, (sfVector2f){0, 0});
    new_inventory->pos_tab = init_pos_tab();
    map->inventory = new_inventory;
}