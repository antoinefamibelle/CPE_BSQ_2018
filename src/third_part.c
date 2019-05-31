/*
** EPITECH PROJECT, 2018
** bsq.c
** File description:
** find the biggest square of a map
*/

#include "function_bsq.h"
#include <stdio.h>

int add_minor(int n1, int n2, int n3)
{
    if (n1 <= n2) {
        if (n1 <= n3)
            return (n1);
        else
            return (n3);
    }
    else {
        if (n2 <= n3)
            return (n2);
        else
            return (n3);
    }
    return (84);
}

int number_of_return(char *buffer)
{
    int i = 0;
    int compteur = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            compteur = compteur + 1;
        i = i + 1;
    }
    return (compteur);
}

char **put_buffer_in_map(char *buffer)
{
    char **map = malloc(sizeof(char*) *(number_of_return(buffer)));
    int a = 0;
    int i = 0;
    int j = 0;

    while (buffer[i] != '\0') {
        map[a] = malloc(sizeof(char) * (number_of_char(buffer) + 2));
        while (buffer[i] != '\n') {
            map[a][j] = buffer[i];
            i = i + 1;
            j = j + 1;
        }
        map[a][j] = '\n';
        map[a][j + 1] = '\0';
        a = a + 1;
        i = i + 1;
        j = 0;
    }
    return (map);
}
