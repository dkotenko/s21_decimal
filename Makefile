LIB=s21_decimal
NAME=$(LIB).a
HEADERS_DIR = .
HEADERS_FILES=$(LIB).h

HEADERS 	= $(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))
SRCS_DIR 	= src
SRCS	= $(shell find $(SRCS_DIR) -maxdepth 2 -name "s21_*.c")

OBJ=$(SRCS:.c=.o)
INCLUDES=-I./

TEST_INCLUDES_DIR=test
TEST_INCLUDES=$(TEST_INCLUDES_DIR)/s21_test.h

TEST_DIR=test
TEST_NAME=testing
TEST_SRCS_FILES= $(notdir $(shell find $(TEST_DIR) -maxdepth 2 -name "test_*.c"))
TEST_SRCS = $(addprefix $(TEST_DIR)/, $(TEST_SRCS_FILES))
TEST_OBJS=$(TEST_SRCS:%.c=%.o)

GCOV_FILES = $(shell find . -maxdepth 3 -name "*.gc*")

REPORT_NAME=report.html
REPORT_FOLDER=report

OS = $(shell uname)
ifeq ($(OS), Darwin)
	TEST_LIBS=-lcheck
else
	TEST_LIBS=-lcheck -lm -lsubunit -lpthread -lrt 
endif

# -fprofile-arcs -ftest-coverage
CC_LIB = gcc -Wall -Wextra -Werror -Wuninitialized -std=c11
CC_LIB_CVR=gcc -Wall -Wextra -Werror -Wuninitialized -std=c11 --coverage -lgcov
CC_TEST = gcc -Wall -Wextra -Werror -Wuninitialized -std=c11
COV_LIBS = --coverage -lgcov
THREADS = 8

all:
	$(MAKE) -j$(THREADS) $(NAME)

$(TEST_NAME): $(NAME) $(TEST_OBJS)
	$(CC_TEST) $(TEST_OBJS) $(OBJ) -o $@ $(TEST_LIBS) $(COV_LIBS)

$(TEST_DIR)/%.o:$(TEST_DIR)/%.c $(TEST_INCLUDES)
	$(CC_TEST) -I./$(TEST_DIR) -I./ -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo =================================
	@echo $(NAME) HAS BEEN MADE          
	@echo =================================	

%.o:%.c $(HEADERS)
	@$(CC_LIB) $(INCLUDES) -c $< -o $@
	@echo $<

test: CC_LIB = $(CC_LIB_CVR)
test: clean $(TEST_NAME)
	./$(TEST_NAME)
	$(info    TEST_OBJ: $(CC))


gcov_report: test
	@mv $(GCOV_FILES) -t $(REPORT_FOLDER)
	@lcov -c -d $(REPORT_FOLDER) -o gcov_test.info
	@genhtml gcov_test.info -o $(REPORT_FOLDER)

clang_fix:
	@cp ../materials/linters/.clang-format .
	@clang-format --style=Google -i */*.c */*.h *.h
	@rm .clang-format

clang_check:
	@cp ../materials/linters/.clang-format .
	@clang-format --style=Google -n */*.c */*.h *.h
	@rm .clang-format

clean:
	@rm -rf \
		$(NAME) \
		$(TEST_NAME) \
		rm -rf report/*/ \
		$(shell find . -maxdepth 3 -name "*.o") \
		$(shell find . -maxdepth 3 -name "*.gc*") \
		$(shell find . -maxdepth 3 -name "*.html") \
		$(shell find . -maxdepth 3 -name "*.png") \
		$(shell find . -maxdepth 3 -name "*.css") \
		$(shell find . -maxdepth 3 -name "*.info")
