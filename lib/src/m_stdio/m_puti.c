/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_puti
*/

#include "m_stdio.h"
#include "m_string.h"

int m_dputi_base(int fd, int nb, char const *base)
{
    int base_l = m_strlen(base);

    if (nb < 0) {
        m_dputc(fd, '-');
        nb *= (-1);
    }
    if (nb >= base_l) {
        m_dputi_base(fd, nb / base_l, base);
    }
    m_dputc(fd, base[nb % base_l]);
    return 0;
}

int m_puti_base(int nb, char const *base)
{
    return m_dputi_base(1, nb, base);
}

int m_dputi(int fd, int nb)
{
    return m_dputi_base(fd, nb, "0123456789");
}

int m_puti(int nb)
{
    return m_dputi(1, nb);
}
