LIB=s21_decimal
NAME=lib$(LIB).a
HEADERS_DIR = .
HEADERS_FILES=$(LIB).h

HEADERS = $(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))
SRCS	= \
			compare.c \
			print.c \
			new.c \
			mantissa.c \
			exponent.c \
			add.c \
			support_func.c \
			sub.c \
			conversion.c \
			other_functions.c 
OBJ=$(SRCS:.c=.o)
INCLUDES=-I./

TEST_INCLUDES_DIR=.
TEST_INCLUDES=$(TEST_INCLUDES_DIR)/tests.h

TEST_DIR=tests
TEST_NAME=test.bin
TEST_SRCS_FILES= \
			test_main.c \
			test_add.c \
			test_conversion.c \
			test_align_exp.c
TEST_SRCS = $(addprefix $(TEST_DIR)/, $(TEST_SRCS_FILES))
TEST_OBJS=$(TEST_SRCS:%.c=%.o)

REPORT_NAME=report.html

TEST_LIBS = ""
OS = $(shell uname)
ifeq ($(OS), Darwin)
	TEST_LIBS=-lcheck
else
	TEST_LIBS=-lcheck -lm -lpthread -lrt -lsubunit 
endif

CC=gcc -Wall -Wextra -Werror -std=c11
CC_GCOV=gcc -Wall -Wextra -Werror -std=c11 \
			-fcf-protection=full -static-libgcc --coverage -lgcov
THREADS = 8

all: CC=$(CC_GCOV)
all:
	$(MAKE) -j$(THREADS) $(NAME)

gcov_report: CC=$(CC_GCOV)
gcov_report: fclean test
	./$(TEST_NAME)
	gcovr -r . -f src --html -o $(REPORT_NAME)

test: $(TEST_NAME)
	@exec ./$(TEST_NAME)

style_check:
	clang-format -style=google -i *.c
	clang-format -style=google -i ./$(TEST_DIR)/*.c
	clang-format -style=google -i *.h
	clang-format -style=google -i ./$(TEST_DIR)/*.h

$(TEST_NAME): $(NAME) $(TEST_OBJS)
	$(CC) $(FLAGS) $(TEST_OBJS) $(OBJ) -o $@ $(TEST_LIBS)

$(TEST_DIR)/%.o:$(TEST_DIR)/%.c $(TEST_INCLUDES)
	$(CC) $(FLAGS) -I./$(TEST_DIR)/includes -I./includes -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ) 
	@echo =================================
	@echo $(NAME) HAS BEEN MADE          
	@echo =================================	

%.o:%.c $(HEADERS)
	@$(CC) $(INCLUDES) -c $< -o $@
	@echo $<
		
clean:
	/bin/rm -rf *.o $(TEST_DIR)/*.o
fclean: clean
	/bin/rm -f $(NAME) $(TEST_NAME)
re: fclean all

.PHONY: lib clean fclean all re multi