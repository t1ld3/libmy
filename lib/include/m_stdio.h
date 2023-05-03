/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** header
*/

#ifndef M_STDIO_H
    #define M_STDIO_H
    #include <stdarg.h>
// print format
int m_vdprintf(int fd, char const *format, va_list ap);
int m_dprintf(int fd, const char *restrict format, ...);
int m_printf(const char *restrict format, ...);
int m_sprintf(char *restrict dest, char const *restrict format, ...);
int m_vsprintf(char *restrict dest, char const *restrict format, va_list ap);
int m_vasprintf(char **restrict strp, const char *restrict format, va_list ap);
int m_asprintf(char **restrict strp, const char *restrict format, ...);
// print char *
int m_puts(char const *str);
int m_putc(char c);
int m_dputc(int fd, char c);
int m_dputs(int fd, char const *str);
// print int
int m_dputi_base(int fd, int nb, char const *base);
int m_puti_base(int nb, char const *base);
int m_dputi(int fd, int nb);
int m_puti(int nb);
// print unsigned long
int m_dputu_base(int fd, unsigned int nb, const char *base);
int m_putu_base(unsigned int nb, const char *base);
int m_dputu(int fd, unsigned int nb);
int m_putu(unsigned int nb);
#endif /* ifndef M_STDIO_H */
