/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-amine.bechagra
** File description:
** environement
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>
#include "my.h"
#include "struct.h"

static int is_alphanumeric(const char *str)
{
    while (*str) {
        if (!(((*str >= 'A' && *str <= 'Z') ||
            (*str >= 'a' && *str <= 'z')) || (*str >= '0' && *str <= '9')))
            return 0;
        str++;
    }
    return 1;
}

char **environement(char **env, char **args)
{
    int i;

    for (i = 0; env[i] != NULL; i++)
        my_printf("\n%s", env[i]);
    my_printf("\n");
    return 0;
}

int unsetenvironement2(char *name, char **env, int i)
{
    for (int j = i; env[j] != NULL; j++)
        env[j] = env[j + 1];
    return 0;
}

int unsetenvironement(char *name, char **env, char **args)
{
    int i = 0;

    if (!args[1]) {
        my_printf("setenv: Too few arguments.\n");
        exit(EXIT_FAILURE);
    }
    while (env[i] != NULL) {
        if (my_strncmp(env[i], name, my_strlen(name)) == 0 &&
        env[i][my_strlen(name)] == '=') {
            unsetenvironement2(name, env, i);
        }
        i++;
    }
    return -1;
}

int setenvironement2(char *name, char *value, char **env)
{
    int overwrite;
    char *new_var;
    int i = 0;

    if (overwrite) {
        new_var = malloc(my_strlen(name) + my_strlen(value) + 2);
        my_strcpy(new_var, name);
        my_strcat(new_var, "=");
        my_strcat(new_var, value);
        env[i] = new_var;
        return 0;
    }
    return 0;
}

static int gestion(char **args, char **env)
{
    if (!args[1]) {
        environement(env, args);
        exit(EXIT_FAILURE);
    }
    if (!is_alphanumeric(args[1])) {
        my_printf("setenv: Variable name must");
        my_printf(" contain alphanumeric characters.\n");
        exit(EXIT_FAILURE);
    } else if (!isalpha(args[1][0])) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        exit(EXIT_FAILURE);
    }
    if (!args[2]) {
        my_printf("setenv: Too few arguments.\n");
        exit(EXIT_FAILURE);
    } else if (args[3]) {
        my_printf("setenv: Too many arguments.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

int setenvironement(char *name, char *value, char **env, char **args)
{
    int overwrite;
    int i = 0;
    int len = 0;
    char *new_var;
    int errors = 0;

    gestion(args, env);
    while (env[i]) {
        len = my_strlen(name);
        if (my_strncmp(env[i], name, len) == 0)
            setenvironement2(name, value, env);
        i++;
    }
    new_var = malloc(my_strlen(name) + my_strlen(value) + 2);
    my_strcpy(new_var, name);
    my_strcat(new_var, "=");
    my_strcat(new_var, value);
    env[i] = new_var;
    env[i + 1] = NULL;
    return 1;
}
