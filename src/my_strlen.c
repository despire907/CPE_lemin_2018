/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** my_strlen
*/

#include"parsing.h"

int my_strlen(char *str)
{
   int i = 0;

   if (str == NULL)
       return 0;
   while (str[i]) {
       i++;
   }
   return i;
}
