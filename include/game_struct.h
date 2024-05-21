/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** game_struct.h
*/

#ifndef GAME_STRUCT_H
    #define GAME_STRUCT_H
    #include "rpg.h"

/*
 * init_game_struct.c
*/
game_t *init_game(void);

/*
 * free_game_struct.c
*/
void free_game(game_t *game);

/*
 * create_sprite.c
*/
sfSprite *create_sprite(sfTexture *texture,
    sfVector2f position, sfVector2f scale);

#endif
