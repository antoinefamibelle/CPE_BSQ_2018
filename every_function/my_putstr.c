/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** print a string
*/

void my_putchar(char c);

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
