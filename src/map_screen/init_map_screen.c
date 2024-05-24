/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** init_map_screen.c
*/

#include "../../include/rpg.h"

static sfSprite *init_collision_sprite(sfTexture *texture_col)
{
    sfSprite *sprite_col = sfSprite_create();

    sfSprite_setTexture(sprite_col, texture_col, 0);
    sfSprite_setPosition(sprite_col, (sfVector2f){0, 0});
    sfSprite_setScale(sprite_col, (sfVector2f){3, 3});
    return sprite_col;
}

static sfSprite *init_map_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    sfSprite_setScale(sprite, (sfVector2f){3, 3});
    return sprite;
}

sfRectangleShape *init_hitbox(entity_t *player)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfFloatRect rect = sfSprite_getGlobalBounds(player->sprite);

    sfRectangleShape_setPosition(hitbox,
        (sfVector2f){rect.left + 15, rect.top + rect.height * (3.f / 4) - 10});
    sfRectangleShape_setSize(hitbox, (sfVector2f){rect.width - 30, rect
    .height / 4});
    sfRectangleShape_setOutlineColor(hitbox, sfBlue);
    sfRectangleShape_setOutlineThickness(hitbox, 2);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    return hitbox;
}

static entity_t *init_player(void)
{
    entity_t *player = malloc(sizeof(entity_t));

    player->rect = (sfIntRect){0, 0, 32, 32};
    player->position = (sfVector2f){1920.f / 2, 1080.f / 2};
    player->texture = sfTexture_createFromFile("assets/player_sprite.png",
        NULL);
    player->sprite = sfSprite_create();
    player->is_hitbox = sfFalse;
    sfSprite_setTexture(player->sprite, player->texture, 0);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setOrigin(player->sprite, (sfVector2f){16, 16});
    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setScale(player->sprite, (sfVector2f){3, 3});
    player->hitbox = init_hitbox(player);
    return player;
}

static sprint_t *init_sprint(void)
{
    sprint_t *sprint = malloc(sizeof(sprint_t));

    sprint->texture = sfTexture_createFromFile("assets/sprint_bar.png", NULL);
    sprint->rect = (sfIntRect){0, 40, 64, 8};
    sprint->stamina = 1;
    sprint->sprite = sfSprite_create();
    sfSprite_setTexture(sprint->sprite, sprint->texture, 0);
    sfSprite_setTextureRect(sprint->sprite, sprint->rect);
    sfSprite_setPosition(sprint->sprite, (sfVector2f){50, 50});
    sfSprite_setScale(sprint->sprite, (sfVector2f){3, 3});
    return sprint;
}

static void init_mini_map(map_screen_t *map)
{
    map->mini_map = sfRectangleShape_create();
    sfRectangleShape_setTexture(map->mini_map, map->map_texture, true);
    sfRectangleShape_setSize(map->mini_map, (sfVector2f){250, 250});
    sfRectangleShape_setPosition(map->mini_map, (sfVector2f){1620, 50});
    sfRectangleShape_setOutlineThickness(map->mini_map, 3);
    sfRectangleShape_setOutlineColor(map->mini_map, sfBlack);
    map->mini_map_player = sfSprite_create();
    sfSprite_setTexture(map->mini_map_player, map->player->texture, true);
    sfSprite_setTextureRect(map->mini_map_player, (sfIntRect){0, 0, 32, 32});
    sfSprite_setScale(map->mini_map_player, (sfVector2f){0.5f, 0.5f});
    sfSprite_setOrigin(map->mini_map_player, (sfVector2f){8, 8});
}

static void init_value_map(map_screen_t *map)
{
    map->map_sprite = init_map_sprite(map->map_texture);
    map->collision_sprite = init_collision_sprite(map->collision_texture);
    map->player = init_player();
    map->enemies = init_enemies(map);
    map->sprint = init_sprint();
    map->image_collision = sfTexture_copyToImage(map->collision_texture);
    map->player->pos_rel_to_map = get_pos_rel_to_map(map->player->position,
        map->map_position);
}

static void init_bush(map_screen_t *map)
{
    map->bush_texture = sfTexture_createFromFile("assets/bush.png", NULL);
    map->bush_sprite = sfSprite_create();
    sfSprite_setTexture(map->bush_sprite, map->bush_texture, 1);
    sfSprite_setOrigin(map->bush_sprite, (sfVector2f){
        (float)sfTexture_getSize(map->bush_texture).x / 2,
        (float)sfTexture_getSize(map->bush_texture).y / 2});
    sfSprite_setPosition(map->bush_sprite, (sfVector2f){500, 500});
}

static void init_health_bar(map_screen_t *map)
{
    map->health_bar_t = sfTexture_createFromFile("assets/health_bar.png",
        NULL);
    map->health_bar = sfSprite_create();
    map->health_rect = (sfIntRect){0, 40, 64, 8};
    sfSprite_setTexture(map->health_bar, map->health_bar_t, 0);
    sfSprite_setTextureRect(map->health_bar, map->health_rect);
    sfSprite_setPosition(map->health_bar, (sfVector2f){ 50, 100});
    sfSprite_setScale(map->health_bar, (sfVector2f){3, 3});
}

screen_t *init_map(void)
{
    screen_t *screen = malloc(sizeof(screen_t));
    map_screen_t *map = malloc(sizeof(map_screen_t));

    map->player_direction = (sfVector2f){0, 0};
    map->speed = 200;
    map->sprint_speed = 400;
    map->map_position = (sfVector2f){0, 0};
    map->map_texture = sfTexture_createFromFile("assets/map.png", NULL);
    map->collision_texture = sfTexture_createFromFile("assets/collision.png",
        NULL);
    init_health_bar(map);
    init_bush(map);
    init_value_map(map);
    init_mini_map(map);
    init_inventory(map);
    init_npc(map);
    screen->screen = map;
    return screen;
}
