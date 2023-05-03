/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_strcpn
*/

#include "m_string.h"

size_t m_strcspn(char const *str, char const *reject)
{
    size_t i = 0;

    while (str[i] != '\0' && (m_strchr(reject, str[i]) == NULL)) {
        i++;
    }
    return i;
}
