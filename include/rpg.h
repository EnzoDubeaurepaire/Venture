/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_sokoban
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Network.h>
#include <SFML/Audio.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

#ifndef HUNTER_H
    #define HUNTER_H
    #include "math.h"
    #include "../linked_list/list.h"
    #include "macros.h"
    #include "struct.h"
    #include "launch_screen.h"
    #include "game_struct.h"
    #include "event.h"
    #include "menu.h"
    #include "settings_overlay.h"
    #include "map_screen.h"
    #include "dialogue.h"

static void (*renderers[SCREEN_NB + 1])(game_t *game, screen_t *screen) = {
    &render_launch_screen, &render_menu, &map_renderer,
    &render_dialogue, &render_settings ,NULL};

#endif
