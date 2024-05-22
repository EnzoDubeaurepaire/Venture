/*
** EPITECH PROJECT, 2023
** rr
** File description:
** rr
*/

#include "../../include/rpg.h"

sfSprite *create_sprite(sfTexture *texture,
    sfVector2f position, sfVector2f scale)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, position);
    return sprite;
}
