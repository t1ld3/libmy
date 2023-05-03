/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_strncmp
*/

#include "m_string.h"

int m_strncmp(char const *s1, char const *s2, int n)
{
    while (*s1 && *s2 && (*s1 == *s2) && (--n) != 0) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
