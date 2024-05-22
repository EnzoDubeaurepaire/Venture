/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** pause_screen.h
*/

#ifndef PAUSE_SCREEN_H
    #define PAUSE_SCREEN_H
    #include "rpg.h"

/*
 * pause.c
*/
screen_t *init_pause(void);
void render_pause(game_t *game, screen_t *screen);

/*
 * buttons_state.c
*/
void check_mouse_on_pause(game_t *game, pause_screen_t *pause);

#endif
