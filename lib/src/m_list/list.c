/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_list
*/

#include <stdlib.h>
#include "list_internal.h"
#include "m_string.h"

static void list_make_capabilities(list_t *new)
{
    new->set_data = list_set_data;
    new->get_data = list_get_data;
    new->get_len = list_get_len;
    new->insert = list_insert;
    new->remove = list_remove_data;
    new->move_to_next = list_move_cursor_to_next;
    new->move_to_prev = list_move_cursor_to_prev;
    new->move_to_head = list_move_cursor_to_head;
    new->move_to_tail = list_move_cursor_to_tail;
    new->is_at_head = list_is_at_head;
    new->is_at_tail = list_is_at_tail;
    new->is_empty = list_is_empty;
}

list_t *list_create(cmp_data_fptr compare, print_fptr print,
    destructor_fptr destroy, data_copy_fptr copy)
{
    list_t *new = NULL;

    if ((new = malloc(sizeof(*new))) == NULL)
        return NULL;
    if ((new->sentinel = malloc(sizeof(*new->sentinel))) == NULL) {
        free(new);
        return NULL;
    }
    new->sentinel->next = new->sentinel;
    new->sentinel->prev = new->sentinel;
    new->cnext = new->sentinel;
    new->cprev = new->sentinel;
    new->compare = compare;
    new->print = print;
    new->destroy = destroy;
    new->copy = copy;
    new->length = 0;
    list_make_capabilities(new);
    return new;
}

list_node_t *list_node_create(void *data)
{
    list_node_t *new = NULL;

    if ((new = malloc(sizeof(*new))) == NULL)
        return NULL;
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void list_destroy(list_t **list)
{
    list_t *to_destroy = NULL;
    list_node_t *current = NULL;
    list_node_t *next = NULL;

    if (list == NULL || *list == NULL)
        return;
    to_destroy = *list;
    current = to_destroy->sentinel->next;
    while (current != to_destroy->sentinel) {
        next = current->next;
        if (to_destroy->destroy != NULL) {
            to_destroy->destroy(&current->data);
        }
        free(current);
        current = next;
    }
    free(to_destroy->sentinel);
    free(to_destroy);
    *list = NULL;
}
