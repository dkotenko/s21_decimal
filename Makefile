NAME = main

SRCDIR = .
OBJDIR = .
INCDIR = .
TESTDIR = testing

INCLUDES = .
ALL_C = main.c
ALL_OBJ = $(ALL_C:%.c=%.o)
OBJS = $(addprefix $(OBJDIR)/, $(ALL_OBJ))

LIB_NAME = s21_decimal
LIB_DIR = ./src
LIB_INC_DIR = .
LIB = $(LIB_DIR)/$(LIB_NAME).a
COMP_LIB = make -C $(LIB_DIR)
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(LIB) $(OBJDIR) $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -L$(LIB_DIR) -ls21_decimal -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES) | $(OBJDIR)
	$(CC) $(FLAGS) -I./$(INCDIR) -I./$(LIB_DIR)/$(LIB_INC_DIR) -c $< -o $@

$(LIB): lib

test: all
	bash $(TESTDIR)/test_func.sh

lib:
	@$(COMP_LIB)

clean:
	@/bin/rm -rf *.o
	@$(COMP_LIB) clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@$(COMP_LIB) fclean

re: fclean all

.PHONY: lib clean fclean all re