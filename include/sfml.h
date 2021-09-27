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
