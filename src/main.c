/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** my_rpg
*/

#include "rpg.h"

void render_active_screen(game_t *game)
{
    for (int i = 0; game->screen_renderer[i]; i++) {
        if (game->active_screen & (1 << i))
            game->screen_renderer[i](game, game->screens[i]);
    }
}

int main(void)
{
    game_t *game = init_game();

    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        render_active_screen(game);
        game->last_frame_time =
            sfClock_getElapsedTime(game->clock).microseconds;
        sfRenderWindow_display(game->window);
        poll_event(game);
        music_manager(game);
    }
    free_game(game);
}
