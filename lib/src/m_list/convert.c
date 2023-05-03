/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** list utils
*/

#include "m_list.h"
#include "m_string.h"
#include <stdlib.h>

void word_array_free_data(void **data_ptr)
{
    char *data = (char *) (*data_ptr);

    if (data != NULL)
        free(data);
    *data_ptr = NULL;
}

list_t *word_array_convert_to_list(
    char *const word_array[], print_fptr print, data_copy_fptr copy)
{
    list_t *new = NULL;
    void *data = NULL;

    if ((new = list_create(NULL, print, word_array_free_data, copy)) == NULL)
        return NULL;
    for (size_t i = 0; word_array[i] != NULL; i++) {
        data = m_strdup(word_array[i]);
        new->insert(new, data, true);
    }
    return new;
}
