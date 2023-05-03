/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_strlen
*/

#include "m_string.h"

size_t m_strlen(char const *str)
{
    size_t length = 0;

    if (str == NULL)
        return 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}
