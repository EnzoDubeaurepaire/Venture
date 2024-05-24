/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** collision.c
*/

#include "../../include/rpg.h"

bool is_red_pixel(sfColor color)
{
    return color.r == 255 && color.g == 0 && color.b == 0;
}

bool check_pixel(map_screen_t *map, float x, float y)
{
    if (is_red_pixel(sfImage_getPixel(map->image_collision, x, y))) {
        return true;
    }
    return false;
}

bool collision_y(sfFloatRect rect_bounds, int y, map_screen_t *map,
    sfVector2u image_size)
{
    bool col = false;

    if (y == 1) {
        if (rect_bounds.top + rect_bounds.height >= image_size.y)
            col = true;
        for (float x = rect_bounds.left; x <= rect_bounds.left + rect_bounds
            .width && !col; x++)
            col = check_pixel(map, x, rect_bounds.top + rect_bounds.height);
    }
    if (y == -1) {
        if (rect_bounds.top < 0)
            col = true;
        for (float x = rect_bounds.left; x <= rect_bounds.left + rect_bounds
            .width && !col; x++)
            col = check_pixel(map, x, rect_bounds.top);
    }
    return col;
}

bool collision_x(sfFloatRect rect_bounds, int x, map_screen_t *map,
    sfVector2u image_size)
{
    bool col = false;

    if (x == 1) {
        if (rect_bounds.left + rect_bounds.width >= image_size.x)
            col = true;
        for (float y = rect_bounds.top; y <= rect_bounds.top +
            rect_bounds.height && !col; y++)
            col = check_pixel(map, rect_bounds.left + rect_bounds.width, y);
    }
    if (x == -1) {
        if (rect_bounds.left < 0)
            col = true;
        for (float y = rect_bounds.top; y <= rect_bounds.top +
            rect_bounds.height && !col; y++)
            col = check_pixel(map, rect_bounds.left, y);
    }
    return col;
}

bool check_collision(map_screen_t *map, entity_t *entity, int x, int y)
{
    sfFloatRect rect_bounds =
        sfRectangleShape_getGlobalBounds(entity->hitbox);
    sfVector2f pos_on_map = get_pos_rel_to_map((sfVector2f)
    {rect_bounds.left, rect_bounds.top}, (sfVector2f){map->map_position.x,
        map->map_position.y});
    sfVector2f scale = sfSprite_getScale(entity->sprite);
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
