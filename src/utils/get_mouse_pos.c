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

    pos.x *= 1920 / (int)size.x;
    pos.y *= 1080 / (int)size.y;
    return pos;
}
