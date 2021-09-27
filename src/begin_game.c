/*
** EPITECH PROJECT, 2021
** CPOOL_2021_DAY03_STREAM
** File description:
** begin_game
*/

#include "sfml.h"
#include <unistd.h>

void game(parameters *params);
player_t *create_player(char **map);
sfRectangleShape **create_map(char **map);

void display_game(sfRectangleShape **gmap, sfRenderWindow *win, player_t *player)
{
    for (int i = 0; gmap[i] != NULL; ++i)
        sfRenderWindow_drawRectangleShape(win, gmap[i], NULL);
    sfRenderWindow_drawSprite(win, player->sprite, NULL);
    sfRenderWindow_display(win);
    sfRenderWindow_clear(win, sfBlack);
}

void begin_game(char **map)
{
    sfEvent event;
    sfRenderWindow *win = sfRenderWindow_create((sfVideoMode){1920, 1080, 64}, "game", sfDefaultStyle, NULL);
    sfRectangleShape **gmap = create_map(map);
    player_t *player = create_player(map);
    parameters params = {.gmap = gmap, .player = player, .win = win};

    while (sfRenderWindow_isOpen(win))
    {
        while (sfRenderWindow_pollEvent(win, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(win);
        }
        display_game(gmap, win, player);
        game(&params);
        sleep(5);
        return;
    }
}