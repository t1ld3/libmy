/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_strtok
*/

#include "m_string.h"

char *m_strtok(char *restrict str, char const *restrict delim)
{
    static char *ptr;
    char *start = NULL;

    if (str != NULL)
        ptr = str;
    if (ptr == NULL)
        return NULL;
    ptr += m_strspn(ptr, delim);
    if (*ptr == '\0') {
        ptr = NULL;
        return ptr;
    } else {
        start = ptr;
        ptr += m_strcspn(ptr, delim);
        if (*ptr == '\0') {
            ptr = NULL;
        } else
            *ptr++ = '\0';
    }
    return start;
}
