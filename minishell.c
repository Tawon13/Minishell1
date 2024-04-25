/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-minishell1-amine.bechagra
** File description:
** minishell
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "include/my.h"
#include "include/struct.h"

int directory(varr *var, char **args)
{
    if (args[1] == NULL)
        exit(1);
    if (chdir(args[1]) != 0) {
        perror("chdir");
    } else
        getcwd(var->current_dir, sizeof(var->current_dir));
    return 0;
}

int flags2(varr *var, char **args, char **env)
{
    if (my_strcmp(args[0], "pwd") == 0)
        execve("/bin/pwd", args, NULL);
    if (my_strcmp(args[0], "id") == 0)
        execve("/usr/bin/id", args, NULL);
    if (my_strcmp(args[0], "/bin/ls") == 0 || my_strcmp(args[0], "ls") == 0)
        execve("/bin/ls", args, NULL);
    else if (my_strcmp(args[0], "env") == 0)
        environement(env, args);
    return 0;
}

int flags(varr *var, char **env, int overwrite, int i)
{
    char *token = strtok(var->input, " \t\n;");
    char *args[10];

    for (i = 0; token != NULL && i < 9; i++) {
        args[i] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
    flags2(var, args, env);
    if (my_strcmp(args[0], "cd") == 0)
        directory(var, args);
    if (my_strcmp(args[0], "setenv") == 0)
        setenvironement(args[1], args[2], env, args);
    if (my_strcmp(args[0], "unsetenv") == 0)
        unsetenvironement(args[1], env, args);
    return 0;
}

int main2(varr var, char **env, int overwrite, int i)
{
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        flags(&var, env, overwrite, i);
    } else {
        waitpid(pid, NULL, 0);
    }
    free(var.input);
    return 0;
}

int main(int argc, char **argv, char **env)
{
    int i;
    int overwrite = 0;
    varr var;
    size_t bufsize = 0;
    char *line = NULL;

    while (1) {
        my_printf("%s", "Minishell> ");
        if (getline(&line, &bufsize, stdin) == -1)
            exit(EXIT_FAILURE);
        var.input = my_strdup(line);
        if (my_strcmp(var.input, "exit") == 0)
            return 0;
        line = NULL;
        if (var.input[my_strlen(var.input) - 1] == '\n')
            var.input[my_strlen(var.input) - 1] = '\0';
        main2(var, env, overwrite, i);
    }
    return 0;
}
