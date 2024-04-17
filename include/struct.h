/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include "rpg.h"

typedef struct launch_screen {
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *text;
    sfRectangleShape *fade;
    float fade_value;
} launch_screen_t;
typedef struct game {
    sfRenderWindow *window;
    sfClock *clock;
    launch_screen_t *launch_screen;
} game_t;

#endif
