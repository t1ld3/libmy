/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** description
*/

#include <stddef.h>
#include "m_string.h"

char *m_strstr(char const *haystack, char const *needle)
{
    size_t length = m_strlen(needle);

    if (*needle == '\0') {
        return (char *) haystack;
    }
    while (*haystack != '\0') {
        if (!m_strncmp(haystack, needle, length)) {
            return (char *) haystack;
        }
        haystack++;
    }
    return NULL;
}
