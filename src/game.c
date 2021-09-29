/*
** EPITECH PROJECT, 2021
** CPOOL_2021_DAY03_STREAM
** File description:
** game
*/

#include "sfml.h"

void go_up(parameters *params);
void go_down(parameters *params);
void go_left(parameters *params);
void go_right(parameters *params);
void change_color(parameters *params, char *color);

void up_four_times(parameters *params)
{
    for (int i = 0; i != 4; ++i)
        go_up(params);
}

void game(parameters *params)
{
    go_right(params);
    change_color(params, "BLEU");
    go_right(params);
    change_color(params, "ROUGE");
    go_right(params);
    change_color(params, "JAUNE");
    go_right(params);
    change_color(params, "VERT");
}