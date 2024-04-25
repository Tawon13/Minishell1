/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-amine.bechagra
** File description:
** my_strncmp
*/

#include <stdlib.h>
#include "my.h"


int my_strncmp(char *s1, char *s2, size_t n)
{
    size_t i = 0;

    while (i < n && (s1[i] != '\0' || s2[i] != '\0')) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return 0;
}
