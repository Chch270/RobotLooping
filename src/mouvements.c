/*
** EPITECH PROJECT, 2021
** CPOOL_2021_DAY03_STREAM
** File description:
** mouvements
*/

#include "sfml.h"

void display_game(sfRectangleShape **gmap, sfRenderWindow *win, player_t *player);

void pause_clock(parameters *params)
{
    sfClock *clock = sfClock_create();
    sfEvent event;

    while (params->win)
    {
        while (sfRenderWindow_pollEvent(params->win, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(params->win);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 1000)
        {
            display_game(params->gmap, params->win, params->player);
            sfClock_destroy(clock);
            return;
        }
    }
}

void move(parameters *params, sfVector2f move)
{
    sfVector2f now = sfSprite_getPosition(params->player->sprite);
    sfSprite_setPosition(params->player->sprite, (sfVector2f){now.x + move.x, now.y + move.y});
    pause_clock(params);
}

void go_up(parameters *params)
{
    move(params, (sfVector2f){0, -105});
}

void go_down(parameters *params)
{
    move(params, (sfVector2f){0, 105});
}

void go_left(parameters *params)
{
    move(params, (sfVector2f){-105, 0});
}

void go_right(parameters *params)
{
    move(params, (sfVector2f){105, 0});
}

void change_color(parameters *params, char *color)
{
    sfVector2f pos = sfSprite_getPosition(params->player->sprite);
    sfVector2f mpos = {0};
    sfColor new_color = {0, 0, 0, 0};

    for (int i = 0; tab_colors[i].name != NULL; ++i)
        if (!strcmp(tab_colors[i].name, color))
            new_color = tab_colors[i].color;
    for (int i = 0; params->gmap[i] != NULL; ++i)
    {
        mpos = sfRectangleShape_getPosition(params->gmap[i]);
        if (mpos.x == pos.x && mpos.y == pos.y)
            sfRectangleShape_setFillColor(params->gmap[i], new_color);
    }
    pause_clock(params);
}