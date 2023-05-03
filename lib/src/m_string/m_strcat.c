/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_strcat
*/

#include "m_string.h"

char *m_strcat(char *dest, char const *src)
{
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return dest;
}
