/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** event.c
*/

#include "../../include/rpg.h"

static void event_mouse_keybord(game_t *game, sfEvent event)
{
    static _Bool key_pressed = 0;

    game->key = -1;
    if (event.type == sfEvtMouseButtonPressed)
        game->mouse_hold = 1;
    if (event.type == sfEvtMouseButtonReleased)
        game->mouse_hold = 0;
    if (event.type == sfEvtKeyPressed && key_pressed == 0)
        key_pressed = 1;
    if (key_pressed && event.type == sfEvtKeyReleased) {
        key_pressed = 0;
        game->key = event.key.code;
    }
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyE &&
        (game->active_screen & DIALOGUE_SCREEN) == 0) {
        game->active_screen |= DIALOGUE_SCREEN;
        ((bubble_t *)(game->screens[3]->screen))->message = "ca marche ?";
        ((bubble_t *)(game->screens[3]->screen))->compteur = 0;
        ((bubble_t *)(game->screens[3]->screen))->skip_animation = sfFalse;
    }
}

void poll_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (game->active_screen & LAUNCH_SCREEN && !(game->active_screen &
            MENU_SCREEN) && event.type == sfEvtKeyPressed && event.key.code
            == sfKeyEnter) {
            game->active_screen |= MENU_SCREEN;
            ((launch_screen_t *)game->screens[0]->screen)->vanish_clock =
                sfClock_create();
        }
        event_mouse_keybord(game, event);
    }
}
