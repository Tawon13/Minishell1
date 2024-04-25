/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-amine.bechagra
** File description:
** struct
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "my.h"
#define MAXSTR 500

typedef struct variables {
    char current_dir[1024];
    char *input;
    int status;
    char *token;
} varr;
