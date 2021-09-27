/*
** EPITECH PROJECT, 2021
** CPOOL_2021_DAY03_STREAM
** File description:
** create_map
*/

#include "sfml.h"
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

sfRectangleShape **create_map(char **map)
{
    sfRectangleShape **gmap = malloc((sizeof(sfRectangleShape *) * 20 * 20) + 1);
    int idx = 0;
    int size = 100;

    gmap[(sizeof(sfRectangleShape *) * 10 * 10) + 1] = NULL;
    for (int i = 0; map[i] != NULL; ++i)
        for (int j = 0; map[i][j] != '\0'; ++j)
        {
            gmap[idx] = sfRectangleShape_create();
            sfRectangleShape_setPosition(gmap[idx], (sfVector2f){400 + (i * (size + 5)), 50 + (j * (size + 5))});
            sfRectangleShape_setSize(gmap[idx], (sfVector2f){size, size});
            sfRectangleShape_setFillColor(gmap[idx], map[j][i] == 'G' ? sfYellow : sfGreen);
            ++idx;
        }
    return (gmap);
}