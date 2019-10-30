/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** main function
*/

#include "constructeur.h"

nodes_t **get_nodes_tab(nodes_t *begin)
{
    int i = 0;
    nodes_t *parse = begin;
    nodes_t **dest;

    while (parse) {
        if (parse->nexts != NULL)
            i++;
        parse = parse->next;
    }
    if (!dest = malloc(sizeof(nodes_t *) * (i + 1)))
        return NULL;
    i = 0;
    parse = begin;
    while (parse) {
        if (parse->nexts != NULL)
            dest[i++] = parse;
        parse = parse->next;
    }
    dest[i] = NULL;
    return dest;
}

node_t *get_lemin_tree(input_t *input)
{
    int i = 0;
    node_t *elem = NULL;
    node_t *begin = NULL;
    nodes_t **nodes;

    while (input->names[i]) {
        if (!begin) {
            begin = new_node(input->names[i]);
            elem = begin;
        } else {
            elem = new_node(input->names[i]);
            elem = elem->ll_next;
        }
        i++;
    }
    i = 0;
    while (input->link[i])
        link_nodes(begin, input->link[i++]);
    return get_nodes_tab(nodes_t *begin);
}