/*
** EPITECH PROJECT, 2023
** rr
** File description:
** rr
*/

#include "../../include/rpg.h"

static void change_volume(settings_screen_t *settings,
    game_t *game, int volume)
{
    char *new_text;

    new_text = malloc(5);
    settings->main_volume += volume;
    sprintf(new_text, "%d %%", settings->main_volume);
    sfText_setString(settings->text_main_volume, new_text);
    free(new_text);
    manage_volume(game->music, settings->main_volume);
}

static void check_refresh_text(settings_screen_t *settings, int mode,
    game_t *game)
{
    if ((settings->main_volume == 100 && mode == 1)
        || (settings->main_volume == 0 && mode == 0))
        return;
    if (mode == 1) {
        change_volume(settings, game, 1);
        return;
    }
    if (mode == 0) {
        change_volume(settings, game, -1);
        return;
    }
}

static void plus_button(game_t *game, settings_screen_t *settings)
{
    sfSprite_setTextureRect(settings->plus_button,
        (sfIntRect){160, 80, 16, 16});
    click_sound(game);
    check_refresh_text(settings, 1, game);
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
    check_refresh_text(settings, 0, game);
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
