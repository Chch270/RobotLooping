/*
** EPITECH PROJECT, 2021
** CPOOL_2021_DAY03_STREAM
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void begin_game(char **map);

static char **get_text_infile(char *map)
{
    char *buf = NULL;
    char **tab = NULL;
    size_t size = 0;
    FILE *fd = fopen(map, "r");

    if (!fd)
        return (NULL);
    for (int i = 0; getline(&buf, &size, fd) != -1; ++i)
    {
        buf[strlen(buf) - 1] = '\0';
        tab = realloc(tab, sizeof(char *) * (i + 2));
        tab[i] = strdup(buf);
        tab[i + 1] = NULL;
        free(buf);
        buf = NULL;
    }
    free(buf);
    fclose(fd);
    return (tab);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    char **map = get_text_infile(av[1]);
    begin_game(map);
}