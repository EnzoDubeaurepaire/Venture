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
    sfSprite_setPosition(sprite_col, (sfVector2f){-24, -24});
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

static sfRectangleShape *init_hitobx(entity_t *player)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfFloatRect rect = sfSprite_getGlobalBounds(player->sprite);

    sfRectangleShape_setPosition(hitbox,
        (sfVector2f){rect.left + 15, rect.top + rect.height * (3.f/4) - 10});
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
    player->hitbox = init_hitobx(player);
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
    map->map_sprite = init_map_sprite(map->map_texture);
    map->collision_sprite = init_collision_sprite(map->collision_texture);
    map->player = malloc(sizeof(entity_t));
    map->player = init_player();
    map->sprint = init_sprint();

    sfImage* image = sfTexture_copyToImage(map->map_texture);
    sfVector2u size = sfImage_getSize(image);
    for (unsigned int x = 0; x < size.x; x++)
    {
        for (unsigned int y = 0; y < size.y; y++)
        {
            sfColor color = sfImage_getPixel(image, x, y);
            color.a = 128; // 128 pour 50% de transparence
            sfImage_setPixel(image, x, y, color);
        }
    }
    sfTexture_updateFromImage(map->map_texture, image, 0, 0);
    sfImage_destroy(image);
    screen->screen = map;
    return screen;
}
