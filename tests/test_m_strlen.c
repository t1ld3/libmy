/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** test_m_string.h
*/

#include <criterion/criterion.h>
#include "m_string.h"

Test(m_strlen, str_null) {
    size_t n = -1;

    n = m_strlen(NULL);
    cr_assert_eq(n, 0);
}
