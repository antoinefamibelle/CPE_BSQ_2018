/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** return the lenght of a string
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
