/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** get_mouse_pos.c
*/

#include "../../include/rpg.h"

sfVector2i get_mouse(game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->window);
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2i res = (game->resolution_state) ? (sfVector2i){1280, 720} :
        (sfVector2i){1920, 1080};

    pos.x *= res.x / (int)size.x;
    pos.y *= res.y / (int)size.y;
    return pos;
}
