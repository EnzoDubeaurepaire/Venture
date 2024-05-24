/*
** EPITECH PROJECT, 2023
** my_rgp
** File description:
** init_music.c
*/

#include "../../include/rpg.h"

music_t *init_music(void)
{
    music_t *music = malloc(sizeof(music_t));

    music->menu_music = sfMusic_createFromFile("assets/music/journey.ogg");
    music->typing_music = sfMusic_createFromFile(
        "assets/music/keyboard_sound.ogg");
    music->button_click = sfMusic_createFromFile(
        "assets/music/button.ogg");
    music->walking = sfMusic_createFromFile
        ("assets/music/exploration_positive.ogg");
    return music;
}
