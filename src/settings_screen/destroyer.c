/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** destroyer.c
*/

#include "../../include/rpg.h"

static void destroy_controls(settings_screen_t *settings)
{
    sfSprite_destroy(settings->controls);
    sfTexture_destroy(settings->controls_texture);
}

void settings_screen_destroyer(screen_t *screen)
{
    settings_screen_t *settings = screen->screen;

    sfTexture_destroy(settings->texture);
    sfFont_destroy(settings->font);
    sfTexture_destroy(settings->buttons_texture);
    sfSprite_destroy(settings->cross);
    sfSprite_destroy(settings->overlay);
    sfSprite_destroy(settings->plus_button);
    sfSprite_destroy(settings->minus_button);
    sfText_destroy(settings->text_main_volume);
    sfText_destroy(settings->text_volume);
    sfText_destroy(settings->window_mode);
    sfText_destroy(settings->window_size);
    sfTexture_destroy(settings->button_texture_screen);
    sfSprite_destroy(settings->fullscreen_button);
    sfSprite_destroy(settings->window_button);
    sfSprite_destroy(settings->resize_button);
    destroy_controls(settings);
    free(settings);
    free(screen);
}
