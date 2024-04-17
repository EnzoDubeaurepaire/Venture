/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** launch_screen.c
*/

#include "../../include/rpg.h"

static sfSprite *init_launch_screen_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    return sprite;
}

static sfText *init_launch_screen_text(sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setOrigin(text, (sfVector2f){29.f * 0.5f * 35.f - 50, 15});
    sfText_setCharacterSize(text, 35);
    sfText_setString(text, "Press Enter To Start The Game\0");
    sfText_setPosition(text, (sfVector2f){1100, 1000});
    sfText_setColor(text, sfWhite);
    sfText_setFillColor(text, sfWhite);
    sfText_setFont(text, font);
    return text;
}

static sfRectangleShape *init_launch_screen_fade(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(rect, sfBlack);
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    return rect;
}

launch_screen_t *init_launch_screen(void)
{
    launch_screen_t *launch_screen = malloc(sizeof(launch_screen_t));

    launch_screen->texture = sfTexture_createFromFile(
        "assets/background_title.png", NULL);
    launch_screen->sprite = init_launch_screen_sprite(launch_screen->texture);
    launch_screen->font = sfFont_createFromFile("assets/venite.ttf");
    launch_screen->text = init_launch_screen_text(launch_screen->font);
    launch_screen->fade = init_launch_screen_fade();
    launch_screen->fade_value = 0;
    return launch_screen;
}

void render_launch_screen(game_t *game, launch_screen_t *launch_screen)
{
    sfTime time = sfClock_getElapsedTime(game->clock);

    launch_screen->fade_value = (float)time.microseconds / 10000;
    if (launch_screen->fade_value > 255)
        launch_screen->fade_value = 255;
    sfRectangleShape_setFillColor(launch_screen->fade,
        (sfColor){0, 0, 0, (int)(255 - launch_screen->fade_value)});
    sfText_setScale(launch_screen->text, (sfVector2f){1 + 0.02f *
        (float)sin((double)time.microseconds / 500000), 1 + 0.02f *
        (float)sin((double)time.microseconds / 500000)});
    sfText_setColor(launch_screen->text, (sfColor){(int)(240 - 15 *
        sin((double)time.microseconds / 300000)), (int)(240 - 15 *
        sin((double)time.microseconds / 300000)), (int)(240 - 15 *
        sin((double)time.microseconds / 300000)), 255});
    sfRenderWindow_drawSprite(game->window, launch_screen->sprite, NULL);
    sfRenderWindow_drawText(game->window, launch_screen->text, NULL);
    sfRenderWindow_drawRectangleShape(game->window, launch_screen->fade,
        NULL);
}
