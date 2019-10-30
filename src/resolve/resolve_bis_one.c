/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** main function
*/

#include "constructeur.h"

int get_next_node(node_t *node)
{
    int i;
    int status = 0;

    if (flag == flag_end)
        return 1;
    if (flag != flag_inactive)
        return 0;
    while (node->nexts[i] && !status) {
        status = get_next_node(node->nexts[i]);
        if(!status)
            ++i;
    }
    if (status)
        register_path_node(node->nexts[i], 1);
    return status;
}

path_t *path_new_elem(node_t *node)
{
    path_t *elem = malloc(sizeof(path_t));

    if (!elem)
        return NULL;
    elem->node = node;
    elem->next = NULL;
    return elem;
}

path_list_t *path_list_new_elem(path_t *path)
{
    path_list_t *elem = malloc(sizeof(path_list_t));

    if (!elem)
        return NULL;
    elem->path = path;
    elem->next = NULL;
    return elem;
}

path_t *register_path_node(node_t *node, int flag)
{
    static path_t *begin = NULL;
    static path_t *elem;

    if (!begin && node && flag)
        begin = path_new_elem(node);
    else if (begin && node && flag) {
        if (elem) {
            elem->next = path_new_elem(node);
            elem = elem->next;
        } else
            elem = elem->next;
    }
    if (!flag) {
        elem = begin;
        begin = NULL;
        return elem;
    }
    return NULL;
}