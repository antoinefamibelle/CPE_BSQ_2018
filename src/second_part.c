/*
** EPITECH PROJECT, 2018
** bsq.c
** File description:
** find the biggest squre
*/

#include "function_bsq.h"

char *convert_in_int(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            i = i + 1;
        if (buffer[i] == 'o')
            buffer[i] = '0';
        if (buffer[i] == '.')
            buffer[i] = '1';
        i = i + 1;
    }
    return (buffer);
}

int number_of_char(char *buffer)
{
    int i = 0 ;
    int a = 0;
    while (buffer[i] != '\n')
        i = i + 1;
    i = i + 1;
    while (buffer[i] != '\n') {
        i = i + 1;
        a = a + 1;
    }
    return (a);
}

char *cut_begin(char *buffer)
{
    int i = 0;
    int a = 0;
    char *string = malloc(sizeof(char) * (my_strlen(buffer)));

    while (buffer[i] != '\n')
        i = i + 1;
    i = i + 1;
    while (buffer[i] != '\0') {
        string[a] = buffer[i];
        i = i + 1;
        a = a + 1;
    }
    string[a + 1] = '\0';
    return (string);
}

char *add_converter(char *map, char *old_map)
{
    int i = 1;
    int n1;
    int n2;
    int n3;
    int tmp;
    
    while (map[i] != '\0') {
        while (map[i] == '0')
            i = i + 1;
        if (map[i] == '\n')
            return (map);
        n1 = old_map[i] - '0';
        n2 = old_map[i - 1] - '0';
        n3 = map[i - 1] - '0';
        tmp = add_minor(n1, n2, n3);
        map[i] = map[i] + tmp;
        i = i + 1;
    }
    map[i] = '\0';
    return (map);
}
