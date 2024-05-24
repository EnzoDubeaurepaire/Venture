/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** check_assets.c
*/

#include "../../include/rpg.h"
#include "fcntl.h"

static _Bool exist(char *path)
{
    int exist = access(path, R_OK);

    if (exist == 0)
        return 1;
    return 0;
}

static void check_fonts(void)
{
    if (!exist("assets/fonts/commando.ttf") ||
        !exist("assets/fonts/venite.ttf"))
        exit(84);
}

static void check_musics(void)
{
    if (!exist("assets/music/boss_final.ogg") ||
        !exist("assets/music/boss_short.ogg") ||
        !exist("assets/music/button.ogg") ||
        !exist("assets/music/exploration_negative.ogg") ||
        !exist("assets/music/exploration_positive.ogg") ||
        !exist("assets/music/journey.ogg") ||
        !exist("assets/music/keyboard_sound.ogg") ||
        !exist("assets/music/mystery.ogg") ||
        !exist("assets/music/sinister.ogg") ||
        !exist("assets/music/space.ogg") ||
        !exist("assets/music/truth.ogg"))
        exit(84);
}

static void check_textures(void)
{
    if (!exist("assets/enemies/enemy_1.png") ||
        !exist("assets/enemies/enemy_2.png") ||
        !exist("assets/enemies/enemy_3.png") ||
        !exist("assets/enemies/enemy_4.png") ||
        !exist("assets/bush.png") ||
        !exist("assets/map.png") ||
        !exist("assets/menu/background_title.jpg") ||
        !exist("assets/menu/buttons.png") ||
        !exist("assets/pause_buttons.png") ||
        !exist("assets/player_sprite.png") ||
        !exist("assets/sprint_bar.png") ||
        !exist("assets/stats.png") ||
        !exist("assets/stats_button.png") ||
        !exist("assets/settings/buttons_screen.png") ||
        !exist("assets/settings/settings.png") ||
        !exist("assets/settings/settings_overlay.png") ||
        !exist("assets/settings/settings_overlay.png") ||
        !exist("assets/how_to_play.png") ||
        !exist("assets/settings/controls.png"))
        exit(84);
}

void check_assets(void)
{
    check_musics();
    check_fonts();
    check_textures();
}
