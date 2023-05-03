/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_puts
*/

#include <unistd.h>
#include "m_stdio.h"
#include "m_string.h"

int m_dputs(int fd, char const *str)
{
    size_t length = 0;

    length = m_strlen(str);
    return write(fd, str, length);
}

int m_puts(char const *str)
{
    return m_dputs(1, str);
}
