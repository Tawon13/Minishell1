/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-amine.bechagra
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <fcntl.h>
    #include <unistd.h>

int my_putstr(char *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char *str);
int my_getnbr(char const *str);
char *hexadecimal(int nb);
char *octet(int nb);
char *binaire(int nb);
int my_printf5(const char *format, int i, va_list args);
int my_printf4(const char *format, int i, va_list args);
int numberof(char const *str);
static int my_printf3(const char *format, int i, va_list args);
int my_float(double nb);
char *my_strdup(char *str);
int my_printf(const char *format, ...);
char *my_strcat(char *dest, char const *src);
char *ptr(long format);
char *hexadecimal2(int nb);
int my_printf8(const char *format, int i, va_list args);
int unsigne(unsigned int nb);
int my_strlen(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char **environement(char **env, char **args);
int setenvironement2(char *name, char *value, char **env);
int setenvironement(char *name, char *value, char **env, char **args);
int my_strncmp(char *s1, char *s2, size_t n);
int unsetenvironement(char *name, char **env, char **args);

#endif
