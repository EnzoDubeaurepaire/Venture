/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** inti_stats.c
*/

#include "../../include/rpg.h"

static void init_res(player_stat_t *stats)
{
    stats->res = 0;
    stats->res_activated = 0;
    stats->res_sprite = sfSprite_create();
    sfSprite_setTexture(stats->res_sprite, stats->stat_button, true);
    sfSprite_setTextureRect(stats->res_sprite, (sfIntRect){0, 0, 240, 300});
    sfSprite_setPosition(stats->res_sprite, (sfVector2f){1050, 520});
    stats->res_hitbox = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(stats->res_hitbox, sfWhite);
    sfRectangleShape_setFillColor(stats->res_hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(stats->res_hitbox, 2);
    sfRectangleShape_setPosition(stats->res_hitbox, (sfVector2f){1078, 543});
    sfRectangleShape_setSize(stats->res_hitbox, (sfVector2f){178, 57});
}

static void init_hp(player_stat_t *stats)
{
    stats->hp = 50;
    stats->actual_hp = 50;
    stats->hp_activated = 0;
    stats->hp_sprite = sfSprite_create();
    sfSprite_setTexture(stats->hp_sprite, stats->stat_button, true);
    sfSprite_setTextureRect(stats->hp_sprite, (sfIntRect){0, 0, 240, 300});
    sfSprite_setPosition(stats->hp_sprite, (sfVector2f){610, 520});
    stats->hp_hitbox = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(stats->hp_hitbox, sfWhite);
    sfRectangleShape_setFillColor(stats->hp_hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(stats->hp_hitbox, 2);
    sfRectangleShape_setPosition(stats->hp_hitbox, (sfVector2f){638, 543});
    sfRectangleShape_setSize(stats->hp_hitbox, (sfVector2f){178, 57});
}

static void init_att(player_stat_t *stats)
{
    stats->att = 5;
    stats->att_activated = 0;
    stats->att_sprite = sfSprite_create();
    sfSprite_setTexture(stats->att_sprite, stats->stat_button, true);
    sfSprite_setTextureRect(stats->att_sprite, (sfIntRect){0, 0, 240, 300});
    sfSprite_setPosition(stats->att_sprite, (sfVector2f){250, 520});
    stats->att_hitbox = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(stats->att_hitbox, sfWhite);
    sfRectangleShape_setFillColor(stats->att_hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(stats->att_hitbox, 2);
    sfRectangleShape_setPosition(stats->att_hitbox, (sfVector2f){278, 543});
    sfRectangleShape_setSize(stats->att_hitbox, (sfVector2f){178, 57});
}

static void init_as(player_stat_t *stats)
{
    stats->as = 1;
    stats->as_activated = 0;
    stats->as_sprite = sfSprite_create();
    sfSprite_setTexture(stats->as_sprite, stats->stat_button, true);
    sfSprite_setTextureRect(stats->as_sprite, (sfIntRect){0, 0, 240, 300});
    sfSprite_setPosition(stats->as_sprite, (sfVector2f){1360, 520});
    stats->as_hitbox = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(stats->as_hitbox, sfWhite);
    sfRectangleShape_setFillColor(stats->as_hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(stats->as_hitbox, 2);
    sfRectangleShape_setPosition(stats->as_hitbox, (sfVector2f){1388, 543});
    sfRectangleShape_setSize(stats->as_hitbox, (sfVector2f){178, 57});
}

static void init_text(player_stat_t *stats)
{
    char level[5];
    char point[5];

    sprintf(level, "%d", stats->level);
    sprintf(point, "%d", stats->total_points);
    stats->font = sfFont_createFromFile("assets/fonts/commando.ttf");
    stats->level_text = sfText_create();
    sfText_setFont(stats->level_text, stats->font);
    sfText_setCharacterSize(stats->level_text, 70);
    sfText_setPosition(stats->level_text, (sfVector2f){358, 115});
    sfText_setString(stats->level_text, level);
    sfText_setFillColor(stats->level_text, sfWhite);
    stats->points_text = sfText_create();
    sfText_setFont(stats->points_text, stats->font);
    sfText_setFillColor(stats->points_text, sfWhite);
    sfText_setCharacterSize(stats->points_text, 70);
    sfText_setPosition(stats->points_text, (sfVector2f){1528, 115});
    sfText_setString(stats->points_text, point);
}

screen_t *init_stats(void)
{
    screen_t *screen = malloc(sizeof(screen_t));
    player_stat_t *stats = malloc(sizeof(player_stat_t));

    stats->stat_button = sfTexture_createFromFile("assets/stats_button.png",
        NULL);
    stats->level = 1;
    stats->needed_exp = 100;
    stats->total_points = 0;
    init_text(stats);
    init_as(stats);
    init_att(stats);
    init_hp(stats);
    init_res(stats);
    stats->skill_tree_back_t = sfTexture_createFromFile("assets/stats.png",
        0);
    stats->skill_tree_back = sfSprite_create();
    sfSprite_setPosition(stats->skill_tree_back, (sfVector2f){0, 0});
    sfSprite_setTexture(stats->skill_tree_back, stats->skill_tree_back_t, 1);
    screen->screen = stats;
    return screen;
}
