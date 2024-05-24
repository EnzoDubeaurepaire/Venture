/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** music_destroyer.c
*/

#include "../../include/rpg.h"

void music_destroyer(music_t *music)
{
    sfMusic_destroy(music->menu_music);
    sfMusic_destroy(music->typing_music);
    sfMusic_destroy(music->button_click);
    free(music);
}
