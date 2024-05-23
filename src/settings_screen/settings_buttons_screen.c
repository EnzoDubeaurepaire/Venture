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
    static _Bool pressed = 0;

    if (pressed == 1 && sfFloatRect_contains(&rect, pos.x, pos.y) &&
        !game->mouse_hold) {
        update_window(game);
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        sfSprite_setTextureRect(settings->fullscreen_button, (sfIntRect)
            {762, 10, 376, 126});
        pressed = 1;
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(settings->fullscreen_button, (sfIntRect)
            {382, 6, 376, 133});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(settings->fullscreen_button, (sfIntRect)
            {8, 8, 364, 121});
    pressed = 0;
}

void check_1280x720_button(game_t *game,
    settings_screen_t *settings, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(settings->resize_button);
    static _Bool pressed = 0;

    if (pressed == 1 && sfFloatRect_contains(&rect, pos.x, pos.y) &&
        !game->mouse_hold) {
        update_resolution(game);
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        sfSprite_setTextureRect(settings->resize_button, (sfIntRect)
            {762, 284, 376, 126});
        pressed = 1;
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(settings->resize_button, (sfIntRect)
            {382, 280, 376, 133});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(settings->resize_button, (sfIntRect)
            {8, 282, 364, 121});
    pressed = 0;
}

void check_1920x1080_button(game_t *game,
    settings_screen_t *settings, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(settings->window_button);
    static _Bool pressed = 0;

    if (pressed == 1 && sfFloatRect_contains(&rect, pos.x, pos.y) &&
        !game->mouse_hold) {
        update_resolution(game);
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        sfSprite_setTextureRect(settings->window_button, (sfIntRect)
            {762, 149, 376, 126});
        pressed = 1;
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(settings->window_button, (sfIntRect)
            {382, 145, 376, 133});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(settings->window_button, (sfIntRect)
            {8, 147, 364, 121});
    pressed = 0;
}
