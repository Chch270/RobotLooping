/*
** EPITECH PROJECT, 2021
** CPOOL_2021_DAY03_STREAM
** File description:
** create_map
*/

#include "../include/sfml.h"
#include "../include/colors.h"
#include <stdlib.h>

player_t *create_player(char **map)
{
    player_t *player = malloc(sizeof(player_t *));
    sfTexture *texture = sfTexture_createFromFile("assets/robot.png", NULL);

    player->sprite = sfSprite_create();
    sfSprite_setTexture(player->sprite, texture, sfFalse);
    sfSprite_setScale(player->sprite, (sfVector2f){0.25, 0.25});
    for (int i = 0; map[i] != NULL; ++i)
        for (int j = 0; map[i][j] != '\0'; ++j)
            if (map[i][j] == 'P')
            {
                sfSprite_setPosition(player->sprite, (sfVector2f){400 + (j * 105), 50 + (i * 105)});
                return (player);
            }
    return (player);
}

void create_obstacles(parameters *params, char **map)
{
    sfTexture *texture = sfTexture_createFromFile("assets/obstacle.png", NULL);
    int nobs = 0;
    int size = 100;

    for (int i = 0; map[i] != NULL; ++i)
        for (int j = 0; map[i][j] != '\0'; ++j)
            if (map[i][j] == '.')
            {
                params->obstacles = realloc(params->obstacles, sizeof(sfSprite *) * (nobs + 2));
                params->obstacles[nobs] = sfSprite_create();
                sfSprite_setTexture(params->obstacles[nobs], texture, sfFalse);
                sfSprite_setPosition(params->obstacles[nobs], (sfVector2f){400 + (j * (size + 5)), 50 + (i * (size + 5))});
                sfSprite_setScale(params->obstacles[nobs], (sfVector2f){0.167, 0.167});
                params->obstacles[nobs + 1] = NULL;
                ++nobs;
            }
}

sfRectangleShape **create_map(char **map)
{
    sfRectangleShape **gmap = NULL;
    int idx = 0;
    int size = 100;

    for (int i = 0; map[i] != NULL; ++i)
    {
        for (int j = 0; map[i][j] != '\0'; ++j)
        {
            gmap = realloc(gmap, sizeof(sfRectangleShape *) * (idx + 2));
            gmap[idx] = sfRectangleShape_create();
            sfRectangleShape_setPosition(gmap[idx], (sfVector2f){400 + (j * (size + 5)), 50 + (i * (size + 5))});
            sfRectangleShape_setSize(gmap[idx], (sfVector2f){size, size});
            for (int x = 0; tab_colors[x].name != NULL; ++x)
                if (tab_colors[x].letter == map[i][j])
                    sfRectangleShape_setFillColor(gmap[idx], tab_colors[x].color);
            ++idx;
            gmap[idx] = NULL;
        }
    }
    return (gmap);
}