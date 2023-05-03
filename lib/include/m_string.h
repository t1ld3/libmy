/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** m_strings_h
*/

#ifndef M_STRINGS_H
    #define M_STRINGS_H
    #define __need_NULL
    #define __need_size_t
    #include <stdbool.h>
    #include <stddef.h>
    #include <string.h>
// standards
size_t m_strlen(char const *str);
char *m_strchr(char const *haystack, char needle);
char *m_strpbrk(const char *str, const char *accept);
char *m_strdup(char const *src);
size_t m_strspn(char const *str, char const *accept);
size_t m_strcspn(char const *str, char const *reject);
char *m_strtok(char *restrict str, char const *restrict delim);
int m_strcmp(char const *s1, char const *s2);
int m_strncmp(char const *s1, char const *s2, int n);
char *m_strcat(char *dest, char const *src);
char *m_strcpy(char *dest, char const *src);
char *m_strstr(char const *haystack, char const *needle);
// checks
bool m_isnum(char const *str);
// word_array
char **m_word_array_create(char const *str, char const *delim);
size_t m_word_array_len(char *const *word_array);
void m_word_array_destroy(char ***word_array);
// word_array_array
char ***m_word_array_array_create(char *const *word_array, char const *delim);
size_t m_word_array_array_len(char **const *word_array_array);
void m_word_array_array_destroy(char ****word_array_array_ptr);
#endif /* ifndef M_STRINGS_H */
