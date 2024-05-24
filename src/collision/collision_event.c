/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** collision_event.c
*/

#include "../../include/rpg.h"

static sfColor collision_y(sfFloatRect rect_bounds, int y, map_screen_t *map,
    sfVector2u image_size)
{
    sfColor col = sfWhite;

    if (y == 1) {
        if (rect_bounds.top + rect_bounds.height >= image_size.y)
            return sfRed;
        for (float x = rect_bounds.left; x <= rect_bounds.left + rect_bounds
            .width && col.g == 255 && col.b == 255 && col.r == 255; x++)
            col = sfImage_getPixel
            (map->image_collision, x, rect_bounds.top + rect_bounds.height);
    }
    if (y == -1) {
        if (rect_bounds.top < 0)
            return sfRed;
        for (float x = rect_bounds.left; x <= rect_bounds.left + rect_bounds
            .width && col.g == 255 && col.b == 255 && col.r == 255; x++)
            col = sfImage_getPixel(map->image_collision, x, rect_bounds.top);
    }
    return col;
}

static sfColor collision_x(sfFloatRect rect_bounds, int x, map_screen_t *map,
    sfVector2u image_size)
{
    sfColor col = sfWhite;

    if (x == 1) {
        if (rect_bounds.left + rect_bounds.width >= image_size.x)
            return sfRed;
        for (float y = rect_bounds.top; y <= rect_bounds.top + rect_bounds
            .height && col.g == 255 && col.b == 255 && col.r == 255; y++)
            col = sfImage_getPixel
            (map->image_collision, rect_bounds.left + rect_bounds.width, y);
    }
    if (x == -1) {
        if (rect_bounds.left < 0)
            return sfRed;
        for (float y = rect_bounds.top; y <= rect_bounds.top + rect_bounds
            .height && col.g == 255 && col.b == 255 && col.r == 255; y++)
            col = sfImage_getPixel(map->image_collision, rect_bounds.left, y);
    }
    return col;
}

sfColor check_event_collision(map_screen_t *map, int x, int y)
{
    sfFloatRect rect_bounds =
    sfRectangleShape_getGlobalBounds(map->player->hitbox);
    sfVector2f pos_on_map = get_pos_rel_to_map((sfVector2f)
        {rect_bounds.left, rect_bounds.top}, (sfVector2f){map->map_position.x,
        map->map_position.y});
    sfVector2f scale = sfSprite_getScale(map->player->sprite);
    sfVector2f position_offset = {0.0f, 0.0f};
    sfVector2u image_size = sfImage_getSize(map->image_collision);

    image_size.x *= scale.x;
    image_size.y *= scale.y;
    rect_bounds.left = (pos_on_map.x + x + position_offset.x) / scale.x;
    rect_bounds.top = (pos_on_map.y + y + position_offset.y) / scale.y;
    rect_bounds.width /= scale.x;
    rect_bounds.height /= scale.y;
    if (x != 0) {
        return collision_x(rect_bounds, x, map, image_size);
    } else
        return collision_y(rect_bounds, y, map, image_size);
}

static void check_color(map_screen_t *map, int x, int y, game_t *game)
{
    sfColor color = check_event_collision(map, x, y);

    if (color.g == 255 && color.b == 255 && color.r == 255)
        return;
    if (color.r == 0 && color.g == 255 && color.b == 0) {
        bridge_message(game, map);
    } else if (color.r == 0 && color.g == 0 && color.b == 255)
        save_message(game, map);
}

void check_direction_event(map_screen_t *map, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        check_color(map, -1, 0, game);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        check_color(map, 1, 0, game);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        check_color(map, 0, -1, game);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        check_color(map, 0, 1, game);
    if (sfKeyboard_isKeyPressed(sfKeyE))
        check_color(map, 0, 0, game);
}
