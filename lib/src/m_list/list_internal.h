/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** list_internal header
*/

#ifndef LIST_INTERNAL_H
    #define LIST_INTERNAL_H
    #include "m_list.h"

// list.c
list_node_t *list_node_create(void *data);
// get.c
void *list_get_data(void *list_addr, bool before);
size_t list_get_len(void *list_addr);
// set.c
void list_set_data(
    void *list_addr, void *data, bool before_cursor, bool destroy_data);
// add.c
void list_insert(void *list_addr, void *data, bool before_cursor);
// remove.c
void list_remove_data(void *list_addr, bool before, bool destroy_data);
// moves.c
void list_move_cursor_to_head(void *list_addr);
void list_move_cursor_to_tail(void *list_addr);
void list_move_cursor_to_next(void *list_addr);
void list_move_cursor_to_prev(void *list_addr);
// checks.c
bool list_is_at_tail(void *list_addr);
bool list_is_at_head(void *list_addr);
bool list_is_empty(void *list_addr);
#endif /* ifndef LIST_INTERNAL_H */
