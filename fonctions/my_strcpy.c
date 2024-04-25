/*
** EPITECH PROJECT, 2023
** day06
** File description:
** day06
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int Z = 0;

    while (src[Z] != '\0') {
        dest[Z] = src[Z];
        Z++;
    }
    dest[Z] = '\0';
    return 0;
}
