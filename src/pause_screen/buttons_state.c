/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** buttons_state.c
*/

#include "rpg.h"

static void check_mouse_save(game_t *game, pause_screen_t *pause,
    sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(pause->save);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(pause->save, (sfIntRect){380, 137, 380,
            137});
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold)
        sfSprite_setTextureRect(pause->save, (sfIntRect){760, 137, 380,
            137});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(pause->save, (sfIntRect){0, 137, 380,
            137});
}

static void setting_button(game_t *game)
{
    game->active_screen ^= SETTINGS_SCREEN;
    click_sound(game);
}

static void check_mouse_settings(game_t *game, pause_screen_t *pause,
    sfVector2f pos, sfFloatRect rect)
{
    static _Bool pressed = 0;

    if (pressed == 1 && !game->mouse_hold
        && sfFloatRect_contains(&rect, pos.x, pos.y)) {
        pressed = 0;
        setting_button(game);
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(pause->sett,
            (sfIntRect){380, 274, 380, 137});
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        sfSprite_setTextureRect(pause->sett,
            (sfIntRect){760, 274, 380, 137});
        pressed = 1;
        return;
    }
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(pause->sett, (sfIntRect){0, 274, 380, 137});
    pressed = 0;
}

static void characteristic_button(game_t *game)
{
    game->active_screen ^= PAUSE_SCREEN;
    game->active_screen ^= STATS_SCREEN;
    click_sound(game);
}

static void check_mouse_characteristics(game_t *game, pause_screen_t *pause,
    sfVector2f pos, sfFloatRect rect)
{
    static _Bool pressed = 0;

    if (pressed == 1 && sfFloatRect_contains(&rect, pos.x, pos.y) &&
        !game->mouse_hold) {
        characteristic_button(game);
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        sfSprite_setTextureRect(pause->chara, (sfIntRect)
            {760, 0, 380, 137});
        pressed = 1;
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(pause->chara, (sfIntRect)
            {380, 0, 380, 137});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(pause->chara, (sfIntRect){0, 0, 380, 137});
    pressed = 0;
}

static void quite_button(game_t *game)
{
    click_sound(game);
    usleep(0.5);
    exit_game(game);
}

static void check_mouse_quit(game_t *game, pause_screen_t *pause,
    sfVector2f pos, sfFloatRect rect)
{
    static _Bool pressed = 0;

    if (pressed == 1 && !game->mouse_hold &&
        sfFloatRect_contains(&rect, pos.x, pos.y)) {
        quite_button(game);
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        sfSprite_setTextureRect(pause->quit, (sfIntRect) {760, 411, 380,
            137});
        pressed = 1;
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(pause->quit, (sfIntRect){380, 411, 380,
            137});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(pause->quit, (sfIntRect){0, 411, 380,
            137});
    pressed = 0;
}

void check_mouse_on_pause(game_t *game, pause_screen_t *pause)
{
    sfVector2i pos = get_mouse(game);

    check_mouse_save(game, pause, (sfVector2f){(float)pos.x, (float)pos.y});
    check_mouse_characteristics(game, pause, (sfVector2f){(float)pos.x,
        (float)pos.y}, sfSprite_getGlobalBounds(pause->chara));
    check_mouse_settings(game, pause, (sfVector2f){(float)pos.x, (float)pos.y},
        sfSprite_getGlobalBounds(pause->sett));
    check_mouse_quit(game, pause, (sfVector2f){(float)pos.x, (float)pos.y},
        sfSprite_getGlobalBounds(pause->quit));
}
