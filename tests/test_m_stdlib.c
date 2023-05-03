/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** test_m_stdlib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "m_stdlib.h"

Test(m_itoa, positive_number) {
    char const *result = "9466846";
    char *test = NULL;

    test = m_itoa(9466846);
    cr_assert_str_eq(test, result);
    free(test);
}

Test(m_itoa, negative_number) {
    char const *result = "-1";
    char *test = NULL;

    test = m_itoa(-1);
    cr_assert_str_eq(result, test);
    free(test);
}

Test(m_itoa, zero_number) {
    char const *result = "0";
    char *test = NULL;

    test = m_itoa(0);
    cr_assert_str_eq(result, test);
    free(test);
}
