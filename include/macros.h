/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** macros.h
*/

#ifndef MACROS_H
    #define MACROS_H

    #define FPS 60
    #define SCREEN_NB 7
    #define LAUNCH_SCREEN 1
    #define MENU_SCREEN 2
    #define MAP_SCREEN 4
    #define DIALOGUE_SCREEN 8
    #define PAUSE_SCREEN 16
    #define STATS_SCREEN 32
    #define SETTINGS_SCREEN 64
    #define DELAY 0.05
    #define SAVED_ELEMENTS 12

enum saved_elements {
    MAP_X,
    MAP_Y,
    LEVEL,
    POINTS,
    ATT,
    ATT_ACTIV,
    AS,
    AS_ACTIV,
    HP,
    HP_ACTIV,
    RES,
    RES_ACTIV
};

#endif
