/*
** EPITECH PROJECT, 2018
** bsq.c
** File description:
** find the biggest square in a map
*/

#include "function_bsq.h"

char **last_convert(char **map)
{
    int a = 0;

    while (map[a] != NULL) {
        map[a] = change_number_to_char(map[a]);
        a = a + 1;
    }
    return (map);
}

char **final_map(char **map, char *buffer)
{
    int a = 0;
    int i = 0;
    int j = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            i = i + 1;
            a = a + 1;
            j = 0;
        }
        else if (map[a][j] == 'x') {
            i = i + 1;
            j = j + 1;
        } else {
            map[a][j] = buffer[i];
            i = i + 1;
            j = j + 1;
        }
    }
    map = last_convert(map);
    return (map);
}
