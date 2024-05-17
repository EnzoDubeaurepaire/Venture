/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** dialogue.h
*/

#ifndef DIALOGUE_H
    #define DIALOGUE_H
    #include "rpg.h"

/*
 * init_struct_dialogue.c
*/
screen_t *init_bubble(sfRenderWindow *window);

/*
 * event_dialogue
*/
void event_dialogue(game_t *game, bubble_t *bubble);

/*
 * dialogue.c
*/
void render_dialogue(game_t *game, screen_t *screen);

#endif
