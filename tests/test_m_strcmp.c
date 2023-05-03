/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** test_m_strcmp
*/

#include <criterion/criterion.h>
#include "m_string.h"

Test(m_strcmp, null_string) {
    int n = -1;

    n = m_strcmp("", "");
    cr_assert_eq(n, 0);
}

Test(m_strcmp, diff_string_same_length) {
    int n = -1;

    n = m_strcmp("AAABBBCCD", "AAABBBCCC");
    cr_assert_eq(n, 'D' - 'C');
}

Test(m_strcmp, diff_string_diff_length) {
    int n = -1;

    n = m_strcmp("AA", "A");
    cr_assert_eq(n, 'A');
}
