/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** map_enemies.c
*/

#include "../../include/rpg.h"

static bool check_reach(sfVector2f a, sfVector2f b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) < 300000;
}

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

static sfVector2f calculate_direction(
    sfVector2f enemy_pos, sfVector2f player_pos)
{
    sfVector2f direction = {
        player_pos.x - enemy_pos.x,
        player_pos.y - enemy_pos.y
    };
    float length = sqrt(
        direction.x * direction.x +
        direction.y * direction.y
    );

    direction.x /= length;
    direction.y /= length;
    return direction;
}

static void determine_movement(enemy_t *e, sfVector2f direction)
{
    if (direction.x > 0.5)
        e->move.x = 4;
    else if (direction.x < -0.5)
        e->move.x = -4;
    else
        e->move.x = 0;
    if (direction.y > 0.5)
        e->move.y = 4;
    else if (direction.y < -0.5)
        e->move.y = -4;
    else
        e->move.y = 0;
}

static void update_route(map_screen_t *map, enemy_t *e, int wait_p)
{
    sfVector2f enemy_pos = sfSprite_getPosition(e->e->sprite);
    sfVector2f player_pos = sfSprite_getPosition(map->player->sprite);

    e->direction_steps--;
    if (e->direction_steps > 0)
        return;
    e->direction_steps = rand() % 300 + 150;
    e->move.x = 0;
    e->move.y = 0;
    if (check_reach(player_pos, enemy_pos)) {
        sfVector2f direction = calculate_direction(enemy_pos, player_pos);
        determine_movement(e, direction);
        e->direction_steps = 50;
    } else {
        if (rand() % 100 < wait_p)
            return;
        while (!e->move.x && !e->move.y) {
            e->move.x = rand() % 3 - 1;
            e->move.y = rand() % 3 - 1;
        }
    }
}

//            if (check_collision(map, e->e, enemy_pos.x + 1, enemy_pos.y + 1)) {
//                e->move.x = enemy_pos.x + 1;
//                e->move.y = enemy_pos.y + 1;
//            } else if (check_collision(map, e->e, enemy_pos.x + 1, enemy_pos.y + 0)) {
//                e->move.x = enemy_pos.x + 1;
//                e->move.y = enemy_pos.y + 0;
//            } else if (check_collision(map, e->e, enemy_pos.x + 1, enemy_pos.y - 1)) {
//                e->move.x = enemy_pos.x + 1;
//                e->move.y = enemy_pos.y - 1;
//            } else if (check_collision(map, e->e, enemy_pos.x + 0, enemy_pos.y + 1)) {
//                e->move.x = enemy_pos.x + 0;
//                e->move.y = enemy_pos.y + 1;
//            } else if (check_collision(map, e->e, enemy_pos.x + 0, enemy_pos.y + 0)) {
//                e->move.x = enemy_pos.x + 0;
//                e->move.y = enemy_pos.y + 0;
//            } else if (check_collision(map, e->e, enemy_pos.x + 0, enemy_pos.y - 1)) {
//                e->move.x = enemy_pos.x + 0;
//                e->move.y = enemy_pos.y - 1;
//            } else if (check_collision(map, e->e, enemy_pos.x - 1, enemy_pos.y + 1)) {
//                e->move.x = enemy_pos.x - 1;
//                e->move.y = enemy_pos.y + 1;
//            } else if (check_collision(map, e->e, enemy_pos.x - 1, enemy_pos.y + 0)) {
//                e->move.x = enemy_pos.x - 1;
//                e->move.y = enemy_pos.y + 0;
//            } else if (check_collision(map, e->e, enemy_pos.x - 1, enemy_pos.y - 1)) {
//                e->move.x = enemy_pos.x - 1;
//                e->move.y = enemy_pos.y - 1;
//            }
//            update_route(map, e, 0);
void update_enemies_pos(map_screen_t *map)
{
    sfVector2f move;

    for (int i = 0; i < ENEMIES; i++) {
        enemy_t *e = map->enemies[i];
        move = e->move;
        update_route(map, e, LAZINESS);
        sfVector2f enemy_pos = sfSprite_getPosition(e->e->sprite);
        sfVector2f player_pos = sfSprite_getPosition(map->player->sprite);
        if (check_collision(map, e->e, move.x, move.y)) {
            printf("CACA\n");
            e->direction_steps = 0;
            return;
        }
        if (move.x && move.y) {
            move.x *= 1.0 / (float)(M_SQRT2);
            move.y *= 1.0 / (float)(M_SQRT2);
        }
        update_enemy_rect(e->e, &move);
        sfSprite_move(e->e->sprite, move);
        sfRectangleShape_move(e->e->hitbox, move);
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
