/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** main function
*/

#include "constructeur.h"

node_t *new_node(char *name)
{
    node_t *new_elem = malloc(sizeof(node_t));

    if (!new_elem || !name)
        return null;
    new_elem->name = name;
    new_elem->ant = 0;
    new_elem->flag = 0;
    new_elem->jump = 0;
    new_elem->nexts = NULL;

    return new_elem;
}

char *my_strdup_from_to(char *str, char start, char end)
{
    int i = 0;
    int count = 0;
    char *dest = NULL;

    if (start) {
        while (str[i] != start)
            i++;
        i++;
    }
    while (str[i + count] != end)
        count++;
    dest = malloc(sizeof(char) * (count + 1));
    count = 0;
    while (str[i] != end) {
        dest[count] = str[i];
        i++;
        count++;
    }
    dest[count] = '\0';
    return dest;
}

node_t **realloc_nexts(node_t **array, node_t *elem, int count)
{
    node_t **dest = malloc(sizeof(node_t *) * (count + 2));
    int i = 0;

    while (array[i]) {
        dest[i] = array[i];
        i++;
    }
    dest[i] = elem;
    dest[i + 1] = NULL;
    return dest;
}

void add_next(node_t *first, node_t *second) 
{
    int = 0;

    if (first) {
        if (!first->nexts)
            first->nexts = malloc(sizeof(node_t) * 2);
        while (first->nexts[i]) {
            first->nexts = realloc_nexts(first->nexts, i);
            i++;
        }
    }
}

void link_nodes(node_t *elem, char *link)
{
    char *first = my_strdup_from_to(link, '\0',  '-');
    char *second = my_strdup_from_to(link, '-', '\n');
    node_t first_node = NULL;
    node_t second_node = NULL;

    free(link);
    while (elem) {
        if (!my_str_cmp(elem->name, first))
            first_node = elem;
        if (!my_str_cmp(elem->name, second))
            second_node = elem;
        elem = elem->next;
    }
    add_next(first, second);
    add_next(second, first);
}