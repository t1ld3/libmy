/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** test_m_strncmp
*/

#include <criterion/criterion.h>
#include "m_stdio.h"
#include "m_string.h"

Test(m_strncmp, three_chars) {
    int n = -1;

    n = m_strncmp("AAC", "AACB", 3);
    cr_assert_eq(n, 0);
}

Test(m_strncmp, diff_string_same_length) {
    int n = -1;

    n = m_strncmp("AAABBBCCD", "AAABBBCCC", 12);
    cr_assert_eq(n, 'D' - 'C');
}

Test(m_strncmp, diff_string_diff_length) {
    int n = -1;

    n = m_strncmp("AA", "A", 1);
    cr_assert_eq(n, 0);
}
