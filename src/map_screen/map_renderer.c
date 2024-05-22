/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** map_renderer.c
*/

#include "../../include/rpg.h"

void map_renderer(game_t *game, screen_t *screen)
{
    update_map(game, screen->screen);
}
