/*
** EPITECH PROJECT, 2023
** rr
** File description:
** rr
*/

#include "../../include/rpg.h"

static void check_refresh_text(settings_screen_t *settings, int mode)
{
    char *new_text;

    if ((settings->main_volume == 100 && mode == 1)
        || (settings->main_volume == 0 && mode == 0))
        return;
    new_text = malloc(5);
    if (mode == 1) {
        settings->main_volume += 1;
        sprintf(new_text, "%d %%", settings->main_volume);
        sfText_setString(settings->text_main_volume, new_text);
        free(new_text);
        return;
    }
    if (mode == 0) {
        settings->main_volume -= 1;
        sprintf(new_text, "%d %%", settings->main_volume);
        sfText_setString(settings->text_main_volume, new_text);
        free(new_text);
        return;
    }
}

static void plus_button(game_t *game, settings_screen_t *settings)
{
    sfSprite_setTextureRect(settings->plus_button,
        (sfIntRect){160, 80, 16, 16});
    click_sound(game);
    check_refresh_text(settings, 1);
}

void check_plus_button(game_t *game,
    settings_screen_t *settings, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(settings->plus_button);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        plus_button(game, settings);
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(settings->plus_button,
        (sfIntRect){0, 80, 16, 16});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(settings->plus_button,
        (sfIntRect){80, 80, 16, 16});
}

static void minus_button(game_t *game, settings_screen_t *settings)
{
    sfSprite_setTextureRect(settings->minus_button,
        (sfIntRect){176, 80, 16, 16});
    check_refresh_text(settings, 0);
    click_sound(game);
}

void check_minus_button(game_t *game,
    settings_screen_t *settings, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(settings->minus_button);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        minus_button(game, settings);
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(settings->minus_button,
        (sfIntRect){16, 80, 16, 16});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(settings->minus_button,
            (sfIntRect){96, 80, 16, 16});
}

static void cross_button(game_t *game, settings_screen_t *settings)
{
    sfSprite_setTextureRect(settings->cross, (sfIntRect){176, 48, 16, 16});
    game->active_screen ^= SETTINGS_SCREEN;
    click_sound(game);
}

void check_cross_button(game_t *game,
    settings_screen_t *settings, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(settings->cross);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        cross_button(game, settings);
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(settings->cross,
        (sfIntRect){16, 48, 16, 16});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(settings->cross,
        (sfIntRect){96, 48, 16, 16});
}
