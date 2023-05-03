/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** list print
*/

#include "m_list.h"
#include "m_stdio.h"

void list_print(list_t *list, char const *sep)
{
    list_node_t *cursor;

    cursor = list->sentinel->next;
    while (cursor != list->sentinel) {
        list->print(cursor->data);
        m_puts(sep);
        cursor = cursor->next;
    }
}
