/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** init_game_struct.c
*/

#include "../../include/rpg.h"

static void init_screens(game_t *game)
{
    game->screens[0] = init_launch_screen();
    game->screens[1] = init_menu();
    game->screens[2] = init_map();
    game->screens[3] = init_bubble(game->window);
    game->screens[4] = init_pause();
    game->screens[5] = init_stats();
    game->screens[6] = init_settings_screen();
    game->screens[SCREEN_NB] = NULL;
}

static void step_init(game_t *game)
{
    game->last_frame_time = 0;
    game->mouse_hold = 0;
    game->window_state = 0;
    game->is_new_game = false;
    game->resolution_state = 0;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "Venture", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setTitle(game->window, "Venture");
    game->clock = sfClock_create();
    init_screens(game);
    game->active_screen = LAUNCH_SCREEN;
    for (int i = 0; renderers[i]; i++) {
        game->screen_renderer[i] = renderers[i];
        game->screen_destroyer[i] = destroyers[i];
    }
    game->screen_renderer[SCREEN_NB] = NULL;
    step_init(game);
    game->music = init_music();
    return game;
}
