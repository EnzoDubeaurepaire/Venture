/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** combat.c
*/

#include "../../include/rpg.h"

static void enemies_attack(game_t *game, map_screen_t *map)
{
    double time = (double) sfClock_getElapsedTime(game->clock).microseconds /
        1000000;
    static double last_hit = 0;
    sfFloatRect player = sfSprite_getGlobalBounds(map->player->sprite);
    sfFloatRect enemy;

    if (time - last_hit < 0.8)
        return;
    for (int i = 0; i < ENEMIES; i++) {
        if (map->enemies[i]->health <= 0)
            continue;
        enemy = sfSprite_getGlobalBounds(map->enemies[i]->e->sprite);
        if (sfFloatRect_intersects(&player, &enemy, NULL)) {
            set_hp(game, get_hp(game) - map->enemies[i]->strength +
                get_res(game));
            last_hit = time;
            return;
        }
    }
}

void combat_system(game_t *game, map_screen_t *map)
{
    double time = (double)sfClock_getElapsedTime(game->clock).microseconds;
    static double elapsed_time = 0;
    sfFloatRect player = sfCircleShape_getGlobalBounds(map->player_reach);
    sfFloatRect enemy;
    _Bool alive_before;

    enemies_attack(game, map);
    if (time / 1000000 - elapsed_time < get_as(game) ||
        !sfMouse_isButtonPressed(sfMouseLeft))
        return;
    elapsed_time = time / 1000000;
    for (int i = 0; i < ENEMIES; i++) {
        map->player->attack_state = 1;
        alive_before = map->enemies[i]->health > 0;
        enemy = sfRectangleShape_getGlobalBounds(map->enemies[i]->e->hitbox);
        if (sfFloatRect_intersects(&player, &enemy, NULL))
            map->enemies[i]->health -= get_att(game);
        if (alive_before && map->enemies[i]->health <= 0)
            give_xp(game, 50);
    }
}
