/*
** EPITECH PROJECT, 2021
** CPOOL_2021_DAY03_STREAM
** File description:
** sfml
*/

#ifndef SFML_H_
#define SFML_H_

#include "SFML/System.h"
#include "SFML/Graphics.h"
#include "SFML/Window.h"
#include <string.h>

typedef struct tkt_s
{
    char *name;
    const sfColor color;
} tkt_t;

static const tkt_t tab_colors[] = {
    {"ROUGE", (sfColor){255, 0, 0, 255}},
    {"BLEU", (sfColor){0, 0, 255, 255}},
    {"VERT", (sfColor){0, 255, 0, 255}},
    {"JAUNE", (sfColor){255, 255, 0, 255}},
    {NULL, (sfColor){0, 0, 0, 0}}};

typedef struct player_s
{
    sfSprite *sprite;
    sfVector2f prevPos;
} player_t;

typedef struct parameter_s
{
    sfRenderWindow *win;
    sfRectangleShape **gmap;
    player_t *player;
} parameters;

#endif /* !SFML_H_ */
