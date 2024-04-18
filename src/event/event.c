/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** event.c
*/

#include "../../include/rpg.h"

void poll_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyEscape))
            sfRenderWindow_close(game->window);
        if (game->active_screen & LAUNCH_SCREEN && !(game->active_screen &
            MENU_SCREEN) && event.type == sfEvtKeyPressed && event.key.code
            == sfKeyEnter)
            game->active_screen |= MENU_SCREEN;
        if (event.type == sfEvtMouseButtonPressed)
            game->mouse_hold = 1;
        if (event.type == sfEvtMouseButtonReleased)
            game->mouse_hold = 0;
    }
}
