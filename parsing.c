/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** lemin
*/

#include "lib.h"
#include "main.h"

void map_parsing(main_t *struct_main)
{
    int i = 0;
    int j = 1;

    struct_main->map = my_str_to_word_array(struct_main->input, '\n');
    struct_main->ant = atoi(struct_main->map[0]);
    printf("#number_of_ants\n%d\n#rooms\n", struct_main->ant);
    for (; struct_main->map[j][1] != '-'; ++j)
        printf("%s\n", struct_main->map[j]);
    struct_main->tunels = j;
    printf("#tunnels\n");
    for (; struct_main->map[struct_main->tunels] != NULL; ++struct_main->tunels)
        printf("%s\n", struct_main->map[struct_main->tunels]);
}