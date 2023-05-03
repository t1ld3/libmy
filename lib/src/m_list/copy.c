/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** list copy
*/

#include <stdlib.h>
#include "list_internal.h"

list_t *list_copy(list_t *list)
{
    list_t *new = NULL;
    void *data = NULL;
    list_cursor_t cursor;

    new = list_create(list->compare, list->print, list->destroy, list->copy);
    if (new == NULL)
        return NULL;
    cursor = list_get_cursor(list);
    list->move_to_head(list);
    while (!list->is_at_tail(list)) {
        if (list->copy != NULL)
            data = list->copy(list, false);
        else
            data = list->get_data(list, false);
        new->insert(new, data, false);
        list->move_to_next(list);
        new->move_to_next(new);
    }
    list_set_cursor(list, cursor);
    return new;
}
