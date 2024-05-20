/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_struct_dialogue
*/

#include "../../include/rpg.h"

sfRectangleShape* create_rect(sfRenderWindow* window, float width, float
    height)
{
    sfRectangleShape* rectangle = sfRectangleShape_create();
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f position = {300, (float)(window_size.y - height - 100)};
    sfColor color = {0, 0, 0, 200};

    sfRectangleShape_setSize(rectangle, (sfVector2f){width, height});
    sfRectangleShape_setPosition(rectangle, position);
    sfRectangleShape_setFillColor(rectangle, color);
    sfRectangleShape_setOutlineThickness(rectangle, 2);
    sfRectangleShape_setOutlineColor(rectangle, sfWhite);
    return rectangle;
}

void init_text(bubble_t *new)
{
    sfVector2f rect_pos;

    new->text = sfText_create();
    sfText_setFont(new->text, new->font);
    sfText_setCharacterSize(new->text, 18);
    rect_pos = sfRectangleShape_getPosition(new->rect);
    sfText_setPosition(new->text, (sfVector2f)
    {rect_pos.x + 25, rect_pos.y + 25});
}

screen_t *init_bubble(sfRenderWindow *window)
{
    screen_t *screen = malloc(sizeof(screen_t));
    bubble_t *new = malloc(sizeof(bubble_t));

    if (new == NULL)
        return NULL;
    new->is_display = sfFalse;
    new->skip_animation = sfFalse;
    new->compteur = 0;
    new->clock = sfClock_create();
    new->rect = create_rect(window, 1300, 200);
    new->font = sfFont_createFromFile("assets/fonts/venite.ttf");
    if (!new->font)
        return NULL;
    init_text(new);
    screen->screen = new;
    return screen;
}
