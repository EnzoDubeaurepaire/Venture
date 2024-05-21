/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include "rpg.h"

typedef struct entity {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f position;
} entity_t;

typedef struct sprint {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    float stamina;
} sprint_t;

typedef struct map_screen {
    sfSprite *map_sprite;
    sfTexture *map_texture;
    entity_t *player;
    sfVector2f map_position;
    sfVector2f player_direction;
    float speed;
    float sprint_speed;
    sprint_t *sprint;
} map_screen_t;

typedef struct bubble_s {
    sfClock *clock;
    sfRectangleShape *rect;
    int compteur;
    sfFont *font;
    sfText *text;
    sfBool is_display;
    sfBool skip_animation;
    char *message;
}bubble_t;

typedef struct launch_screen {
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *text;
    sfRectangleShape *fade;
    float fade_value;
    sfTime text_vanish;
    sfClock *vanish_clock;
    sfMusic *music;
} launch_screen_t;

typedef struct settings_screen {
    sfTexture *texture;
    sfTexture *buttons_texture;
    int main_volume;
    sfText *text_main_volume;
    sfText *text_volume;
    sfText *window_mode;
    sfText *window_size;
    sfSprite *overlay;
    sfSprite *cross;
    sfSprite *plus_button;
    sfSprite *minus_button;
    sfSprite *fullscreen_button;
    sfSprite *window_button;
    sfFont *font;
} settings_screen_t;

typedef struct menu_screen {
    sfTexture *texture;
    sfClock *clock;
    sfSprite *new_game;
    sfSprite *resume;
    sfSprite *settings;
    sfSprite *quit;
    _Bool resume_is_usable;
} menu_screen_t;

typedef struct screen {
    void *screen;
} screen_t;

typedef struct player_stat {
    sfTexture *stat_button;
    int level;
    double needed_exp;
    int att;
    int att_activated;
    sfSprite *att_sprite;
    sfRectangleShape *att_hitbox;
    int hp;
    int hp_activated;
    sfSprite *hp_sprite;
    sfRectangleShape *hp_hitbox;
    int res;
    int res_activated;
    sfSprite *res_sprite;
    sfRectangleShape *res_hitbox;
    double as;
    int as_activated;
    sfSprite *as_sprite;
    sfRectangleShape *as_hitbox;
    int total_points;
    sfTexture *skill_tree_back_t;
    sfSprite *skill_tree_back;
    sfText *level_text;
    sfText *points_text;
    sfFont *font;
} player_stat_t;

typedef struct game {
    sfRenderWindow *window;
    sfClock *clock;
    _Bool mouse_hold;
    sfKeyCode key;
    size_t active_screen;
    screen_t *screens[SCREEN_NB + 1];
    void (*screen_renderer[SCREEN_NB + 1])(struct game *game, screen_t
        *screen);
    long long last_frame_time;
} game_t;

#endif
