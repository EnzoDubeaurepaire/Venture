/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** end_win.c
*/

#include "../../include/rpg.h"

static void end_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter)
            exit_game(game);
    }
}

void end_win(game_t *game, _Bool win)
{
    sfTexture *texture;
    sfSprite *sprite;

    if (win)
        texture = sfTexture_createFromFile("assets/menu/win_screen.png", NULL);
    else
        texture = sfTexture_createFromFile("assets/menu/lose_screen.png",
            NULL);
    sprite = sfSprite_create();
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(sprite, texture, 1);
    while (1) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
        sfRenderWindow_display(game->window);
        end_event(game);
    }
}
