/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** exit_game.c
*/

#include "../../include/rpg.h"

void exit_game(game_t *game)
{
    sfRenderWindow_close(game->window);
    sfClock_destroy(game->clock);
    for (int i = 0; i < SCREEN_NB; i++)
        game->screen_destroyer[i](game->screens[i]);
    exit(0);
}
