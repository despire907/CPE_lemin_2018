/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** main function
*/

#include "constructeur.h"

path_list_t *queue_path(int flag)
{
    static path_list_t *begin = NULL;
    static path_list_t *elem;
    path_t *path = register_path_node(NULL, 0);

    if (!begin && path && flag)
        begin = path_list_new_elem(path);
    else if (begin && path && flag) {
        if (elem) {
            elem->next = path_list_new_elem(path);
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

node_t **sort_node_tab(node_t **list)
{
    int i = 0;
    node_t *temp;

    while (list[i] && list[i + 1]) {
        if (list[i]->jump > list[i + 1]->jump) {
            temp = list[i];
            list[i] = list[i + 1];
            list[i + 1] = temp;
            i = 0;
        }
        ++i;
    }
}

int sort_closest(node_t *node, int jump)
{
    int i = 0;

    if (node->flag == flag_inactive)
        node->flag = flag_active;
    else
        return 0;
    if (!node->jump || node->jump > jump)
        node->jump = jump;
    else
        return 1;

    while (node->nexts[i]) {
        if (!node->nexts[i]->jump && node->nexts[i]->jump > jump + 1)
            sort_closest(node->nexts[i], jump + 1);
        ++i;
    }
    node->flag = flag_inactive;
    node->nexts = sort_node_tab(node->nexts);
    return status;
}

int sort_closest_from_end(node_t *end)
{
    int i = 0;

    if (end->flag != flag_end)
        return 0;
    while (node->nexts[i]) {
        sort_closest(node->nexts[i], 1);
        ++i;
    }
    return 1;
}
