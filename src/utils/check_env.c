/*
** EPITECH PROJECT, 2024
** rpg_mirror
** File description:
** check_assets.c
*/

#include "../../include/rpg.h"

void check_env(char **env)
{
    if (!env)
        exit(84);
    for (int i = 0; env[i]; i++)
        if (strncmp(env[i], "DISPLAY=", 8) == 0)
            return;
    exit(84);
}
