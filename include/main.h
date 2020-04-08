/*
** EPITECH PROJECT, 2020
** all lib
** File description:
** include aml lib
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "lib.h"

typedef struct main_s
{
   int ant;
   int tunels;
   char **map;
   char *input;
}main_t;

void read_file(main_t *my_struct);

#endif /* !MAIN_H_ */
