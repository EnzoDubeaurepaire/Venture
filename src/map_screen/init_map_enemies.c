/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** init_map_screen.c
*/

#include "../../include/rpg.h"
#include "../../include/enemies_positions.h"

static void init_enemy_entity(enemy_t *enemy, char *asset_path, sfVector2f pos)
{
    enemy->e = malloc(sizeof(entity_t));
    enemy->e->rect = (sfIntRect){0, 0, 32, 32};
    enemy->e->position = pos;
    enemy->e->texture = sfTexture_createFromFile(asset_path, NULL);
    enemy->e->sprite = sfSprite_create();
    enemy->e->is_hitbox = sfFalse;
    sfSprite_setTexture(enemy->e->sprite, enemy->e->texture, 0);
    sfSprite_setTextureRect(enemy->e->sprite, enemy->e->rect);
    sfSprite_setOrigin(enemy->e->sprite, (sfVector2f){16, 16});
    sfSprite_setPosition(enemy->e->sprite, enemy->e->position);
    sfSprite_setScale(enemy->e->sprite, (sfVector2f){3, 3});
    enemy->e->hitbox = init_hitbox(enemy->e);
}

static enemy_t *init_enemy(map_screen_t *map, int i)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    char asset_path[27] = "assets/enemies/enemy_x.png";
    sfVector2f pos = (sfVector2f){
        enemies_positions[i % 20].x + sfSprite_getPosition(map->map_sprite).x,
        enemies_positions[i % 20].y + sfSprite_getPosition(map->map_sprite).y
    };

    enemy->move.x = 0;
    enemy->move.y = 0;
    enemy->type = (rand() % 4) + 1;
    enemy->direction_steps = 0;
    enemy->anim_steps = 15;
    enemy->health = 50;
    enemy->strength = 5;
    asset_path[21] = enemy->type + '0';
    init_enemy_entity(enemy, asset_path, pos);
    return enemy;
}

enemy_t **init_enemies(map_screen_t *map)
{
    enemy_t **enemies = malloc(sizeof(enemy_t *) * ENEMIES);

    srand(time(NULL));
    for (int i = 0; i < ENEMIES; i++)
        enemies[i] = init_enemy(map, i);
    return enemies;
}
