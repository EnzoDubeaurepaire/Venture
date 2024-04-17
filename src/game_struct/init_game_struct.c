/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** init_game_struct.c
*/

#include "../../include/rpg.h"

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "Venture", sfResize | sfClose, NULL);
    game->clock = sfClock_create();
    game->launch_screen = init_launch_screen();
    return game;
}
