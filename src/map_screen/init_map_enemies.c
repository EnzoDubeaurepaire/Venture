/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** init_map_screen.c
*/

#include "../../include/rpg.h"

static void init_enemy_entity(enemy_t *enemy, char *asset_path)
{
    enemy->e = malloc(sizeof(entity_t));
    enemy->e->rect = (sfIntRect){0, 0, 32, 32};
    enemy->e->position = (sfVector2f) {rand() % 3000 + 50, rand() % 3000 + 50};
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

static enemy_t *init_enemy(int enemy_nbr)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    char asset_path[27] = "assets/enemies/enemy_x.png";

    enemy->move.x = 0;
    enemy->move.y = 0;
    enemy->type = (rand() % 4) + 1;
    enemy->direction_steps = 0;
    enemy->anim_steps = 15;
    asset_path[21] = enemy->type + '0';
    init_enemy_entity(enemy, asset_path);
    return enemy;
}

enemy_t **init_enemies(void)
{
    enemy_t **enemies = malloc(sizeof(enemy_t *) * ENEMIES);

    srand(time(NULL));
    for (int i = 0; i < ENEMIES; i++)
        enemies[i] = init_enemy(i);
    return enemies;
}
