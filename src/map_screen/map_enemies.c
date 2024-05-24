/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** map_enemies.c
*/

#include "../../include/rpg.h"

static void update_enemy_rect(entity_t *e, sfVector2f *move)
{
    if (move->y < 0)
        e->rect.left = 32;
    if (move->y > 0)
        e->rect.left = 0;
    if (move->x < 0)
        e->rect.left = 96;
    if (move->x > 0)
        e->rect.left = 64;
    sfSprite_setTextureRect(e->sprite, e->rect);
}

static void update_route(map_screen_t *map, enemy_t *e, int wait_p)
{
    e->direction_steps--;
    if (e->direction_steps > 0)
        return;
    e->direction_steps = rand() % 300 + 150;
    e->move.x = 0;
    e->move.y = 0;
    if (rand() % 100 < wait_p)
        return;
    while (!e->move.x && !e->move.y) {
        e->move.x = rand() % 3 - 1;
        e->move.y = rand() % 3 - 1;
    }
}

void update_enemies_pos(map_screen_t *map)
{
    sfVector2f move;

    for (int i = 0; i < ENEMIES; i++) {
        move = map->enemies[i]->move;
        update_route(map, map->enemies[i], LAZINESS);
        if (check_collision(map, map->enemies[i]->e, move.x, move.y)) {
            map->enemies[i]->direction_steps = 0;
            update_route(map, map->enemies[i], 0);
            return;
        }
        if (move.x && move.y) {
            move.x *= 1.0 / (float)(M_SQRT2);
            move.y *= 1.0 / (float)(M_SQRT2);
        }
        update_enemy_rect(map->enemies[i]->e, &move);
        sfSprite_move(map->enemies[i]->e->sprite, move);
        sfRectangleShape_move(map->enemies[i]->e->hitbox, move);
    }
}

static void update_animation(enemy_t *enemy)
{
    if ((enemy->move.x || enemy->move.y) && enemy->anim_steps == 15) {
        enemy->e->rect.top += 32;
        enemy->e->rect.top = enemy->e->rect.top % 96;
    } else if (!enemy->move.x && !enemy->move.y && enemy->anim_steps == 15)
        enemy->e->rect.top = 0;
}

void animate_enemies(game_t *game, map_screen_t *map_screen)
{
    for (int i = 0; i < ENEMIES; i++) {
        if (map_screen->enemies[i]->anim_steps == 0)
            map_screen->enemies[i]->anim_steps = 15;
        update_animation(map_screen->enemies[i]);
        map_screen->enemies[i]->anim_steps--;
    }
}
