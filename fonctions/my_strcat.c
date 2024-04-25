/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-amine.bechagra
** File description:
** my_strcat
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);

    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}
