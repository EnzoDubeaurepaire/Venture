/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** event.c
*/

#include "../../include/rpg.h"

static void event_hitbox(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyH) {
        if (((map_screen_t *) (game->screens[2]->screen))->player->is_hitbox
            == sfTrue)
            ((map_screen_t *) (game->screens[2]->screen))->player->is_hitbox
            = sfFalse;
        else
            ((map_screen_t *)(game->screens[2]->screen))->player->is_hitbox =
            sfTrue;
    }
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyE &&
        (game->active_screen & DIALOGUE_SCREEN) == 0) {
        game->active_screen |= DIALOGUE_SCREEN;
        ((bubble_t *)(game->screens[3]->screen))->message = "ca marche ?";
        ((bubble_t *)(game->screens[3]->screen))->compteur = 0;
        ((bubble_t *)(game->screens[3]->screen))->skip_animation = sfFalse;
    }
}

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
    event_hitbox(game, event);
}

void update_resolution(game_t *game)
{
    const sfView *view = sfRenderWindow_getView(game->window);
    sfVideoMode mode;

    click_sound(game);
    if (game->resolution_state == 0) {
        game->resolution_state = 1;
        mode = (sfVideoMode){1280, 720, 32};
    } else {
        game->resolution_state = 0;
        mode = (sfVideoMode){1920, 1080, 32};
    }
    sfRenderWindow_close(game->window);
    game->window = sfRenderWindow_create(mode, "Venture", (sfFullscreen *
        game->window_state == 0) | (sfResize *
        game->window_state == 1) | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setView(game->window, sfView_copy(view));
}

void update_window(game_t *game)
{
    const sfView *view = sfRenderWindow_getView(game->window);
    sfVideoMode mode = (game->resolution_state) ? (sfVideoMode){1280,
        720, 32} : (sfVideoMode){1920, 1080, 32};

    click_sound(game);
    if (game->window_state == 0) {
        game->window_state = 1;
        sfRenderWindow_close(game->window);
        game->window = sfRenderWindow_create(mode,
            "Venture", sfClose | sfResize, NULL);
        sfRenderWindow_setFramerateLimit(game->window, 60);
    } else {
        game->window_state = 0;
        sfRenderWindow_close(game->window);
        game->window = sfRenderWindow_create(mode,
            "Venture", sfFullscreen, NULL);
        sfRenderWindow_setFramerateLimit(game->window, 60);
    }
    sfRenderWindow_setView(game->window, sfView_copy(view));
    sfRenderWindow_setSize(game->window, (sfVector2u){1920, 1080});
}

static void event_resolution(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA)
        update_window(game);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR)
        update_resolution(game);
}

static void check_echap(sfEvent event, game_t *game)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape
        && (game->active_screen & MAP_SCREEN) && !(game->active_screen
        & STATS_SCREEN))
        game->active_screen ^= PAUSE_SCREEN;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape
        && (game->active_screen & MAP_SCREEN) && (game->active_screen
        & STATS_SCREEN))
        game->active_screen ^= STATS_SCREEN;
}

static void event_tuto(game_t *game, sfEvent event)
{
    if (((launch_screen_t *)game->screens[0]->screen)->show_tuto &&
        game->active_screen & LAUNCH_SCREEN && event.type == sfEvtKeyPressed
        && event.key.code == sfKeyEnter) {
        game->active_screen = 0;
        game->active_screen |= MAP_SCREEN;
    }
}

void poll_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            exit_game(game);
        check_echap(event, game);
        if (game->active_screen & LAUNCH_SCREEN && !(game->active_screen &
            MENU_SCREEN) && event.type == sfEvtKeyPressed && event.key.code
            == sfKeyEnter) {
            game->active_screen |= MENU_SCREEN;
            ((launch_screen_t *)game->screens[0]->screen)->vanish_clock =
                sfClock_create();
        }
        event_tuto(game, event);
        event_resolution(game, event);
        event_mouse_keybord(game, event);
    }
}
