/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** list get
*/

#include <stddef.h>
#include "list_internal.h"

void *list_get_data(void *list_addr, bool before)
{
    list_t *list = NULL;

    if ((list = (list_t *) list_addr) == NULL)
        return NULL;
    if (before) {
        return list->cprev->data;
    } else {
        return list->cnext->data;
    }
}

size_t list_get_len(void *list_addr)
{
    list_t *list = NULL;

    if ((list = (list_t *) list_addr) == NULL)
        return 0;
    return list->length;
}

list_cursor_t list_get_cursor(list_t *list)
{
    list_cursor_t cursor;

    cursor.cnext = list->cnext;
    cursor.cprev = list->cprev;
    return cursor;
}
