/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** pause.c
*/

#include "../../include/rpg.h"

static sfSprite *init_save_button(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setTextureRect(sprite, (sfIntRect){0, 0, 380, 137});
    sfSprite_setOrigin(sprite, (sfVector2f){190, 68.5f});
    sfSprite_setPosition(sprite, (sfVector2f){960 - 230, 500});
    return sprite;
}

static sfSprite *init_chara_button(sfTexture *texture)
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

screen_t *init_pause(void)
{
    pause_screen_t *pause = malloc(sizeof(pause_screen_t));
    screen_t *screen = malloc(sizeof(screen_t));

    pause->texture = sfTexture_createFromFile("assets/pause_buttons.png",
        NULL);
    pause->save = init_save_button(pause->texture);
    pause->chara = init_chara_button(pause->texture);
    pause->sett = init_settings_button(pause->texture);
    pause->quit = init_quit_button(pause->texture);
    screen->screen = pause;
    return screen;
}

void render_pause(game_t *game, screen_t *screen)
{
    pause_screen_t *pause = screen->screen;

    check_mouse_on_pause(game, pause);
    sfRenderWindow_drawSprite(game->window, pause->quit, 0);
    sfRenderWindow_drawSprite(game->window, pause->sett, 0);
    sfRenderWindow_drawSprite(game->window, pause->chara, 0);
    sfRenderWindow_drawSprite(game->window, pause->save, 0);
}
