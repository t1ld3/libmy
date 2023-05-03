/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** list_add
*/

#include <stddef.h>
#include "list_internal.h"

void list_insert(void *list_addr, void *data, bool before_cursor)
{
    list_t *list = NULL;
    list_node_t *node = NULL;

    if ((list = (list_t *) list_addr) == NULL)
        return;
    if ((node = list_node_create(data)) == NULL)
        return;
    node->next = list->cnext;
    node->prev = list->cprev;
    list->cnext->prev = node;
    list->cprev->next = node;
    if (before_cursor)
        list->cprev = node;
    else
        list->cnext = node;
    list->length++;
}
