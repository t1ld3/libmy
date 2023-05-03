/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** list checks
*/

#include <stddef.h>
#include "list_internal.h"

bool list_is_at_head(void *list_addr)
{
    list_t *list = NULL;

    if ((list = (list_t *) list_addr) == NULL)
        return false;
    return list->cprev == list->sentinel;
}

bool list_is_at_tail(void *list_addr)
{
    list_t *list = NULL;

    if ((list = (list_t *) list_addr) == NULL)
        return false;
    return list->cnext == list->sentinel;
}

bool list_is_empty(void *list_addr)
{
    list_t *list = NULL;

    if ((list = (list_t *) list_addr) == NULL)
        return false;
    return list->length == 0;
}
