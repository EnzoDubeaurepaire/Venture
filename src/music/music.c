/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** music.c
*/

#include "../../include/rpg.h"

static void music_manager_dialogue(game_t *game)
{
    if (game->active_screen & DIALOGUE_SCREEN) {
        if (((bubble_t *)(game->screens[3]->screen))->compteur == 0) {
            sfMusic_setLoop(game->music->typing_music, true);
            sfMusic_play(game->music->typing_music);
        }
        if (((bubble_t *)(game->screens[3]->screen))->skip_animation ==
            sfTrue &&
            sfMusic_getStatus(game->music->typing_music) == sfPlaying)
            sfMusic_stop(game->music->typing_music);
    } else if (sfMusic_getStatus(game->music->typing_music) == sfPlaying)
        sfMusic_stop(game->music->typing_music);
}

static void music_manager_menu(game_t *game)
{
    if (game->active_screen & LAUNCH_SCREEN ||
        game->active_screen & MENU_SCREEN) {
        if (sfMusic_getStatus(game->music->menu_music) != sfPlaying) {
            sfMusic_setLoop(game->music->menu_music, true);
            sfMusic_play(game->music->menu_music);
        }
    } else if (sfMusic_getStatus(game->music->menu_music) == sfPlaying) {
            sfMusic_stop(game->music->menu_music);
    }
}

static void music_manager_gameplay(game_t *game)
{
    if (game->active_screen & MAP_SCREEN) {
        if (sfMusic_getStatus(game->music->walking) != sfPlaying) {
            sfMusic_setLoop(game->music->walking, true);
            sfMusic_play(game->music->walking);
        }
    } else if (sfMusic_getStatus(game->music->walking) == sfPlaying) {
        sfMusic_stop(game->music->walking);
    }
}

void music_manager(game_t *game)
{
    music_manager_menu(game);
    music_manager_dialogue(game);
    music_manager_gameplay(game);
}

void click_sound(game_t *game)
{
    sfMusic_stop(game->music->button_click);
    sfMusic_play(game->music->button_click);
}
