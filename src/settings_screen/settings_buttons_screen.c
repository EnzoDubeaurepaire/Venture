/*
** EPITECH PROJECT, 2023
** rr
** File description:
** rr
*/

#include "../../include/rpg.h"

void check_fullscreen_button(game_t *game,
    settings_screen_t *settings, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(settings->fullscreen_button);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        sfSprite_setTextureRect(settings->plus_button,
        (sfIntRect){160, 80, 16, 16});
        update_window(game);
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(settings->fullscreen_button,
        (sfIntRect){0, 80, 16, 16});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(settings->fullscreen_button,
        (sfIntRect){80, 80, 16, 16});
}

void check_1280x720_button(game_t *game,
    settings_screen_t *settings, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(settings->resize_button);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        sfSprite_setTextureRect(settings->resize_button,
        (sfIntRect){176, 80, 16, 16});
        update_resolution(game);
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(settings->resize_button,
        (sfIntRect){16, 80, 16, 16});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(settings->resize_button,
        (sfIntRect){96, 80, 16, 16});
}

void check_1920x1080_button(game_t *game,
    settings_screen_t *settings, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(settings->window_button);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        sfSprite_setTextureRect(settings->window_button,
        (sfIntRect){176, 48, 16, 16});
        update_resolution(game);
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(settings->window_button,
        (sfIntRect){16, 48, 16, 16});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(settings->window_button,
        (sfIntRect){96, 48, 16, 16});
}