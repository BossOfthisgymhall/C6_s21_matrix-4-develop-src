GCC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
GCOV_FLAGS=-fprofile-arcs -ftest-coverage 
ALL_FILES=$(wildcard s21_functions/*.c)
TEST_FILE =$(wildcard tests/s21_test.c)
OBJ= $(patsubst /s21_functions/%.c,%.o,$(wildcard /s21_functions/*.c))
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm

OS = $(shell uname -s)
ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

all: clean s21_matrix.a test


s21_matrix.a:
	$(GCC) $(FLAGS) -c s21_functions/*.c
	ar rcs s21_matrix.a *.o
	ranlib s21_matrix.a
	rm -rf *.o

test: s21_matrix.a
	checkmk clean_mode=1 tests/s21_unit_test.check > tests/s21_test.c
ifeq ($(OS), Darwin)
	$(GCC) $(FLAGS)  tests/s21_test_matrix.c s21_matrix.a  -o unit_test -lcheck -lm
else
	$(GCC) $(FLAGS)  tests/s21_test.c s21_matrix.a -o unit_test -lcheck $(LINUX_FLAGS)
endif
	./unit_test

gcov_report:
ifeq ($(OS), Darwin)
	$(GCC) $(FLAGS) $(GCOV_FLAGS) s21_functions/*.c $(TEST_FILE) -o gcov_test -lcheck -lm
else
	$(GCC) $(FLAGS) $(GCOV_FLAGS) s21_functions/*.c $(TEST_FILE) -o gcov_test -lcheck $(LINUX_FLAGS)
endif
	./gcov_test

	lcov -t "stest" -o s21_test.info --no-external --filter range -c -d .
	genhtml -o report s21_test.info 
	$(OPEN_CMD) ./report/index.html
	rm -rf *.gcno
	rm -rf *.gcda

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gcda
