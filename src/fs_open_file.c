/*
** EPITECH PROJECT, 2018
** fs_open_file
** File description:
** CPE_lemin_2018
*/

#include"parsing.h"

char *fs_getline_standard(void)
{
    int check = 0;
    char *buf = NULL;
    size_t buf_size = 0;

    if ((check = getline(&buf, &buf_size, STDIN_FILENO)) == 0)
        return NULL;
    if (check == -1) {
        free(buf);
        return NULL;
    }
    return buf;
}
