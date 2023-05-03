/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_strpbrk
*/

#include "m_string.h"

static char *check_accept(char const *str, char const *accept)
{
    for (int i = 0; accept[i] != '\0'; i++)
        if (accept[i] == *str)
            return (char *) str;
    return NULL;
}

char *m_strpbrk(const char *str, const char *accept)
{
    char *ret = NULL;

    if (accept == NULL) {
        return NULL;
    }
    while (*str != '\0') {
        if ((ret = check_accept(str, accept)) != NULL) {
            return ret;
        }
        str++;
    }
    return NULL;
}
