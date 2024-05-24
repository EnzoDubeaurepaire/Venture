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
        "Oh non encore quelque chose de brise !\n"
        "Bon je n'ai pas vraiment le choix si je veux continuer il va falloir "
        "reparer ce pont .\n"
        "Je peux peu etre trouve du bois ou quelque chose pour le reparer dans"
        " les debris du vaisseau\n"
        "Est ce que j'ai essaye le buisson ? (appuyez sur E)"
        "\n\n\nappuyez sur entree";
    }
}

static void wood_message(game_t *game, map_screen_t *map, int *show)
{
    if (*show == 1 && map->is_picked_up[6]) {
        game->active_screen |= DIALOGUE_SCREEN;
        ((bubble_t *) (game->screens[3]->screen))->compteur = 0;
        ((bubble_t *) (game->screens[3]->screen))->skip_animation = sfFalse;
        ((bubble_t *) (game->screens[3]->screen))->message =
        "Trop bien maintenant que j'ai le bois je vais pour reparer ce fichu "
        "pont."
        "(appuyez sur E)\n"
        "Je vas pouvoir aller sauve mon amie !\n"
        "\n\n\nappuyez sur entree";
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
        "Oh non encore quelque chose de brise !\n"
        "Bon je n'ai pas vraiment le choix si je veux continuer il va falloir "
        "reparer ce pont .\n"
        "Je peux peu etre trouve du bois ou quelque chose pour le reparer dans"
        " les debris du vaisseau\n\n\n\n"
        "appuyer sur entree";
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
    "appuyer sur entree";
    map->is_end = true;
}

void save_message(game_t *game, map_screen_t *map)
{
    if (get_all_object(map) == false) {
        game->active_screen |= DIALOGUE_SCREEN;
        ((bubble_t *) (game->screens[3]->screen))->compteur = 0;
        ((bubble_t *) (game->screens[3]->screen))->skip_animation = sfFalse;
        ((bubble_t *) (game->screens[3]->screen))->message =
        "WOw mon sauveur je ne pensez pas revoir une autre personne ici !\n"
        "quand est ce quon repart !?"
        "quoi ton vaisseau est aussi casser ?!\n"
        "il ne reste qu'une seul possibilite tu vas devoir retrouver les "
        "pieces \nde vaisseau qui ont ete perdue a travers la map\n"
        "Il y en a 6 ! fais attention cest une endroit dangereux, enfin tu as "
        "deja du le remarquer !\n"
        "appuyer sur entree";
    } else
        save_succeed(game, map);
}
