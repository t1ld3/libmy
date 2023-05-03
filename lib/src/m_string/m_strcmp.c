/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_strcmp
*/

#include "m_string.h"

int m_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
