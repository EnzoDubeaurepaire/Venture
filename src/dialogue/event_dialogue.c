/*
** EPITECH PROJECT, 2023
** my_rgp
** File description:
** event_dialogue.c
*/

#include "../../include/rpg.h"

//when calling to display window :
//put bubble->compteur = 0;
//bubble->skip_animation = sfFalse;
void event_dialogue(game_t *game, bubble_t *bubble)
{
    if (game->key == sfKeyReturn) {
        if (bubble->skip_animation == sfTrue) {
            game->active_screen ^= DIALOGUE_SCREEN;
            bubble->skip_animation = sfFalse;
            game->key = -1;
        } else {
            bubble->skip_animation = sfTrue;
            game->key = -1;
        }
    }
}
