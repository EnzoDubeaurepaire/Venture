/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** dialogue.c
*/

#include "../../include/rpg.h"

void display_all(game_t *game, bubble_t *bubble, char const *displayed_message)
{
    sfText_setString(bubble->text, displayed_message);
    sfRenderWindow_drawRectangleShape(game->window, bubble->rect, NULL);
    sfRenderWindow_drawText(game->window, bubble->text, NULL);
    if (strcmp(displayed_message, bubble->message) == 0)
        bubble->skip_animation = sfTrue;
}

void render_dialogue(game_t *game, screen_t *screen)
{
    bubble_t *bubble = screen->screen;
    char *displayed_message = malloc(strlen(bubble->message) + 1);
    sfTime elapsed = sfClock_getElapsedTime(bubble->clock);
    float deltaTime = sfTime_asSeconds(elapsed);

    event_dialogue(game, bubble);
    if (bubble->skip_animation == sfFalse && deltaTime >= DELAY &&
        bubble->compteur < (int)strlen(bubble->message)) {
        bubble->compteur++;
        sfClock_restart(bubble->clock);
    } else if (bubble->skip_animation == sfTrue) {
        strcpy(displayed_message, bubble->message);
        bubble->compteur = strlen(bubble->message);
    } else {
        strncpy(displayed_message, bubble->message, bubble->compteur);
        displayed_message[bubble->compteur] = '\0';
    }
    display_all(game, bubble, displayed_message);
    free(displayed_message);
}
