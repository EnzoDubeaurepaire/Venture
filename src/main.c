/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** my_rpg
*/

#include "rpg.h"

int main(void)
{
    game_t *game = init_game();
    sfEvent event;

    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        render_launch_screen(game, game->launch_screen);
        sfRenderWindow_display(game->window);
        poll_event(game);
    }
    free_game(game);
}
