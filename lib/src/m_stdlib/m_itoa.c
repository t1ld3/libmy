/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** my_nbr_to_str
*/

#include <stdlib.h>
#include "m_stdlib.h"
#include "m_string.h"

static int get_nb_len(int nb, size_t base)
{
    int n = 0;

    if (nb == 0)
        return 1;
    if (nb < 0) {
        nb *= -1;
        n++;
    }
    while (nb) {
        nb /= base;
        n++;
    }
    return n;
}

char *m_itoa_base(int nb, char const *base)
{
    size_t base_len = 0;
    char *new = NULL;
    size_t len = 0;

    base_len = m_strlen(base);
    len = get_nb_len(nb, base_len);
    if ((new = malloc(sizeof(*new) * (len + 1))) == NULL)
        return NULL;
    if (nb < 0) {
        new[0] = '-';
        nb *= -1;
    }
    new[len--] = '\0';
    if (!nb)
        new[0] = base[0];
    while (nb) {
        new[len--] = base[nb % base_len];
        nb /= base_len;
    }
    return new;
}

char *m_itoa(int nb)
{
    return m_itoa_base(nb, "0123456789");
}
