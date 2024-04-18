/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** menu.c
*/

#include "../../include/rpg.h"

void render_menu(game_t *game, screen_t *screen)
{
    menu_screen_t *menu = screen->screen;

    check_mouse_on_menu(game, menu);
    sfRenderWindow_drawSprite(game->window, menu->new_game, 0);
    sfRenderWindow_drawSprite(game->window, menu->resume, 0);
    sfRenderWindow_drawSprite(game->window, menu->settings, 0);
    sfRenderWindow_drawSprite(game->window, menu->quit, 0);
}

static sfSprite *init_new_game_button(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setTextureRect(sprite, (sfIntRect){0, 0, 380, 137});
    sfSprite_setOrigin(sprite, (sfVector2f){190, 68.5f});
    sfSprite_setPosition(sprite, (sfVector2f){960 - 230, 500});
    return sprite;
}

static sfSprite *init_resume_button(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setTextureRect(sprite, (sfIntRect){1140, 137, 380, 137});
    sfSprite_setOrigin(sprite, (sfVector2f){190, 68.5f});
    sfSprite_setPosition(sprite, (sfVector2f){960 + 230, 500});
    return sprite;
}

static sfSprite *init_settings_button(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setTextureRect(sprite, (sfIntRect){0, 274, 380, 137});
    sfSprite_setOrigin(sprite, (sfVector2f){190, 68.5f});
    sfSprite_setPosition(sprite, (sfVector2f){960 - 230, 740});
    return sprite;
}

static sfSprite *init_quit_button(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setTextureRect(sprite, (sfIntRect){0, 411, 380, 137});
    sfSprite_setOrigin(sprite, (sfVector2f){190, 68.5f});
    sfSprite_setPosition(sprite, (sfVector2f){960 + 230, 740});
    return sprite;
}

screen_t *init_menu(void)
{
    screen_t *screen = malloc(sizeof(screen_t));
    menu_screen_t *menu = malloc(sizeof(menu_screen_t));

    menu->clock = sfClock_create();
    menu->texture = sfTexture_createFromFile("assets/menu/buttons.png", NULL);
    menu->new_game = init_new_game_button(menu->texture);
    menu->resume = init_resume_button(menu->texture);
    menu->settings = init_settings_button(menu->texture);
    menu->quit = init_quit_button(menu->texture);
    menu->resume_is_usable = 0;
    screen->screen = menu;
    return screen;
}
