/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** free_game_struct.c
*/

#include "../../include/rpg.h"

static void free_dialogue_screen(screen_t *screen)
{
    bubble_t *bubble = screen->screen;

    sfClock_destroy(bubble->clock);
    sfRectangleShape_destroy(bubble->rect);
    sfText_destroy(bubble->text);
    sfFont_destroy(bubble->font);
    free(bubble);
    free(screen);
}

static void free_launch_screen(screen_t *screen)
{
    launch_screen_t *launch_screen = screen->screen;

    sfSprite_destroy(launch_screen->sprite);
    sfTexture_destroy(launch_screen->texture);
    sfRectangleShape_destroy(launch_screen->fade);
    sfText_destroy(launch_screen->text);
    sfFont_destroy(launch_screen->font);
    free(launch_screen);
    free(screen);
}

void free_game(game_t *game)
{
    free_launch_screen(game->screens[0]);
    free_dialogue_screen(game->screens[3]);
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->clock);
    music_destroyer(game->music);
    free(game);
}
