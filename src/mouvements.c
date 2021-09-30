/*
** EPITECH PROJECT, 2021
** CPOOL_2021_DAY03_STREAM
** File description:
** mouvements
*/

#include "../include/sfml.h"
#include "../include/colors.h"

void display_game(parameters *params);

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
            display_game(params);
            sfClock_destroy(clock);
            return;
        }
    }
}

int move(parameters *params, sfVector2f move)
{
    sfVector2f now = sfSprite_getPosition(params->player->sprite);
    sfVector2f block = {0};

    if (params->obstacles)
        for (int i = 0; params->obstacles[i] != NULL; ++i)
        {
            block = sfSprite_getPosition(params->obstacles[i]);
            if (now.x + move.x == block.x && now.y + move.y == block.y)
                return (0);
        }
    sfSprite_setPosition(params->player->sprite, (sfVector2f){now.x + move.x, now.y + move.y});
    pause_clock(params);
    return (1);
}

int go_up(parameters *params)
{
    return move(params, (sfVector2f){0, -105});
}

int go_down(parameters *params)
{
    return move(params, (sfVector2f){0, 105});
}

int go_left(parameters *params)
{
    return move(params, (sfVector2f){-105, 0});
}

int go_right(parameters *params)
{
    return move(params, (sfVector2f){105, 0});
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