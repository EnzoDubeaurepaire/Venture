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

#ifndef HUNTER_H
    #define HUNTER_H
    #include "macros.h"
    #include "struct.h"
    #include "launch_screen.h"
    #include "game_struct.h"
    #include "event.h"
    #include "menu.h"
    #include "settings_overlay.h"

static void (*renderers[SCREEN_NB + 1])(game_t *game, screen_t *screen) = {
    &render_launch_screen, &render_menu, &render_settings, NULL};

#endif
