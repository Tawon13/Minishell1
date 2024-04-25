/*
** EPITECH PROJECT, 2024
** B-CPE-110-MAR-1-1-secured-samy.chakrouni
** File description:
** strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *new = malloc(sizeof(char) * (len + 1));

    my_strcpy(new, str);
    return new;
}
