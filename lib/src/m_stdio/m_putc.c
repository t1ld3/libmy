/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** putc
*/

#include <unistd.h>
#include "m_stdio.h"

int m_dputc(int fd, char c)
{
    return write(fd, &c, 1);
}

int m_putc(char c)
{
    return m_dputc(1, c);
}
