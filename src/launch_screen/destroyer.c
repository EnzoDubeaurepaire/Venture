/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** destroyer.c
*/

#include "../../include/rpg.h"

void launch_screen_destroyer(screen_t *screen)
{
    launch_screen_t *launch = screen->screen;

    sfTexture_destroy(launch->texture);
    sfText_destroy(launch->text);
    sfSprite_destroy(launch->sprite);
    sfFont_destroy(launch->font);
    sfRectangleShape_destroy(launch->fade);
    sfClock_destroy(launch->vanish_clock);
    free(launch);
    free(screen);
}
