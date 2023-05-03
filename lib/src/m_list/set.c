/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** list_set
*/

#include <stddef.h>
#include "list_internal.h"

void list_set_data(
    void *list_addr, void *data, bool before_cursor, bool destroy_data)
{
    list_t *list = NULL;
    list_node_t *node = NULL;

    if ((list = (list_t *) list_addr) == NULL)
        return;
    if (before_cursor)
        node = list->cprev;
    else
        node = list->cnext;
    if (destroy_data)
        list->destroy(node->data);
    node->data = data;
}

void list_set_cursor(list_t *list, list_cursor_t cursor)
{
    list->cnext = cursor.cnext;
    list->cprev = cursor.cprev;
}
