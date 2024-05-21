/*
** EPITECH PROJECT, 2023
** rr
** File description:
** rr
*/

#include "rpg.h"

static sfText *init_main_volume_text(sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setOrigin(text, (sfVector2f){29.f * 0.5f * 35.f - 20, 15});
    sfText_setCharacterSize(text, 35);
    sfText_setString(text, "50 %\0");
    sfText_setPosition(text, (sfVector2f){2125, 300});
    sfText_setColor(text, sfWhite);
    sfText_setFillColor(text, sfWhite);
    sfText_setFont(text, font);
    return text;
}

static sfText *init_volume_text(sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setOrigin(text, (sfVector2f){29.f * 0.5f * 35.f - 20, 15});
    sfText_setCharacterSize(text, 35);
    sfText_setString(text, "Volume :\0");
    sfText_setPosition(text, (sfVector2f){2075, 240});
    sfText_setColor(text, sfWhite);
    sfText_setFillColor(text, sfWhite);
    sfText_setFont(text, font);
    return text;
}

static void init_sprites_buttons_settings(settings_screen_t *settings)
{
    settings->plus_button = create_sprite(settings->buttons_texture,
    (sfVector2f){1750,290}, (sfVector2f){2.25, 2.25});
    settings->minus_button = create_sprite(settings->buttons_texture,
    (sfVector2f){1580,290}, (sfVector2f){2.25, 2.25});
    settings->overlay = create_sprite(settings->texture, (sfVector2f){1450,0},
    (sfVector2f){0.95,0.95});
    settings->cross = create_sprite(settings->buttons_texture, (sfVector2f){1815,50},
    (sfVector2f){2.25,2.25});
}

screen_t *init_settings_screen(void)
{
    screen_t *screen = malloc(sizeof(screen_t));
    settings_screen_t *settings = malloc(sizeof(settings_screen_t));

    settings->main_volume = 50;
    settings->font = sfFont_createFromFile("assets/fonts/venite.ttf");
    settings->texture = sfTexture_createFromFile("assets/settings/settings_overlay.png", NULL);
    settings->buttons_texture = sfTexture_createFromFile("assets/settings/settings_buttons.png", NULL);
    settings->text_main_volume = init_main_volume_text(settings->font);
    settings->text_volume = init_volume_text(settings->font);
    screen->screen = settings;
    return screen;
}

void manage_settings_buttons(game_t *game, settings_screen_t *settings_screen)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    check_plus_button(game, settings_screen, (sfVector2f){(float)pos.x, (float)pos.y});
    check_minus_button(game, settings_screen, (sfVector2f){(float)pos.x, (float)pos.y});
    check_cross_button(game, settings_screen, (sfVector2f){(float)pos.x, (float)pos.y});
}

void render_settings(game_t *game, screen_t *screen)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    settings_screen_t *settings_screen = screen->screen;

    manage_settings_buttons(game, settings_screen);
    sfRenderWindow_drawSprite(game->window, settings_screen->overlay, 0);
    sfRenderWindow_drawSprite(game->window, settings_screen->cross, 0);
    sfRenderWindow_drawSprite(game->window, settings_screen->plus_button, 0);
    sfRenderWindow_drawSprite(game->window, settings_screen->minus_button, 0);
    sfRenderWindow_drawText(game->window, settings_screen->text_main_volume, 0);
    sfRenderWindow_drawText(game->window, settings_screen->text_volume, 0);
}
