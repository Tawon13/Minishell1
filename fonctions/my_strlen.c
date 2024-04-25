/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include "my.h"

int my_strlen(char *str)
{
    int m = 0;

    while (str[m] != '\0') {
        m++;
    }
    return m;
}
