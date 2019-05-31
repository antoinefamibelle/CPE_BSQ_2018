/*
** EPITECH PROJECT, 2018
** bsq.c
** File description:
** Find the biggest square on a map!
*/

#include "function_bsq.h"
#include <stdio.h>

char *open_the_file(char const *filepath)
{
    struct stat buf;
    int fd;
    long long len_max;
    char *buffer;

    fd = open(filepath, O_RDONLY);
    stat(filepath, &buf);
    len_max = buf.st_size;
    buffer = malloc(sizeof(char) * (len_max + 1));
    read(fd, buffer, len_max);
    buffer[len_max] = '\0';
    close(fd);
    buffer = convert_in_int(buffer);
    buffer = cut_begin(buffer);
    return (buffer);
}

void free_all(char *old_map, char **map, char *buffer)
{
    int a = 0;

    free(old_map);
    while (map[a] != NULL) {
        free(map[a]);
        a = a + 1;
    }
    free(map);
    free(buffer);
}

void bsq(char const *filepath)
{
    char *buffer = open_the_file(filepath);
    char **map = malloc(sizeof(char*) * (number_of_return(buffer)));;
    char *old_map;
    int a = 1;

    map = put_buffer_in_map(buffer);
    while (map[a] != NULL) {
        old_map = map[a - 1];
        map[a] = add_converter(map[a], old_map);
        a = a + 1;
    }
    map = last_step(map);
    a = 0;
    map = final_map(map, buffer);
    while (map[a] != NULL) {
        my_putstr(map[a]);
        a = a + 1;
    }
    free_all(old_map, map, buffer);
}        

int main(int ac, char **av)
{
    char *filepath = av[1];

    if (ac != 2)
        return (84);
    bsq(filepath);
    return (0);
}
