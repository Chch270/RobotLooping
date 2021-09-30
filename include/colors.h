/*
** EPITECH PROJECT, 2021
** RobotLooping
** File description:
** colors
*/

#pragma once

typedef struct tkt_s
{
    char letter;
    char *name;
    sfColor color;
} tkt_t;

static const tkt_t tab_colors[] = {
    {'R', "ROUGE", (sfColor){255, 0, 0, 255}},
    {'B', "BLEU", (sfColor){0, 0, 255, 255}},
    {'G', "VERT", (sfColor){0, 255, 0, 255}},
    {'Y', "JAUNE", (sfColor){255, 255, 0, 255}},
    {'W', "BLANC", (sfColor){255, 255, 255, 255}},
    {'\0', NULL, (sfColor){0, 0, 0, 0}}};
