/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-amine.bechagra
** File description:
** get_line_widht
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int get_line_width(char *str, int start)
{
    int q = start;

    while (str[q] != '\n' && str[q] != '\0')
        q++;
    return q - start;
}
