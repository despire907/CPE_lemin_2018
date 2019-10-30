/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** main function
*/

#include "constructeur.h"

path_list_t *get_paths(node_t *node)
{
    int i;
    int status = 0;
    path_list_t *list;

    if (flag != flag_start)
        return 0;
    while (node->nexts[i]) {
        if (status = get_next_node(node->nexts[i]) != 0) {
            register_path_node(node, 1);
            queue_path(1);
        }
        ++i;
    }
    return queue_path(0);
}

void move_in_path(path_t *path)
{
    if (path->next && path->next->node->ant == 1) {
        path->next->node->ant = 0;
        path->node->ant += 1;
        my_putchar('P');
        my_putstr(path->next->node->name);
        my_putstr("->");
        my_putstr(path->node->name);
        my_putchar(' ');
    }
    move_in_path(path->next);
}

void move_ants(path_list_t *paths)
{
    while (paths) {
        move_in_path(paths->path);
        paths = paths->next;
        my_putchar('\n');
    }
}