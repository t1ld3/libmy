/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_atoi
*/
#include <limits.h>
#include "m_string.h"

static int m_int_signedmax(int sign)
{
    if (sign > 0) {
        return INT_MAX;
    }
    return INT_MIN;
}

int m_atoi_base(char const *str, char const *base)
{
    int base_l = m_strlen(base);
    int ret = 0;
    int sign = 1;

    while (*str == ' ') {
        str++;
    }
    if (*str == '-' && sign > 0) {
        sign *= -1;
        str++;
    }
    while (m_strchr(base, *str) != NULL) {
        if (ret > INT_MAX / 10
            || (ret == INT_MAX / 10 && *str - base[0] > 7)) {
            return m_int_signedmax(sign);
        }
        ret = (ret * base_l) + *str - base[0];
        str++;
    }
    return ret * sign;
}

int m_atoi(char const *str)
{
    return m_atoi_base(str, "0123456789");
}
