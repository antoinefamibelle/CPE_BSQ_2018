/*
** EPITECH PROJECT, 2018
** bsq.c
** File description:
** find the biggest square
*/

#include "function_bsq.h"

int take_big(char *map)
{
    int i = 0;
    int big = 0;

    while (map[i] != '\n') {
        if (map[i] - '0' > big)
            big = map[i] - '0';
        i = i + 1;
    }
    return (big);
}

int find_j(int big, char *map)
{
    int i = 0;

    while (map[i] - '0' != big)
        i = i + 1;
    return (i);
}

char **put_the_square(int big, char **map, int a, int j)
{
    int tmp = big;
    int tmp_2 = big;
    int j_tmp = j;

    while (big != 0) {
        while (tmp != 0) {
            map[a][j] = 'x';
            j = j - 1;
            tmp = tmp - 1;
        }
        big = big - 1;
        tmp = tmp_2;
        j = j_tmp;
        a = a - 1;
    }
    return (map);
}

char **last_step(char **map)
{
    int a = 0;
    int big = 0;
    int tmp;
    int position_a;
    int position_j;

    while (map[a] != NULL) {
        tmp = take_big(map[a]);
        if (tmp > big) {
            big = tmp;
            position_a = a;
        }
        a = a + 1;
    }
    position_j = find_j(big, map[position_a]);   
    map = put_the_square(big, map, position_a, position_j);
    return (map);
}

char *change_number_to_char(char *map)
{
    int i = 0;

    while (map[i] != '\n') {
        if (map[i] == '1')
            map[i] = '.';
        else if (map[i] == '0')
            map[i] = 'o';
        else
            i = i + 1;
    }
    return (map);
}
