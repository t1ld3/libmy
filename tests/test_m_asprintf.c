/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** test_m_asprintf
*/

#include <criterion/criterion.h>
#include "m_stdio.h"
#include "m_string.h"

Test(m_asprintf, basic_test)
{
    char const *result = "Hello World!42\n";
    char *test = NULL;
    int result_len = m_strlen(result);
    int n = -1;

    n = m_asprintf(&test, "%s%d\n", "Hello World!", 42);
    m_dprintf(2, "%d %d\n", n, result_len);
    cr_assert_eq(n, result_len);
    cr_assert_str_eq(result, test);
    free(test);
}
