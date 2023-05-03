/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** list moves
*/

#include <stddef.h>
#include "list_internal.h"

void list_move_cursor_to_head(void *list_addr)
{
    list_t *list = (list_t *) list_addr;

    if (list == NULL) {
        return;
    }
    list->cprev = list->sentinel;
    list->cnext = list->sentinel->next;
}

void list_move_cursor_to_tail(void *list_addr)
{
    list_t *list = (list_t *) list_addr;

    if (list == NULL) {
        return;
    }
    list->cnext = list->sentinel;
    list->cprev = list->sentinel->prev;
}

void list_move_cursor_to_next(void *list_addr)
{
    list_t *list = (list_t *) list_addr;

    if (list == NULL) {
        return;
    }
    list->cprev = list->cnext;
    list->cnext = list->cnext->next;
}

void list_move_cursor_to_prev(void *list_addr)
{
    list_t *list = (list_t *) list_addr;

    if (list == NULL) {
        return;
    }
    list->cnext = list->cprev;
    list->cprev = list->cprev->prev;
}
