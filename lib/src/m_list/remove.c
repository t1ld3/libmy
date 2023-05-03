/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** list remove
*/

#include <stdlib.h>
#include "list_internal.h"

static void list_remove_destroy_ressources(
    list_t *list, list_node_t *node, bool destroy_data)
{
    if (destroy_data && list->destroy != NULL)
        list->destroy(&node->data);
    free(node);
}

void list_remove_data(void *list_addr, bool before, bool destroy_data)
{
    list_t *list = NULL;
    list_node_t *next = NULL;
    list_node_t *prev = NULL;

    list = (list_t *) list_addr;
    prev = list->cprev;
    next = list->cnext;
    if (before) {
        next->prev = prev->prev;
        prev->prev->next = next;
        list->cprev = prev->prev;
        list_remove_destroy_ressources(list, prev, destroy_data);
    } else {
        prev->next = next->next;
        next->next->prev = prev;
        list->cnext = next->next;
        prev = next;
        list_remove_destroy_ressources(list, next, destroy_data);
    }
    list->length--;
}
