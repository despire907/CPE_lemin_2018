/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** main function
*/

#ifndef CPE_LEMIN_2018_CONSTRUCTEUR_H
#define CPE_LEMIN_2018_CONSTRUCTEUR_H

#include "parsing.h"

typedef struct input {
    char **names;
    char **link;
}input_t;

typedef struct s_node {
    char *name;
    int ant;
    int flag;
    int nb_nexts;
    struct s_node **nexts;
    struct s_node *ll_next;
} node_t;

typedef struct s_path{
    node_t *node;
    struct s_path *next;
} path_t;

typedef struct s_path_list{
    path_t *path;
    struct s_path_list *next;
} path_list_t;

enum flag_e {flag_active = 1, flag_inactive = 0, flag_end = 666, flag_start = 5};

node_t *new_node(char *name);
char *my_strdup_from_to(char *str, char start, char end);
node_t **realloc_nexts(node_t **array, node_t *elem, int count);
void add_next(node_t *first, node_t *second);
void link_nodes(node_t *elem, char *link);
node_t *get_lemin_tree(input_t *input);
void move_ants(path_list_t *paths);
void move_in_path(path_t *path);
path_list_t *get_paths(node_t *node);
path_list_t *queue_path(int flag);
int get_next_node(node_t *node);
node_t **sort(node_t **list);
int sort_closest(node_t *node, int jump);
int sort_closest_from_end(node_t *end);
int get_next_node(node_t *node);
int get_paths_bis(node_t *node);
path_t *path_new_elem(node_t *node);
path_list_t *path_list_new_elem(path_t *path);
path_t *register_path_node(node_t *node, int flag);

#endif //CPE_LEMIN_2018_CONSTRUCTEUR_H
