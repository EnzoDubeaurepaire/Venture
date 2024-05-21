/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** settings_screen.h
*/

#ifndef SETTINGS_OVERLAY_H
    #define SETTINGS_OVERLAY_H
    #include "rpg.h"

void render_settings(game_t *game, screen_t *screen);
screen_t *init_settings_screen(void);
void check_plus_button(game_t *game,
    settings_screen_t *settings, sfVector2f pos);
void check_minus_button(game_t *game,
    settings_screen_t *settings, sfVector2f pos);
void check_cross_button(game_t *game,
    settings_screen_t *settings, sfVector2f pos);

#endif
