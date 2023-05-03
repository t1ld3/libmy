/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_strcpy
*/

#include "m_string.h"

char *m_strcpy(char *dest, char const *src)
{
    size_t i = 0;

    if (dest == NULL || src == NULL)
        return dest;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (dest[i] != '\0') {
        dest[i] = '\0';
        i++;
    }
    return dest;
}
