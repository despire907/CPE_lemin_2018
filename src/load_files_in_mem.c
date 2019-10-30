/*
** EPITECH PROJECT, 2018
** load_files_in_mem
** File description:
** CPE_lemin_2018
*/


#include "parsing.h"

load_file_t *new_str_elem(char *str)
{
    load_file_t *new_elem = malloc(sizeof(load_file_t));

    if (!new_elem)
        return NULL;
    if (str[my_strlen(str) - 1] == '\n')
        str[my_strlen(str) - 1] = '\0';
    new_elem->line = str;
    new_elem->next = NULL;

    return new_elem;
}

char **str_to_tab(load_file_t *begin)
{
    int i = 0;
    int count = 0;
    char **dest;
    load_file_t *parse = begin;

    while (parse) {
        count++;
        parse = parse->next;
    }
    if (!(dest = malloc(sizeof(char*) * (count + 1))))
        return NULL;
    parse = begin;
    while (i < count) {
        dest[i] = parse->line;
        i++;
        parse = parse->next;
    }
    dest[i] = NULL;
    return dest;
}

void free_load_file(load_file_t *begin)
{
    load_file_t *tmp;

    while (begin->next) {
        tmp = begin->next;
        free(begin);
        begin = tmp;
    }
    free(begin);
}

char **read_input(void)
{
    load_file_t *begin = NULL;
    load_file_t *elem = NULL;
    char *buf;
    char **dest;

    while ((buf = fs_getline_standard())) {
	      if (!begin) {
            begin = new_str_elem(buf);
            elem = begin;
        } else {
            elem->next = new_str_elem(buf);
            elem = elem->next;
        }
    }
    dest = str_to_tab(begin);
    free_load_file(begin);
    return dest;
}
