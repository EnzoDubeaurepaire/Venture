/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** utils.h
*/

#ifndef UTILS_H
    #define UTILS_H
    #include "rpg.h"

sfVector2i get_mouse(game_t *game);

/*
 * exit_game.c
*/
void exit_game(game_t *game);

/*
 * event.c
*/
void update_resolution(game_t *game);
void update_window(game_t *game);

/*
 * check_env.c
*/
void check_env(char **env);

/*
 * check_assets.c
*/
void check_assets(void);

#endif
