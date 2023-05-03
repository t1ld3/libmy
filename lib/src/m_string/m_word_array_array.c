/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_word_array_array
*/

#include <stdlib.h>
#include "m_string.h"

char ***m_word_array_array_create(char *const *word_array, char const *delim)
{
    char ***new = NULL;
    size_t length = 0;

    length = m_word_array_len(word_array);
    if (length == 0)
        return NULL;
    if ((new = malloc(sizeof(*new) * (length + 1))) == NULL)
        return NULL;
    for (size_t i = 0; i < length; i++)
        new[i] = m_word_array_create(word_array[i], delim);
    new[length] = NULL;
    return new;
}

size_t m_word_array_array_len(char **const *word_array_array)
{
    size_t length = 0;

    if (word_array_array == NULL)
        return 0;
    while (*word_array_array != NULL) {
        length++;
        word_array_array++;
    }
    return length;
}

void m_word_array_array_destroy(char ****word_array_array_ptr)
{
    char ***word_array_array = *word_array_array_ptr;

    if (word_array_array == NULL)
        return;
    for (int i = 0; word_array_array[i] != NULL; i++) {
        m_word_array_destroy(&word_array_array[i]);
    }
    free(word_array_array);
    *word_array_array_ptr = NULL;
}
