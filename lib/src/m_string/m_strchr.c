/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_strchr
*/

#include "m_string.h"

char *m_strchr(char const *haystack, char needle)
{
    if (haystack == NULL || needle == '\0')
        return NULL;
    while (*haystack != '\0') {
        if (*haystack == needle)
            return (char *) haystack;
        haystack++;
    }
    return NULL;
}
