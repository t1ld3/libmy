/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** test_m_strcpy
*/

#include <criterion/criterion.h>
#include "m_string.h"

Test(m_strcpy, basic_test) {
    char const *result = "Hello World!";
    char test[23] = {0};

    m_strcpy(test, result);
    cr_assert_str_eq(test, result);
}
