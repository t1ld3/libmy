/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** test_m_strdup
*/

#include <criterion/criterion.h>
#include "m_string.h"

Test(m_strdup, basic_test)
{
    char const *result = "Hello World!";
    char *test = NULL;

    test = m_strdup(result);
    cr_assert_not_null(test);
    cr_assert_str_eq(test, result);
    free(test);
}

Test(m_strdup, empty_string)
{
    char *test = NULL;

    test = m_strdup("");
    cr_assert_not_null(test);
    free(test);
}
