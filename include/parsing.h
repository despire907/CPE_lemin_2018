/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** main function
*/

#ifndef LEMIN_H
#define LEMIN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_load_file {
    char *line;
    struct s_load_file *next;
}load_file_t;

int my_strlen(char *str);
char *fs_getline_standard(void);
int my_strlen(char *str);
load_file_t *new_str_elem(char *str);
char **str_to_tab(load_file_t *begin);
void free_load_file(load_file_t *begin);
char **read_input(void);

#endif //LEMIN_H
