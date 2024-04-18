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
    game->screens[SCREEN_NB] = NULL;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "Venture", sfResize | sfClose, NULL);
    game->clock = sfClock_create();
    init_screens(game);
    game->active_screen = LAUNCH_SCREEN;
    for (int i = 0; renderers[i]; i++)
        game->screen_renderer[i] = renderers[i];
    game->screen_renderer[SCREEN_NB] = NULL;
    return game;
}
