/*
** EPITECH PROJECT, 2020
** check all error 
** File description:
** lem_in
*/

#include "main.h"

int my_strlen(char const *str)
{
    int result;

    for (result = 0; *str; result++);
    return (result);
}

char *my_strdup(char *src)
{
    int length = my_strlen(src);
    char *dest = malloc(length + 1);

    for (length = 0; *src; length++)
        dest[length] = src[length];
    dest[length] = '\0';
    return (dest);
}

void read_file(main_t *my_struct)
{
    char *buff = malloc(sizeof(char) * 10000);
    int offset = 0;

    my_struct->input = '\0';
    while (read(0, buff + offset, 1) > 0 && offset < 9999)
        offset += 1;
    buff[offset] = '\0';
    my_struct->input = my_strdup(buff);
    free(buff);
}
