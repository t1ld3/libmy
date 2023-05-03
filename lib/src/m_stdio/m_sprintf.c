/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_sprintf
*/

#include <stdlib.h>
#include "m_stdio.h"
#include "m_stdlib.h"
#include "m_string.h"

char *m_sprintf_get_data(char const *ptr, va_list ap)
{
    char *ret = NULL;

    switch (*ptr) {
        case 's': ret = m_strdup(va_arg(ap, char *)); break;
        case 'c':
            if ((ret = malloc(sizeof(*ret) * 2)) == NULL)
                return NULL;
            ret[0] = va_arg(ap, int);
            ret[1] = '\0';
            break;
        case 'i':
        case 'd': ret = m_itoa(va_arg(ap, int)); break;
    }
    return ret;
}

int m_vsprintf(char *restrict dest, char const *restrict format, va_list ap)
{
    int n = 0;
    char *data = NULL;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            dest[n] = format[i];
            n++;
        } else {
            i++;
            data = m_sprintf_get_data(&format[i], ap);
            m_strcpy(&dest[n], data);
            n += m_strlen(data);
            free(data);
        }
    }
    return n;
}

int m_sprintf(char *restrict dest, char const *restrict format, ...)
{
    int n = 0;
    va_list ap;

    va_start(ap, format);
    n = m_vsprintf(dest, format, ap);
    va_end(ap);
    return n;
}
