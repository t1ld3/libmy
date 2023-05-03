##
## EPITECH PROJECT, 2023
## libmy
## File description:
## Makefile
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Wpedantic -Werror -Ilib/include

LIBSRC	=	lib/src/m_list/remove.c		\
		lib/src/m_list/insert.c		\
		lib/src/m_list/get.c		\
		lib/src/m_list/print.c		\
		lib/src/m_list/filter.c		\
		lib/src/m_list/list.c		\
		lib/src/m_list/moves.c		\
		lib/src/m_list/set.c		\
		lib/src/m_list/checks.c		\
		lib/src/m_list/copy.c		\
		lib/src/m_list/convert.c	\
		lib/src/m_string/m_strcat.c	\
		lib/src/m_string/m_strcmp.c	\
		lib/src/m_string/m_strdup.c	\
		lib/src/m_string/m_strlen.c	\
		lib/src/m_string/m_strchr.c	\
		lib/src/m_string/m_strstr.c	\
		lib/src/m_string/m_strcpy.c	\
		lib/src/m_string/m_strncmp.c	\
		lib/src/m_string/m_strcspn.c	\
		lib/src/m_string/m_strspn.c	\
		lib/src/m_string/m_strpbrk.c	\
		lib/src/m_string/m_strtok.c	\
		lib/src/m_string/m_word_array.c	\
		lib/src/m_stdlib/m_itoa.c	\
		lib/src/m_stdlib/m_atoi.c	\
		lib/src/m_stdio/m_putc.c	\
		lib/src/m_stdio/m_puts.c	\
		lib/src/m_stdio/m_putu.c	\
		lib/src/m_stdio/m_puti.c	\
		lib/src/m_stdio/m_dprintf.c	\
		lib/src/m_stdio/m_asprintf.c	\
		lib/src/m_stdio/m_sprintf.c

LIBOBJ	=	$(LIBSRC:.c=.o)

LIBNAME	=	lib/libmy.a

TESTSRC	=	tests/test_list.c	\
		tests/test_m_stdlib.c	\
		tests/test_m_strlen.c	\
		tests/test_m_strcmp.c	\
		tests/test_m_strncmp.c	\
		tests/test_m_strcpy.c	\
		tests/test_m_strdup.c	\
		tests/test_m_strchr.c	\
		tests/test_m_strstr.c	\
		tests/test_m_asprintf.c	\

TESTOBJ	=	$(TESTSRC:.c=.o)

TESTNAME	=	tests_run

$(LIBNAME):	$(LIBOBJ)
	$(AR) cr -o $(LIBNAME) $(LIBOBJ)

debug:	CFLAGS	+=	-g3
debug:	re

tests_run:	CFLAGS	+=	--coverage
tests_run:	LDFLAGS	+=	--coverage -Llib -lmy -lcriterion
tests_run:	fclean $(LIBNAME) $(TESTOBJ)
	$(CC) -o $(TESTNAME) $(TESTOBJ) $(LDFLAGS)
	./$(TESTNAME)
	gcovr --exclude lib/tests --exclude tests
	gcovr --exclude lib/tests --exclude tests --branches

all:	$(LIBNAME)

clean:
	rm -f $(LIBOBJ)
	rm -f $(TESTOBJ)
	rm -f $(LIBOBJ:.o=.gcno)
	rm -f $(TESTOBJ:.o=.gcno)
	rm -f $(LIBOBJ:.o=.gcda)
	rm -f $(TESTOBJ:.o=.gcda)

fclean:	clean
	rm -f $(LIBNAME)
	rm -f $(TESTNAME)

re:	fclean all

.PHONY:	re fclean clean all
