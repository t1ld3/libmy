/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** list header
*/

#ifndef M_LIST_H
    #define M_LIST_H
    #define __need_size_t
    #include <stdbool.h>
    #include <stddef.h>

// capabilities

typedef int (*cmp_data_fptr)(void *, void *);
typedef void (*destructor_fptr)(void **);
typedef void (*print_fptr)(void *);
typedef void *(*data_copy_fptr)(void *, bool);
typedef void *(*get_data_fptr)(void *, bool);
typedef void (*set_data_fptr)(void *, void *, bool, bool);
typedef void (*insert_data_fptr)(void *, void *, bool);
typedef size_t (*get_len_fptr)(void *);
typedef void (*remove_data_fptr)(void *, bool, bool);
typedef void (*move_cursor_fptr)(void *);
typedef bool (*check_fptr)(void *);
typedef bool (*predicate_fptr)(void *);

typedef struct list_node_s list_node_t;

struct list_node_s {
    void *data;
    list_node_t *next;
    list_node_t *prev;
};

typedef struct list_cursor_s list_cursor_t;

struct list_cursor_s {
    list_node_t *cnext;
    list_node_t *cprev;
};

typedef struct list_s list_t;

struct list_s {
    list_node_t *sentinel;
    list_node_t *cnext;
    list_node_t *cprev;
    size_t length;
    insert_data_fptr insert;
    remove_data_fptr remove;
    get_data_fptr get_data;
    set_data_fptr set_data;
    get_len_fptr get_len;
    move_cursor_fptr move_to_next;
    move_cursor_fptr move_to_prev;
    move_cursor_fptr move_to_head;
    move_cursor_fptr move_to_tail;
    check_fptr is_at_head;
    check_fptr is_at_tail;
    check_fptr is_empty;
    cmp_data_fptr compare;
    destructor_fptr destroy;
    data_copy_fptr copy;
    print_fptr print;
};

list_t *list_create(cmp_data_fptr compare, print_fptr print,
    destructor_fptr destroy, data_copy_fptr copy);
void list_destroy(list_t **list);
list_t *list_copy(list_t *list);
list_cursor_t list_get_cursor(list_t *list);
void list_set_cursor(list_t *list, list_cursor_t cursor);
list_t *word_array_convert_to_list(
    char *const word_array[], print_fptr print, data_copy_fptr copy);
void list_print(list_t *list, char const *sep);
list_t *word_array_convert_to_list(
    char *const word_array[], print_fptr print, data_copy_fptr copy);
#endif /* ifndef M_LIST_H */
