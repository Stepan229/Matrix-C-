CC := g++
FLAGS = -Wall -Wextra -Werror -std=c++17
D_OS = -D __My_Linux__
LIB_DIR = ./Modules/*.cpp
LIB = matrix_oop.a
RM = rm -rf

TEST_DIR = ./tests/*.cpp

LIBS_FOR_CHECK_PCKG = -lgtest -lgmock -pthread
GCOV_FLAG = -fprofile-arcs -ftest-coverage


all: test


check: clean
	$(CC) $(D_OS) $(FLAGS) $(LIB_DIR) -o matr
	./matr

clang_check:
	cp ../materials/linters/.clang-format .
	clang-format -n Modules/*.cpp
	clang-format -n tests/*.cpp
	clang-format -n tests/*.h
	clang-format -n *.h
	$(RM) .clang-format

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i Modules/*.cpp
	clang-format -i tests/*.cpp
	clang-format -i tests/*.h
	clang-format -i  *.h 
	$(RM) .clang-format

test: clean matrix_oop.a
	$(CC) $(FLAGS) $(TEST_DIR) $(LIB) $(LIBS_FOR_CHECK_PCKG) -o test
	./test

valgrind: clean matrix_oop.a
	$(CC) $(FLAGS) $(TEST_DIR) $(LIB) $(LIBS_FOR_CHECK_PCKG) -o test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s  ./test 
	
gcov-report:
	$(CC) $(FLAGS) -o test.out $(TEST_DIR) $(LIB_DIR) $(LIBS_FOR_CHECK_PCKG) $(GCOV_FLAG)
	./test.out
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	$(RM) *.gcda *.gcno

matrix_oop.a:
	$(CC) $(D_OS) -c $(FLAGS) $(LIB_DIR)
	ar -rcs $(LIB) *.o
	ranlib $(LIB)
	$(RM) *.o

clean:
	$(RM) *.o *.a
	$(RM) matr test
	$(RM) report test.info test.out