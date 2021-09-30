/*
** EPITECH PROJECT, 2021
** CPOOL_2021_DAY03_STREAM
** File description:
** begin_game
*/

#include "../include/sfml.h"
#include <unistd.h>

void game(parameters *params);
void create_obstacles(parameters *params, char **map);
player_t *create_player(char **map);
sfRectangleShape **create_map(char **map);

void display_game(parameters *params)
{
    for (int i = 0; params->gmap[i] != NULL; ++i)
        sfRenderWindow_drawRectangleShape(params->win, params->gmap[i], NULL);
    if (params->obstacles)
        for (int i = 0; params->obstacles[i] != NULL; ++i)
            sfRenderWindow_drawSprite(params->win, params->obstacles[i], NULL);
    sfRenderWindow_drawSprite(params->win, params->player->sprite, NULL);
    sfRenderWindow_display(params->win);
    sfRenderWindow_clear(params->win, sfBlack);
}

void begin_game(char **map)
{
    sfEvent event;
    sfRenderWindow *win = sfRenderWindow_create((sfVideoMode){1920, 1080, 64}, "game", sfDefaultStyle, NULL);
    sfRectangleShape **gmap = create_map(map);
    player_t *player = create_player(map);
    parameters params = {.gmap = gmap, .player = player, .win = win, .obstacles = NULL};
    create_obstacles(&params, map);

    while (sfRenderWindow_isOpen(win))
    {
        while (sfRenderWindow_pollEvent(win, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(win);
        display_game(&params);
        game(&params);
        sleep(5);
        return;
    }
}