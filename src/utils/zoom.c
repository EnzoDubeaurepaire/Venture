/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** my_rpg
*/

#include "rpg.h"

void zoom_centered(resources_t *r)
{
    sfFloatRect rect = sfText_getGlobalBounds(r->title_text);
    float center_x = rect.left + rect.width / 2;
    float center_y = rect.top + rect.height / 2;
    sfVector2f center = (sfVector2f){center_x, center_y};
    float scale = 1 + rect.width / 200000;
    sfFloatRect new_rect = sfText_getGlobalBounds(r->title_text);
    float new_center_x = new_rect.left + new_rect.width / 2;
    float new_center_y = new_rect.top + new_rect.height / 2;
    sfVector2f new_center = (sfVector2f){new_center_x, new_center_y};
    sfVector2f offset = (sfVector2f)
        {center.x - new_center.x, center.y - new_center.y};

    sfText_scale(r->title_text, (sfVector2f){scale, scale});
    sfText_move(r->title_text, offset);
}

static sfVector2f zoom_helper(sfFloatRect rect, float scale_factor)
{
    sfVector2f center = {1920 / 2, 1080 / 2};
    sfVector2f corner = {rect.left, rect.top};
    sfVector2f direct = {corner.x - center.x, corner.y - center.y};
    float magnitude = sqrt(direct.x * direct.x + direct.y * direct.y);
    sfVector2f unit_direct = {direct.x / magnitude, direct.y / magnitude};
    sfVector2f new_corner = {
        center.x + unit_direct.x * magnitude * scale_factor,
        center.y + unit_direct.y * magnitude * scale_factor
    };

    return (sfVector2f){new_corner.x - corner.x, new_corner.y - corner.y};
}

void zoom_text(sfText *text, float scale_factor)
{
    sfFloatRect rect_bounds = sfText_getGlobalBounds(text);

    sfText_scale(text, (sfVector2f){scale_factor, scale_factor});
    sfText_move(text, zoom_helper(rect_bounds, scale_factor));
}

void zoom_rect(sfRectangleShape *rect, float scale_factor)
{
    sfFloatRect rect_bounds = sfRectangleShape_getGlobalBounds(rect);

    sfRectangleShape_scale(rect, (sfVector2f){scale_factor, scale_factor});
    sfRectangleShape_move(rect, zoom_helper(rect_bounds, scale_factor));
}

void zoom_sprite(sfSprite *sprite, float scale_factor)
{
    sfFloatRect rect_bounds = sfSprite_getGlobalBounds(sprite);

    sfSprite_scale(sprite, (sfVector2f){scale_factor, scale_factor});
    sfSprite_move(sprite, zoom_helper(rect_bounds, scale_factor));
}
