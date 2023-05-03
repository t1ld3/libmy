/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** test_list
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/m_list/list_internal.h"
#include "m_list.h"

Test(list_create, good_init) {
    list_t *list = NULL;

    list = list_create(NULL, NULL, NULL, NULL);
    cr_assert_not_null(list);
    cr_assert_not_null(list->sentinel);
    cr_assert_eq(list->cnext, list->sentinel);
    cr_assert_eq(list->cprev, list->sentinel);
    cr_assert_eq(list->sentinel->next, list->sentinel);
    cr_assert_eq(list->sentinel->prev, list->sentinel);
    cr_assert_eq(list->length, 0);
    cr_assert_eq(list->insert, list_insert);
    cr_assert_eq(list->remove, list_remove_data);
    cr_assert_eq(list->get_data, list_get_data);
    cr_assert_eq(list->set_data, list_set_data);
    cr_assert_eq(list->get_len, list_get_len);
    cr_assert_eq(list->move_to_next, list_move_cursor_to_next);
    cr_assert_eq(list->move_to_prev, list_move_cursor_to_prev);
    cr_assert_eq(list->move_to_head, list_move_cursor_to_head);
    cr_assert_eq(list->move_to_tail, list_move_cursor_to_tail);
    cr_assert_eq(list->is_at_head, list_is_at_head);
    cr_assert_eq(list->is_at_tail, list_is_at_tail);
    cr_assert_eq(list->is_empty, list_is_empty);
    cr_assert_null(list->compare);
    cr_assert_null(list->destroy);
    cr_assert_null(list->print);
    list_destroy(&list);
    cr_assert_null(list);
}

Test(list_create, good_linking) {
    list_t *list = list_create(NULL, NULL, NULL, NULL);

    list->insert(list, (void *) 42, false);
    list->insert(list, (void *) 64, false);
    list->insert(list, (void *) 56, false);
    cr_assert_eq(list->get_len(list), 3);
    cr_assert_eq(list->get_data(list, false), (void *) 56);
    list->move_to_tail(list);
    cr_assert_eq(list->get_data(list, true), (void *) 42);
    list->remove(list, true, false);
    cr_assert_eq(list->get_len(list), 2);
    cr_assert_eq(list->get_data(list, true), (void *) 64);
    list->move_to_prev(list);
    cr_assert_eq(list->get_data(list, true), (void *) 56);
    list_destroy(&list);
    cr_assert_null(list);
}

Test(list, good_linking_addr) {
    list_t *list = list_create(NULL, NULL, NULL, NULL);
    list_node_t *sentinel = NULL;

    cr_assert_not_null(list);
    list->insert(list, (void *) 42, true);
    list->insert(list, (void *) 64, true);
    list->insert(list, (void *) 56, true);
    sentinel = list->sentinel;
    cr_assert(sentinel->next->prev == sentinel);
    cr_assert(sentinel->next->next->prev == sentinel->next);
    cr_assert(sentinel->next->next->next->prev == sentinel->next->next);
    cr_assert(sentinel->next == sentinel->prev->prev->prev);
    cr_assert(sentinel->next->next == sentinel->prev->prev);
    cr_assert(sentinel->next->next->next == sentinel->prev);
    cr_assert(sentinel->next->next->next != sentinel);
    cr_assert(sentinel->next->next != sentinel);
    cr_assert(sentinel->next != sentinel);
    cr_assert(sentinel->prev->prev->prev != sentinel);
    cr_assert(sentinel->prev->prev != sentinel);
    cr_assert(sentinel->prev != sentinel);
    list_destroy(&list);
}
