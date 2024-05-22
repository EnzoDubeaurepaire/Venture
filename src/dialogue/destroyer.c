/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** destroyer.c
*/

#include "../../include/rpg.h"

void dialogue_destroyer(screen_t *screen)
{
    bubble_t *bubble = screen->screen;

    sfFont_destroy(bubble->font);
    sfClock_destroy(bubble->clock);
    sfText_destroy(bubble->text);
    sfRectangleShape_destroy(bubble->rect);
    free(bubble);
    free(screen);
}
