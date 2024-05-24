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

    tab[0] = (sfVector2f){722, 970};
    tab[1] = (sfVector2f){780, 970};
    tab[2] = (sfVector2f){842, 970};
    tab[3] = (sfVector2f){906, 970};
    tab[4] = (sfVector2f){980, 970};
    tab[5] = (sfVector2f){1038, 970};
    tab[6] = (sfVector2f){1100, 970};
    tab[7] = (sfVector2f){1156, 970};
    return tab;
}

static sfIntRect *init_rect_tab(void)
{
    sfIntRect *tab = malloc(sizeof(sfIntRect) * 9);

    tab[0] = (sfIntRect){0, 0, 32, 32};
    tab[1] = (sfIntRect){32, 0, 32, 32};
    tab[2] = (sfIntRect){64, 0, 32, 32};
    tab[3] = (sfIntRect){96, 0, 32, 32};
    tab[4] = (sfIntRect){128, 0, 32, 32};
    tab[5] = (sfIntRect){160, 0, 32, 32};
    tab[6] = (sfIntRect){192, 0, 32, 32};
    tab[7] = (sfIntRect){224, 0, 32, 32};
    tab[8] = (sfIntRect){256, 0, 32, 32};
    return tab;
}

static slot_t **init_slots(sfTexture *items_texture, sfVector2f *pos_tab)
{
    slot_t **slot_tab = malloc(sizeof(slot_t *) * 9);

    for (int i = 0; i < 8; i++) {
        slot_tab[i] = malloc(sizeof(slot_t));
        slot_tab[i]->stored_item = NONE;
        slot_tab[i]->slot = create_sprite(items_texture,
        pos_tab[i], (sfVector2f){1.5, 1.5});
    }
    slot_tab[8] = NULL;
    return slot_tab;
}

void init_inventory(map_screen_t *map)
{
    inventory_t *new_inventory;

    new_inventory = malloc(sizeof(inventory_t));
    new_inventory->items_texture = sfTexture_createFromFile(
    "assets/inventory/items.png", NULL);
    new_inventory->hotbar_texture = sfTexture_createFromFile(
    "assets/inventory/hotbar.png", NULL);
    new_inventory->hotbar = create_sprite(new_inventory->hotbar_texture,
    (sfVector2f){700, 950}, (sfVector2f){8, 8});
    new_inventory->pos_tab = init_pos_tab();
    new_inventory->rect_tab = init_rect_tab();
    new_inventory->slot_tab = init_slots(new_inventory->items_texture,
        new_inventory->pos_tab);
    map->inventory = new_inventory;
}
