/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** test_m_strstr
*/

#include <criterion/criterion.h>
#include "m_stdio.h"
#include "m_string.h"

Test(m_strstr, null_return) {
    char const *haystack = "Hello World!";
    char const *needle = "W olle";
    char *test = NULL;

    test = m_strstr(haystack, needle);
    cr_assert_null(test);
}

Test(m_strstr, not_null_return) {
    char const *haystack = "Hello World!";
    char const *needle = "World";
    char const *result = &haystack[6];
    char *test = NULL;

    test = m_strstr(haystack, needle);
    cr_assert_eq(test, result);
}

Test(m_strstr, needle_empty) {
    char const *haystack = "Hello World!";
    char const *needle = "\0";
    char *test = NULL;

    test = m_strstr(haystack, needle);
    cr_assert_eq(test, haystack);
}
