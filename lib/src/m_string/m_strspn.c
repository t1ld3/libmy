/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_strspn
*/

#include "m_string.h"

size_t m_strspn(char const *str, char const *accept)
{
    size_t i = 0;

    while (str[i] != '\0' && m_strchr(accept, str[i]) != NULL) {
        i++;
    }
    return i;
}
