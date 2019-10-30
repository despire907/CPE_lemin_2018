/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** main function
*/

#include "constructeur.h"

void free_input(char **input)
{
    int i = 0;

    while (input[i] != NULL) {
        free(input[i]);
        i++;
    }
    free(input);
}

void free_node(input_t *input, node_t *node)
{
    node_t *tmp = node;

    while (node != NULL) {
        tmp = node->ll_next;
        free(node);
        node = tmp;
    }
    free_input(input->names);
    free_input(input->link);
    free(input);
}