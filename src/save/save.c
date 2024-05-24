/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** save.c
*/

#include "../../include/rpg.h"
#include <fcntl.h>

static _Bool check_file(FILE *file, int *elements)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < SAVED_ELEMENTS; i++) {
        read = getline(&line, &len, file);
        if (!check_element[i](line, read)) {
            free(line);
            return 0;
        }
        elements[i] = atoi(line);
    }
    free(line);
    return 1;
}

static void load_items(game_t *game, int *elements)
{
    pick_up_item(game, elements[12]);
    pick_up_item(game, elements[13]);
    pick_up_item(game, elements[14]);
    pick_up_item(game, elements[15]);
    pick_up_item(game, elements[16]);
    pick_up_item(game, elements[17]);
    pick_up_item(game, elements[18]);
    pick_up_item(game, elements[19]);
}

void load_save(int *elements, game_t *game)
{
    map_screen_t *map = game->screens[2]->screen;
    player_stat_t *stats = game->screens[5]->screen;

    sfSprite_setPosition(map->map_sprite, (sfVector2f){(float)elements[0],
        (float)elements[1]});
    stats->level = elements[2];
    stats->total_points = elements[3];
    stats->att = elements[4];
    stats->att_activated = elements[5];
    stats->as = elements[6];
    stats->as_activated = elements[7];
    stats->actual_hp = elements[8];
    stats->hp = elements[8];
    stats->hp_activated = elements[9];
    stats->res = elements[10];
    stats->res_activated = elements[11];
    load_items(game, elements);
    if (elements[20])
        switch_map(map);
    map->bridge_repared = elements[20];
}

static int count_lines(FILE *file)
{
    int i = 0;
    char *line = NULL;
    size_t len = 0;

    for (size_t read = getline(&line, &len, file); read != -1ul;
        read = getline(&line, &len, file))
        i++;
    free(line);
    return i;
}

_Bool check_save(game_t *game)
{
    FILE *save = fopen(".save", "r");
    int *elements = malloc(sizeof(int) * SAVED_ELEMENTS);

    if (!save) {
        free(elements);
        return 0;
    }
    if (count_lines(save) != SAVED_ELEMENTS || !check_file(save, elements)) {
        free(elements);
        fclose(save);
        return 0;
    }
    load_save(elements, game);
    free(elements);
    fclose(save);
    return 1;
}

_Bool is_save_ok(void)
{
    FILE *save = fopen(".save", "r");
    int *elements = malloc(sizeof(int) * SAVED_ELEMENTS);

    if (!save) {
        free(elements);
        return 0;
    }
    if (count_lines(save) != SAVED_ELEMENTS || !check_file(save, elements)) {
        free(elements);
        fclose(save);
        return 0;
    }
    free(elements);
    fclose(save);
    return 1;
}

void save(game_t *game)
{
    int fd = open(".save", O_CREAT | O_WRONLY, S_IRWXO | S_IRWXG | S_IRWXU);
    map_screen_t *map = game->screens[2]->screen;
    player_stat_t *stat = game->screens[5]->screen;
    slot_t **inv = map->inventory->slot_tab;

    click_sound(game);
    if (fd == -1)
        return;
    dprintf(fd, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d"
        "\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
        (int)sfSprite_getPosition(map->map_sprite).x,
        (int)sfSprite_getPosition(map->map_sprite).y, stat->level,
        stat->total_points, stat->att, stat->att_activated, (int)stat->as,
        stat->as_activated, stat->hp, stat->hp_activated, stat->res,
        stat->res_activated, inv[0]->stored_item, inv[1]->stored_item,
        inv[2]->stored_item, inv[3]->stored_item, inv[4]->stored_item,
        inv[5]->stored_item, inv[6]->stored_item, inv[7]->stored_item,
        map->bridge_repared);
    close(fd);
}
