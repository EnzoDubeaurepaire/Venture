/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** stats_renderer.c
*/

#include "../../include/rpg.h"

void show_stats(game_t *game, player_stat_t *stats)
{
    sfRenderWindow_drawSprite(game->window, stats->skill_tree_back, NULL);
    sfRenderWindow_drawSprite(game->window, stats->as_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, stats->att_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, stats->hp_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, stats->res_sprite, NULL);
    sfRenderWindow_drawText(game->window, stats->level_text, NULL);
    sfRenderWindow_drawText(game->window, stats->points_text, NULL);
}

static void update_att(player_stat_t *stats, sfVector2i pos)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(stats->att_hitbox);
    char text[5];

    if (sfFloatRect_contains(&rect, (float)pos.x, (float)pos.y) &&
        stats->att_activated < 3 && stats->total_points >=
        stats->att_activated + 1) {
        stats->total_points -= stats->att_activated + 1;
        sprintf(text, "%d", stats->total_points);
        sfText_setString(stats->points_text, text);
        stats->att += 5;
        stats->att_activated += 1;
        sfSprite_setTextureRect(stats->att_sprite, (sfIntRect){240 *
            stats->att_activated, 0, 240, 300});
        sfRectangleShape_move(stats->att_hitbox, (sfVector2f){0, 97});
    }
}

static void update_as(player_stat_t *stats, sfVector2i pos)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(stats->as_hitbox);
    char text[5];

    if (sfFloatRect_contains(&rect, (float)pos.x, (float)pos.y) &&
        stats->as_activated < 3 && stats->total_points >=
        stats->as_activated + 1) {
        stats->total_points -= stats->as_activated + 1;
        sprintf(text, "%d", stats->total_points);
        sfText_setString(stats->points_text, text);
        stats->as += 0.5;
        stats->as_activated += 1;
        sfSprite_setTextureRect(stats->as_sprite, (sfIntRect){240 *
            stats->as_activated, 0, 240, 300});
        sfRectangleShape_move(stats->as_hitbox, (sfVector2f){0, 97});
    }
}

static void update_hp(player_stat_t *stats, sfVector2i pos)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(stats->hp_hitbox);
    char text[5];

    if (sfFloatRect_contains(&rect, (float)pos.x, (float)pos.y) &&
        stats->hp_activated < 3 && stats->total_points >=
        stats->as_activated + 1) {
        stats->total_points -= stats->hp_activated + 1;
        sprintf(text, "%d", stats->total_points);
        sfText_setString(stats->points_text, text);
        stats->hp += 15;
        stats->hp_activated += 1;
        sfSprite_setTextureRect(stats->hp_sprite, (sfIntRect){240 *
            stats->hp_activated, 0, 240, 300});
        sfRectangleShape_move(stats->hp_hitbox, (sfVector2f){0, 97});
    }
}

static void update_res(player_stat_t *stats, sfVector2i pos)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(stats->res_hitbox);
    char text[5];

    if (sfFloatRect_contains(&rect, (float)pos.x, (float)pos.y) &&
        stats->res_activated < 3 && stats->total_points >=
        stats->res_activated + 1) {
        stats->total_points -= stats->res_activated + 1;
        sprintf(text, "%d", stats->total_points);
        sfText_setString(stats->points_text, text);
        stats->res += 1;
        stats->res_activated += 1;
        sfSprite_setTextureRect(stats->res_sprite, (sfIntRect){240 *
            stats->res_activated, 0, 240, 300});
        sfRectangleShape_move(stats->res_hitbox, (sfVector2f){0, 97});
    }
}

static void update_stats(game_t *game, player_stat_t *stats)
{
    sfVector2i pos = get_mouse(game);

    if (!sfMouse_isButtonPressed(sfMouseLeft))
        return;
    update_att(stats, pos);
    update_res(stats, pos);
    update_hp(stats, pos);
    update_as(stats, pos);
}

void stats_renderer(game_t *game, screen_t *screen)
{
    update_stats(game, (player_stat_t *)screen->screen);
    show_stats(game, (player_stat_t *)screen->screen);
}
