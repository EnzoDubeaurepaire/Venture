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
    sfRectangleShape *hitbox;
    sfBool is_hitbox;
    sfVector2f pos_rel_to_map;
} entity_t;

typedef struct sprint {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    float stamina;
} sprint_t;

typedef struct map_screen {
    sfSprite *collision_sprite;
    sfTexture *collision_texture;
    sfSprite *map_sprite;
    sfTexture *map_texture;
    entity_t *player;
    sfVector2f map_position;
    sfVector2f player_direction;
    float speed;
    float sprint_speed;
    sprint_t *sprint;
    sfRectangleShape *mini_map;
    sfSprite *mini_map_player;
    sfImage *image_collision;
    sfTexture *bush_texture;
    sfSprite *bush_sprite;
    bool got_wood;
    sfTexture *object_texture[8];
    sfSprite *object_table[8];
    sfVector2f *object_pos[8];
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
    sfTexture *tuto_texture;
    sfSprite *tuto;
    _Bool show_tuto;
} launch_screen_t;

typedef struct settings_screen {
    sfTexture *texture;
    sfTexture *buttons_texture;
    sfTexture *button_texture_screen;
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
    sfSprite *resize_button;
    sfSprite *window_button;
    sfFont *font;
    sfSprite *controls;
    sfTexture *controls_texture;
} settings_screen_t;

typedef struct menu_screen {
    sfTexture *texture;
    sfClock *clock;
    sfSprite *new_game;
    sfSprite *resume;
    sfSprite *settings;
    sfSprite *quit;
    _Bool resume_is_usable;
    sfMusic *music;
} menu_screen_t;

typedef struct pause_screen {
    sfTexture *texture;
    sfSprite *quit;
    sfSprite *save;
    sfSprite *chara;
    sfSprite *sett;
} pause_screen_t;

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

typedef struct music_s {
    sfMusic *menu_music;
    sfMusic *typing_music;
    sfMusic *button_click;
    sfMusic *walking;
} music_t;

typedef struct game {
    sfRenderWindow *window;
    _Bool window_state;
    _Bool resolution_state;
    sfClock *clock;
    _Bool mouse_hold;
    sfKeyCode key;
    size_t active_screen;
    screen_t *screens[SCREEN_NB + 1];
    void (*screen_renderer[SCREEN_NB + 1])(struct game *game, screen_t
        *screen);
    void (*screen_destroyer[SCREEN_NB + 1])(screen_t *screen);
    long long last_frame_time;
    _Bool save;
    music_t *music;
} game_t;

#endif
