/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** buttons_state.c
*/

#include "../../include/rpg.h"

static void start(game_t *game)
{
    click_sound(game);
    game->active_screen = 0;
    game->active_screen |= MAP_SCREEN;
    check_save(game);
}

static void check_mouse_resume(game_t *game, menu_screen_t *menu,
    sfVector2f pos, sfFloatRect rect)
{
    static _Bool pressed = 0;

    if (pressed == 1 && !game->mouse_hold
        && sfFloatRect_contains(&rect, pos.x, pos.y)) {
        start(game);
        pressed = 0;
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(menu->resume,
            (sfIntRect){380, 137, 380, 137});
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        sfSprite_setTextureRect(menu->resume,
            (sfIntRect){760, 137, 380, 137});
        pressed = 1;
        return;
    }
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(menu->resume, (sfIntRect){0, 137, 380, 137});
    pressed = 0;
}

static void settings_button(game_t *game)
{
    game->active_screen ^= SETTINGS_SCREEN;
    click_sound(game);
}

static void check_mouse_settings(game_t *game, menu_screen_t *menu,
    sfVector2f pos, sfFloatRect rect)
{
    static _Bool pressed = 0;

    if (pressed == 1 && !game->mouse_hold
        && sfFloatRect_contains(&rect, pos.x, pos.y)) {
        pressed = 0;
        settings_button(game);
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(menu->settings,
        (sfIntRect){380, 274, 380, 137});
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        sfSprite_setTextureRect(menu->settings,
        (sfIntRect){760, 274, 380, 137});
        pressed = 1;
        return;
    }
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(menu->settings, (sfIntRect){0, 274, 380, 137});
    pressed = 0;
}

static void new_game_button(game_t *game)
{
    click_sound(game);
    game->active_screen ^= MENU_SCREEN;
    ((launch_screen_t *)game->screens[0]->screen)->show_tuto = 1;
}

static void check_mouse_new_game(game_t *game, menu_screen_t *menu,
    sfVector2f pos, sfFloatRect rect)
{
    static _Bool pressed = 0;

    if (pressed == 1 && sfFloatRect_contains(&rect, pos.x, pos.y) &&
        !game->mouse_hold) {
        new_game_button(game);
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        sfSprite_setTextureRect(menu->new_game, (sfIntRect){760, 0, 380, 137});
        pressed = 1;
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold) {
        sfSprite_setTextureRect(menu->new_game, (sfIntRect){380, 0, 380, 137});
    }
    if (!sfFloatRect_contains(&rect, pos.x, pos.y)) {
        sfSprite_setTextureRect(menu->new_game, (sfIntRect) {0, 0, 380, 137});
    }
    pressed = 0;
}

static void quite_button(game_t *game)
{
    click_sound(game);
    usleep(0.5);
    exit_game(game);
}

static void check_mouse_quit(game_t *game, menu_screen_t *menu, sfVector2f pos,
    sfFloatRect rect)
{
    static _Bool pressed = 0;

    if (pressed == 1 && !game->mouse_hold &&
        sfFloatRect_contains(&rect, pos.x, pos.y)) {
        quite_button(game);
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold) {
        sfSprite_setTextureRect(menu->quit, (sfIntRect) {760, 411, 380,
            137});
        pressed = 1;
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(menu->quit, (sfIntRect){380, 411, 380,
            137});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(menu->quit, (sfIntRect){0, 411, 380,
            137});
    pressed = 0;
}

void check_mouse_on_menu(game_t *game, menu_screen_t *menu)
{
    sfVector2i pos = get_mouse(game);

    if (game->save == 0)
        sfSprite_setTextureRect(menu->resume, (sfIntRect){1140, 137, 380,
            137});
    else
        check_mouse_resume(game, menu, (sfVector2f){(float)pos.x,
            (float)pos.y}, sfSprite_getGlobalBounds(menu->resume));
    check_mouse_new_game(game, menu, (sfVector2f){(float)pos.x, (float)pos.y},
        sfSprite_getGlobalBounds(menu->new_game));
    check_mouse_settings(game, menu, (sfVector2f){(float)pos.x, (float)pos.y},
            sfSprite_getGlobalBounds(menu->settings));
    check_mouse_quit(game, menu, (sfVector2f){(float)pos.x, (float)pos.y},
        sfSprite_getGlobalBounds(menu->quit));
}
