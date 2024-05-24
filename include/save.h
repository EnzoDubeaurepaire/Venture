/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** save.h
*/

#ifndef SAVE_H
    #define SAVE_H
    #include "rpg.h"

_Bool check_save(game_t *game);
void save(game_t *game);
_Bool is_save_ok(void);

_Bool check_stat_activ(const char *line, ssize_t size);
_Bool check_uint(const char *line, ssize_t size);
_Bool check_int(const char *line, ssize_t size);
_Bool check_inv_item(const char *line, ssize_t size);

static _Bool (*check_element[SAVED_ELEMENTS])(const char *line, ssize_t size)
    = {
    &check_int, &check_int, &check_uint, &check_uint, &check_uint,
    &check_stat_activ, &check_uint, &check_stat_activ, &check_uint,
    &check_stat_activ, &check_uint, &check_stat_activ, &check_inv_item,
    &check_inv_item, &check_inv_item, &check_inv_item, &check_inv_item,
    &check_inv_item, &check_inv_item, &check_inv_item};
#endif
