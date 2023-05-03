/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** test_m_strchr
*/

#include <criterion/criterion.h>
#include "m_string.h"

Test(m_strchr, basic_test) {
    char const *sample = "Hello World!";
    char const *result = &sample[4];
    char c = 'o';
    char *test = NULL;

    test = m_strchr(sample, c);
    cr_assert_eq(test, result);
}

Test(m_strchr, null_tests) {
    cr_assert_null(m_strchr(NULL, 'c'));
    cr_assert_null(m_strchr("Hello World!", '\0'));
}
