/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** destroyer.c
*/

#include "../../include/rpg.h"

void menu_destroyer(screen_t *screen)
{
    menu_screen_t *menu = screen->screen;

    sfTexture_destroy(menu->texture);
    sfClock_destroy(menu->clock);
    sfSprite_destroy(menu->settings);
    sfSprite_destroy(menu->quit);
    sfSprite_destroy(menu->resume);
    sfSprite_destroy(menu->new_game);
    free(menu);
    free(screen);
}
