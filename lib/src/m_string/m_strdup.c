/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_strdup
*/

#include <stdlib.h>
#include "m_string.h"

char *m_strdup(char const *src)
{
    char *ret = NULL;
    size_t len = 0;

    if (src == NULL)
        return NULL;
    len = m_strlen(src);
    if ((ret = malloc(sizeof(char) * (len + 1))) == NULL)
        return NULL;
    for (size_t i = 0; i < len; i++) {
        ret[i] = src[i];
    }
    ret[len] = '\0';
    return ret;
}
