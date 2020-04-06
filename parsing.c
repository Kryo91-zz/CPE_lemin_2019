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
    char *str = malloc(sizeof(char) * 4096);
    int i = 0;
    int j = 1;

    i = read(0, str, 4096);
    char **map = my_str_to_word_array(str, "\n");
    struct_main->ant = atoi(map[0]);
    printf("#number_of_ants\n%d\n#rooms\n", struct_main->ant);
    for (; map[j][1] != '-'; ++j)
        printf("%s\n", map[j]);
    struct_main->tunels = j;
    printf("#tunnels\n");
    for (; map[struct_main->tunels] != NULL; ++struct_main->tunels)
        printf("%s\n", map[struct_main->tunels]);
}