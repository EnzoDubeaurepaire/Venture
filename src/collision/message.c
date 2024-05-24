/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** message.c
*/

#include "../../include/rpg.h"

static void no_wood_message(game_t *game, map_screen_t *map, int *show)
{
    if (*show == 1 && map->is_picked_up[6] == false) {
        game->active_screen |= DIALOGUE_SCREEN;
        ((bubble_t *) (game->screens[3]->screen))->compteur = 0;
        ((bubble_t *) (game->screens[3]->screen))->skip_animation = sfFalse;
        ((bubble_t *) (game->screens[3]->screen))->message =
            "Oh no another broken thing !\n"
            "I have no choice... If I want to carry on, "
            "i need to repair this bridge.\n"
            "Maybe I can find some wood towards the"
            "spaceship debris\n"
            "\n\n\nPress enter";
    }
}

static void wood_message(game_t *game, map_screen_t *map, int *show)
{
    if (*show == 1 && map->is_picked_up[6]) {
        game->active_screen |= DIALOGUE_SCREEN;
        ((bubble_t *) (game->screens[3]->screen))->compteur = 0;
        ((bubble_t *) (game->screens[3]->screen))->skip_animation = sfFalse;
        ((bubble_t *) (game->screens[3]->screen))->message =
            "Nice, now that I got the wood, I can repair this damn"
            "bridge."
            "(press E)\n"
            "I can finally go and save my friend !\n"
            "\n\n\nPress enter";
        *show = 2;
    }
    if (*show == 2 && sfKeyboard_isKeyPressed(sfKeyE)) {
        map->bridge_repared = true;
        switch_map(map);
        *show = 3;
    }
}

void bridge_message(game_t *game, map_screen_t *map)
{
    static int show = 0;

    if (show == 0) {
        game->active_screen |= DIALOGUE_SCREEN;
        ((bubble_t *) (game->screens[3]->screen))->compteur = 0;
        ((bubble_t *) (game->screens[3]->screen))->skip_animation = sfFalse;
        ((bubble_t *) (game->screens[3]->screen))->message =
            "Oh no another broken thing !\n"
            "I have no choice... If I want to carry on, "
            "i need to repair this bridge.\n"
            "Maybe I can find some wood towards the"
            "spaceship debris\n"
            "\n\n\nPress enter";
        show = 1;
    }
    no_wood_message(game, map, &show);
    wood_message(game, map, &show);
}

void save_succeed(game_t *game, map_screen_t *map)
{
    game->active_screen |= DIALOGUE_SCREEN;
    ((bubble_t *) (game->screens[3]->screen))->compteur = 0;
    ((bubble_t *) (game->screens[3]->screen))->skip_animation = sfFalse;
    ((bubble_t *) (game->screens[3]->screen))->message =
        "Here we go !\n\n\n\n"
        "\nPress enter";
    map->is_end = true;
}

void save_message(game_t *game, map_screen_t *map)
{
    if (get_all_object(map) == false) {
        game->active_screen |= DIALOGUE_SCREEN;
        ((bubble_t *) (game->screens[3]->screen))->compteur = 0;
        ((bubble_t *) (game->screens[3]->screen))->skip_animation = sfFalse;
        ((bubble_t *) (game->screens[3]->screen))->message =
            "WOW, my savior, I never thought I'd see anyone here again.\n"
            "WHEN DO WE LIVE !?!"
            "\nWHAT ? Your spaceship is also broken ?!"
            " there's only one possibility left you'll have to find the pieces"
            " \nof your spaceship through the planet\n"
            "There are 6 of them ! "
            "watch out this is a dangerous place, well you may "
            "have already noticed !\n"
            "\nPress enter";
    } else
        save_succeed(game, map);
}
