.PHONY: all string_plus.a

CC=gcc
FLAGS=-std=c11 -g -Wall -Werror -Wextra
STRING_PLUS_C=src_c_files/strpls_*.c
STRING_PLUS_H=src_h_files/strpls_*.h
STRING_PLUS_O=strpls_*.o
TESTS=tests/tests
NAME=test

all: string_plus.a

string_plus.a:
	$(CC) $(STRING_PLUS_C) -c $(FLAGS)
	ar rc string_plus.a $(STRING_PLUS_O)
	ranlib string_plus.a

strpls_covered:
	$(CC) $(STRING_PLUS_C) -c -lcheck $(FLAGS) --coverage
	ar rc string_plus.a $(STRING_PLUS_O)
	ranlib string_plus.a

style:
	clang-format -style=google -i *.c *h

test: clean strpls_covered
	$(CC) $(TESTS)*.c -c -lcheck $(FLAGS) --coverage
	$(CC) $(TESTS)*.o string_plus.a -o $(NAME) -lcheck --coverage $(FLAGS) -lsubunit -lm -lgcov

mem: test
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME)

macmem: test
	leaks --atExit -- ./string_plus -T ../common/t1

clean:
	rm -rf $(NAME) *.a *.o *.gcda *.gcno *.gcov *.info *.html report

rebuild: clean all

gcov_report: test
	./$(NAME)
	lcov -t "string_plus" -o string_plus.info -c -d .
	genhtml -o report string_plus.info
