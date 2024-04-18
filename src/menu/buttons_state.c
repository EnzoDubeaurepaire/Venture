/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** buttons_state.c
*/

#include "../../include/rpg.h"

static void check_mouse_new_game(game_t *game, menu_screen_t *menu, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(menu->new_game);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(menu->new_game, (sfIntRect){380, 0, 380,
            137});
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold)
        sfSprite_setTextureRect(menu->new_game, (sfIntRect){760, 0, 380,
            137});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(menu->new_game, (sfIntRect){0, 0, 380,
            137});
}

static void check_mouse_resume(game_t *game, menu_screen_t *menu, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(menu->resume);

    if (menu->resume_is_usable == 0) {
        sfSprite_setTextureRect(menu->resume, (sfIntRect){1140, 137, 380,
            137});
        return;
    }
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(menu->resume, (sfIntRect){380, 137, 380,
            137});
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold)
        sfSprite_setTextureRect(menu->resume, (sfIntRect){760, 137, 380,
            137});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(menu->resume, (sfIntRect){0, 137, 380,
            137});
}

static void check_mouse_settings(game_t *game, menu_screen_t *menu, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(menu->settings);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(menu->settings, (sfIntRect){380, 274, 380,
            137});
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold)
        sfSprite_setTextureRect(menu->settings, (sfIntRect){760, 274, 380,
            137});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(menu->settings, (sfIntRect){0, 274, 380,
            137});
}

static void check_mouse_quit(game_t *game, menu_screen_t *menu, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(menu->quit);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) && !game->mouse_hold)
        sfSprite_setTextureRect(menu->quit, (sfIntRect){380, 411, 380,
            137});
    if (sfFloatRect_contains(&rect, pos.x, pos.y) && game->mouse_hold)
        sfSprite_setTextureRect(menu->quit, (sfIntRect){760, 411, 380,
            137});
    if (!sfFloatRect_contains(&rect, pos.x, pos.y))
        sfSprite_setTextureRect(menu->quit, (sfIntRect){0, 411, 380,
            137});
}

void check_mouse_on_menu(game_t *game, menu_screen_t *menu)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    check_mouse_new_game(game, menu, (sfVector2f){(float)pos.x,(float)pos.y});
    check_mouse_resume(game, menu, (sfVector2f){(float)pos.x,(float)pos.y});
    check_mouse_settings(game, menu, (sfVector2f){(float)pos.x,(float)pos.y});
    check_mouse_quit(game, menu, (sfVector2f){(float)pos.x,(float)pos.y});
}