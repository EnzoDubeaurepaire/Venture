/*
** EPITECH PROJECT, 2023
** rr
** File description:
** rr
*/

#include "rpg.h"

screen_t *init_settings_screen(void)
{
    screen_t *screen = malloc(sizeof(screen_t));
    settings_screen_t *settings = malloc(sizeof(menu_screen_t));

    settings->texture = sfTexture_createFromFile("assets/settings/settings_overlay.png", NULL);
//    settings->buttons_texture = sfTexture_createFromFile("assets/menu/settings_buttons.png", NULL);
    settings->overlay = create_sprite(settings->texture, (sfVector2f){0,0}, (sfVector2f){0,0});
    screen->screen = settings;
    return screen;
}

void render_settings(game_t *game, screen_t *screen)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    settings_screen_t *settings_screen = screen->screen;

    sfRenderWindow_drawSprite(game->window, settings_screen->overlay, 0);
    printf("rendering\n");
}