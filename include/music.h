/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** music.h
*/


#ifndef MUSIC_H
    #define MUSIC_H
    #include "rpg.h"

/*
 * init_music.c
*/
music_t *init_music(void);

/*
 * music.c
*/
void music_manager(game_t *game);
void click_sound(game_t *game);

/*
 * music_destroyer.c
*/
void music_destroyer(music_t *music);

#endif //MUSIC_H
