/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** lemin
*/

#include "lib.h"
#include "main.h"

void print_rooms(main_t *struct_main)
{
    write(1, "#number_of_ants\n", 16);
    write (1, struct_main->map[0], strlen(struct_main->map[0]));
    write(1, "\n#rooms\n", 8);
    for (int i = 1; struct_main->map[i]; i += 1) {
        write (1, struct_main->map[i], strlen(struct_main->map[i]));
        write(1, "\n", 1);
    }
}

char *uncomment(char *str)
{
    int i = 0;
    char *str2 = malloc(sizeof(char) * 4096);

    for (i; str[i]; i += 1) {
        if (str[i] == '#') {
            if (str[i + 1] == '#') {
                str2[i] = str[i];
                i += 1;
            }
            else
                break;
        }
        str2[i] = str[i];
    }
    str2[i + 1] = '\0';
    return  (str2);
}

void attribute_to(main_t *struct_main, char *str, int n)
{
    struct_main->map[n] = malloc(sizeof(char) * 4096);
    struct_main->map[n] = str;
}

void attribute_fourmiz(main_t *struct_main, char **temp)
{
    int r = 5;

    attribute_to(struct_main, temp[0], 0);
    for (int i = 1; temp[i]; i += 1) {
        if (my_strncmp(temp[i], "##start", 7) == 0) {
            attribute_to(struct_main, temp[i], 1);
            attribute_to(struct_main, temp[i + 1], 2);
            i += 1;
        } else if (my_strncmp(temp[i], "##end", 5) == 0) {
            attribute_to(struct_main, temp[i], 3);
            attribute_to(struct_main, temp[i + 1], 4);
            i += 1;
        } else {
            attribute_to(struct_main, temp[i], r);
            r += 1;
        }
    }
}

void map_parsing(main_t *struct_main)
{
    char **temp = my_str_to_word_array(struct_main->input, '\n');
    char **temp2 = malloc(sizeof(char *) * 4096);
    char *temp3 = 0;
    int f = 0;

    struct_main->map = malloc(sizeof(char) * 4096);
    for (int i = 0; temp[i];i += 1) {
        if (temp[i][0] == '#' && temp[i][1] != '#') {
        } else {
            temp2[f] = malloc(sizeof(char) * 4096);
            temp3 = uncomment(temp[i]);
            temp2[f] = temp3;
            f += 1;
        }
    }
    attribute_fourmiz(struct_main, temp2);
    print_rooms(struct_main);
}