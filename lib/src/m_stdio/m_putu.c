/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_putu
*/

#include "m_stdio.h"
#include "m_string.h"

int m_dputu_base(int fd, unsigned int nb, const char *base)
{
    unsigned long base_l = m_strlen(base);

    if (nb >= base_l) {
        m_dputu_base(fd, nb / base_l, base);
    }
    m_dputc(fd, base[nb % base_l]);
    return 0;
}

int m_putu_base(unsigned int nb, const char *base)
{
    return m_dputu_base(1, nb, base);
}

int m_dputu(int fd, unsigned int nb)
{
    return m_dputu_base(fd, nb, "0123456789");
}

int m_putu(unsigned int nb)
{
    return m_dputu(1, nb);
}
