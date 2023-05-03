/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_asprintf
*/

#include <stdlib.h>
#include "m_stdio.h"
#include "m_string.h"

char *m_sprintf_get_data(char const *ptr, va_list ap);

static size_t vasprintf_get_buffer_length(const char *format, va_list ap)
{
    size_t n = 0;
    size_t i = 0;
    size_t count = 0;
    char *data = NULL;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            count++;
            i++;
            data = m_sprintf_get_data(&format[i], ap);
            n += m_strlen(data);
            free(data);
        }
        i++;
    }
    n += i - (2 * count);
    return n;
}

int m_vasprintf(char **restrict strp, const char *restrict format, va_list ap)
{
    int n = 0;
    va_list tmp;

    va_copy(tmp, ap);
    n = vasprintf_get_buffer_length(format, tmp);
    va_end(tmp);
    if ((*strp = malloc(sizeof(**strp) * (n + 1))) == NULL)
        return -1;
    (*strp)[n] = '\0';
    n = m_vsprintf(*strp, format, ap);
    return n;
}

int m_asprintf(char **restrict strp, const char *restrict format, ...)
{
    int n = 0;
    va_list ap;

    va_start(ap, format);
    n = m_vasprintf(strp, format, ap);
    va_end(ap);
    return n;
}
