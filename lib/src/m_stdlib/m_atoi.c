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
    char *digit = NULL;
    int base_l = 0;
    int ret = 0;
    int sign = 1;

    if (str == NULL || base == NULL)
        return INT_MIN;
    base_l = m_strlen(base);
    while (*str == ' ')
        str++;
    if (*str == '-' && sign > 0) {
        sign *= -1;
        str++;
    }
    while ((digit = m_strchr(base, *str)) != NULL && *digit != '\0' && str++) {
        if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && digit - base > 7))
            return m_int_signedmax(sign);
        ret = (ret * base_l) + (digit - base);
    }
    return ret * sign;
}

int m_atoi(char const *str)
{
    return m_atoi_base(str, "0123456789");
}
