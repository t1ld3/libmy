/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** dprintf
*/
#include <unistd.h>
#include "m_stdio.h"
#include "m_string.h"

static int print_data(int fd, char const *ptr, va_list ap)
{
    int n = 0;

    switch (*(ptr + 1)) {
        case 'd': n += m_dputi(fd, va_arg(ap, int)); break;
        case 's': n += m_dputs(fd, va_arg(ap, char *)); break;
        case 'c': n += m_dputc(fd, va_arg(ap, int)); break;
        case 'u': n += m_dputu(fd, va_arg(ap, int)); break;
        default:
            n += m_dprintf(2, "\nflag '%c' not found.\n", *(ptr + 1));
            break;
    }
    return n;
}

int m_vdprintf(int fd, char const *format, va_list ap)
{
    int n = 0;
    int len = 0;
    int i = 0;
    char const *ptr = format;

    while ((ptr = m_strchr(ptr, '%')) != NULL) {
        len = ptr - &format[i];
        n += write(fd, &format[i], len);
        n += print_data(fd, ptr, ap);
        i += len + 2;
        ptr++;
    }
    n += m_dputs(fd, &format[i]);
    return n;
}

int m_dprintf(int fd, const char *restrict format, ...)
{
    va_list list;
    int n = 0;

    va_start(list, format);
    n = m_vdprintf(fd, format, list);
    va_end(list);
    return n;
}

int m_printf(const char *restrict format, ...)
{
    int n = 0;
    va_list list;

    va_start(list, format);
    n = m_vdprintf(1, format, list);
    va_end(list);
    return n;
}
