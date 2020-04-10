/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** lemin
*/

#include "lib.h"
#include "main.h"

int main(void)
{
    main_t struct_main;
    graph_t *graph;
    //error_management(&struct_main);
    read_file(&struct_main);
    map_parsing(&struct_main);
    //graph = init_graph(&struct_main, graph);
    return (0);
}