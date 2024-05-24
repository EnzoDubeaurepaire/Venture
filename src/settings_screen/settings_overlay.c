/*
** EPITECH PROJECT, 2023
** rr
** File description:
** rr
*/

#include "rpg.h"

static sfText *init_text(sfFont *font, char *str)
{
    sfText *text = sfText_create();

    sfText_setOrigin(text, (sfVector2f){29.f * 0.5f * 35.f - 20, 15});
    sfText_setCharacterSize(text, 35);
    sfText_setString(text, str);
    sfText_setPosition(text, (sfVector2f){2125, 290});
    sfText_setColor(text, sfWhite);
    sfText_setFillColor(text, sfWhite);
    sfText_setFont(text, font);
    return text;
}

static void init_textures(settings_screen_t *settings)
{
    settings->texture = sfTexture_createFromFile(
    "assets/settings/settings_overlay.png", NULL);
    settings->buttons_texture = sfTexture_createFromFile(
    "assets/settings/settings_buttons.png", NULL);
    settings->button_texture_screen = sfTexture_createFromFile(
    "assets/settings/buttons_screen.png", NULL);
}

static void init_sprites_buttons_settings(settings_screen_t *settings)
{
    settings->plus_button = create_sprite(settings->buttons_texture,
    (sfVector2f){1750, 280}, (sfVector2f){2.25, 2.25});
    settings->minus_button = create_sprite(settings->buttons_texture,
    (sfVector2f){1580, 280}, (sfVector2f){2.25, 2.25});
    settings->overlay = create_sprite(settings->texture,
    (sfVector2f){1450, 0}, (sfVector2f){0.95, 0.95});
    settings->cross = create_sprite(settings->buttons_texture,
    (sfVector2f){1815, 50}, (sfVector2f){2.25, 2.25});
    settings->fullscreen_button = create_sprite(
    settings->button_texture_screen,
    (sfVector2f){1580, 480}, (sfVector2f){0.5, 0.5});
    settings->window_button = create_sprite(
    settings->button_texture_screen,
    (sfVector2f){1580, 650}, (sfVector2f){0.5, 0.5});
    settings->resize_button = create_sprite(
    settings->button_texture_screen,
    (sfVector2f){1580, 750}, (sfVector2f){0.5, 0.5});
}

static void init_controls(settings_screen_t *settings)
{
    settings->controls_texture = sfTexture_createFromFile(
        "assets/settings/controls.png", NULL);
    settings->controls = sfSprite_create();
    sfSprite_setTexture(settings->controls, settings->controls_texture, 1);
    sfSprite_setPosition(settings->controls, (sfVector2f){0, 0});
}

screen_t *init_settings_screen(void)
{
    screen_t *screen = malloc(sizeof(screen_t));
    settings_screen_t *settings = malloc(sizeof(settings_screen_t));

    settings->main_volume = 50;
    init_textures(settings);
    settings->font = sfFont_createFromFile("assets/fonts/venite.ttf");
    settings->text_main_volume = init_text(settings->font, "50 %\0");
    settings->text_volume = init_text(settings->font, "Volume :\0");
    settings->window_mode = init_text(settings->font, "Window mode :\0");
    settings->window_size = init_text(settings->font, "Resolution :\0");
    sfText_setPosition(settings->text_volume, (sfVector2f){2075, 200});
    sfText_setPosition(settings->window_mode, (sfVector2f){2020, 400});
    sfText_setPosition(settings->window_size, (sfVector2f){2035, 600});
    init_sprites_buttons_settings(settings);
    init_controls(settings);
    screen->screen = settings;
    return screen;
}

void manage_settings_buttons(game_t *game, settings_screen_t *settings_screen)
{
    sfVector2i pos = get_mouse(game);

    check_plus_button(game, settings_screen,
    (sfVector2f){(float)pos.x, (float)pos.y});
    check_minus_button(game, settings_screen,
    (sfVector2f){(float)pos.x, (float)pos.y});
    check_cross_button(game, settings_screen,
    (sfVector2f){(float)pos.x, (float)pos.y});
    check_fullscreen_button(game, settings_screen,
    (sfVector2f){(float)pos.x, (float)pos.y});
    check_1280x720_button(game, settings_screen,
    (sfVector2f){(float)pos.x, (float)pos.y});
    check_1920x1080_button(game, settings_screen,
    (sfVector2f){(float)pos.x, (float)pos.y});
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
    sfRenderWindow_drawSprite(game->window,
    settings_screen->fullscreen_button, 0);
    sfRenderWindow_drawSprite(game->window, settings_screen->resize_button, 0);
    sfRenderWindow_drawSprite(game->window, settings_screen->window_button, 0);
    sfRenderWindow_drawText(game->window,
    settings_screen->text_main_volume, 0);
    sfRenderWindow_drawText(game->window, settings_screen->text_volume, 0);
    sfRenderWindow_drawText(game->window, settings_screen->window_mode, 0);
    sfRenderWindow_drawText(game->window, settings_screen->window_size, 0);
    sfRenderWindow_drawSprite(game->window, settings_screen->controls, 0);
}
