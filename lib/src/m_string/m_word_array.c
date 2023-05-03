/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_word_array_create
*/

#include <stdlib.h>
#include "m_string.h"

static size_t count_tokens(char const *str, char const *delim)
{
    size_t argc = 1;

    if (str == NULL || *str == '\0')
        return 0;
    while ((str = m_strpbrk(str, delim)) != NULL) {
        argc++;
        while (m_strchr(delim, *str) != NULL)
            str++;
    }
    return argc;
}

char **m_word_array_create(char const *str, char const *delim)
{
    char **new = NULL;
    char *buf = NULL;
    size_t argc = 0;

    if (str == NULL)
        return NULL;
    str += m_strspn(str, delim);
    if (*str == '\0')
        return NULL;
    if ((buf = m_strdup(str)) == NULL)
        return NULL;
    argc = count_tokens(str, delim);
    if ((new = malloc(sizeof(*new) * (argc + 1))) == NULL)
        return NULL;
    new[0] = m_strdup(m_strtok(buf, delim));
    for (size_t i = 1; new[i - 1] != NULL; i++)
        new[i] = m_strdup(m_strtok(NULL, delim));
    free(buf);
    return new;
}

size_t m_word_array_len(char *const *word_array)
{
    size_t length = 0;

    if (word_array == NULL)
        return 0;
    while (*word_array != NULL) {
        length++;
        word_array++;
    }
    return length;
}

void m_word_array_destroy(char ***word_array)
{
    char **to_free = *word_array;

    if (to_free == NULL)
        return;
    for (int i = 0; to_free[i] != NULL; i++) {
        free(to_free[i]);
    }
    free(to_free);
    *word_array = NULL;
}
