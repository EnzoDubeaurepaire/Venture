/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include "rpg.h"

typedef struct bubble_s {
    sfClock *clock;
    sfRectangleShape *rect;
    int compteur;
    sfFont *font;
    sfText *text;
    sfBool is_display;
    sfBool skip_animation;
    char *message;
}bubble_t;

typedef struct launch_screen {
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *text;
    sfRectangleShape *fade;
    float fade_value;
    sfTime text_vanish;
    sfClock *vanish_clock;
} launch_screen_t;

typedef struct menu_screen {
    sfTexture *texture;
    sfClock *clock;
    sfSprite *new_game;
    sfSprite *resume;
    sfSprite *settings;
    sfSprite *quit;
    _Bool resume_is_usable;
} menu_screen_t;

typedef struct screen {
    void *screen;
} screen_t;

typedef struct game {
    sfRenderWindow *window;
    sfClock *clock;
    _Bool mouse_hold;
    sfKeyCode key;
    size_t active_screen;
    screen_t *screens[SCREEN_NB + 1];
    void (*screen_renderer[SCREEN_NB + 1])(struct game *game, screen_t
        *screen);
} game_t;

#endif
