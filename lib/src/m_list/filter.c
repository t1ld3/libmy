/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** list_filter
*/

#include <stddef.h>
#include "m_list.h"

list_t *list_filter(list_t *list, predicate_fptr predicate)
{
    list_t *new = NULL;
    void *current = NULL;

    new = list_create(list->compare, list->print, NULL, list->copy);
    if (new == NULL)
        return NULL;
    list->move_to_head(list);
    while (!list->is_at_tail(list)) {
        current = list->get_data(list, false);
        if (predicate(current)) {
            new->insert(new, current, true);
        }
        list->move_to_next(list);
    }
    return new;
}
