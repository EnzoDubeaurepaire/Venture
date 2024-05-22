/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** destroyer.c
*/

#include "../../include/rpg.h"

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
    free(settings);
    free(screen);
}
