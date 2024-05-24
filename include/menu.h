/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** menu.h
*/

#ifndef MENU_H
    #define MENU_H
    #include "rpg.h"

/*
 * menu.c
*/
void render_menu(game_t *game, screen_t *screen);
screen_t *init_menu(void);

/*
 * buttons_state.c
*/
void check_mouse_on_menu(game_t *game, menu_screen_t *menu);

void end_win(game_t *game, _Bool win);

#endif
