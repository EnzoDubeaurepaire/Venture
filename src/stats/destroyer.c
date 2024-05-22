/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** destroyer.c
*/

#include "../../include/rpg.h"

void stats_destroyer(screen_t *screen)
{
    player_stat_t *stat = screen->screen;

    sfFont_destroy(stat->font);
    sfText_destroy(stat->points_text);
    sfRectangleShape_destroy(stat->att_hitbox);
    sfSprite_destroy(stat->att_sprite);
    sfRectangleShape_destroy(stat->as_hitbox);
    sfText_destroy(stat->level_text);
    sfSprite_destroy(stat->hp_sprite);
    sfSprite_destroy(stat->as_sprite);
    sfSprite_destroy(stat->skill_tree_back);
    sfTexture_destroy(stat->skill_tree_back_t);
    sfTexture_destroy(stat->stat_button);
    sfRectangleShape_destroy(stat->hp_hitbox);
    sfRectangleShape_destroy(stat->res_hitbox);
    sfSprite_destroy(stat->res_sprite);
    free(stat);
    free(screen);
}
