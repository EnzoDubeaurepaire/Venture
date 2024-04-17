/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** free_game_struct.c
*/

#include "../../include/rpg.h"

static void free_launch_screen(launch_screen_t *launch_screen)
{
    sfSprite_destroy(launch_screen->sprite);
    sfTexture_destroy(launch_screen->texture);
    sfRectangleShape_destroy(launch_screen->fade);
    sfText_destroy(launch_screen->text);
    sfFont_destroy(launch_screen->font);
    free(launch_screen);
}

void free_game(game_t *game)
{
    free_launch_screen(game->launch_screen);
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->clock);
    free(game);
}
