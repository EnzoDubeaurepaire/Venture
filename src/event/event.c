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

static void update_window(game_t *game)
{
    const sfView *view = sfRenderWindow_getView(game->window);
    sfView *new_view = sfView_copy(view);

    if (game->window_state == 0) {
        game->window_state = 1;
        sfRenderWindow_close(game->window);
        game->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
            "Venture", sfClose | sfResize, NULL);
        sfRenderWindow_setFramerateLimit(game->window, 60);
        sfRenderWindow_setView(game->window, new_view);
    } else {
        game->window_state = 0;
        sfRenderWindow_close(game->window);
        game->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
            "Venture", sfFullscreen, NULL);
        sfRenderWindow_setFramerateLimit(game->window, 60);
    }
    sfRenderWindow_setSize(game->window, (sfVector2u){1920, 1080});
}

void poll_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyEscape))
            sfRenderWindow_close(game->window);
        if (game->active_screen & LAUNCH_SCREEN && !(game->active_screen &
            MENU_SCREEN) && event.type == sfEvtKeyPressed && event.key.code
            == sfKeyEnter) {
            game->active_screen |= MENU_SCREEN;
            ((launch_screen_t *)game->screens[0]->screen)->vanish_clock =
                sfClock_create();
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyY &&
            (game->active_screen & MAP_SCREEN))
            game->active_screen ^= STATS_SCREEN;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA)
            update_window(game);
        event_mouse_keybord(game, event);
    }
}
