/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** destroyer.c
*/

#include "../../include/rpg.h"

void pause_screen_destroyer(screen_t *screen)
{
    pause_screen_t *pause = screen->screen;

    sfSprite_destroy(pause->quit);
    sfTexture_destroy(pause->texture);
    sfSprite_destroy(pause->save);
    sfSprite_destroy(pause->chara);
    sfSprite_destroy(pause->sett);
    free(pause);
    free(screen);
}
