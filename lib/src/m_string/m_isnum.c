/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_isnum
*/

#include <stdbool.h>
#include "m_string.h"

bool m_isnum(char const *str)
{
    while (*str) {
        if (*str > '9' || *str < '0')
            return false;
        str++;
    }
    return true;
}
