NAME=s21_decimal.a
HEADERS_DIR = .
HEADERS_NAMES =	s21_decimal.h

HEADERS = $(addprefix $(HEADERS_DIR)/, $(HEADERS_NAMES))
SRCS	= \
			compare.c
OBJ=$(SRCS:.c=.o)
INCLUDES=-I./

CC=gcc -Wall -Wextra -Werror
THREADS = 8


all:
	$(MAKE) -j$(THREADS) $(NAME)

multi:
	$(MAKE) -j$(THREADS) all

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ) 
	@echo =================================
	@echo $(NAME) HAS BEEN MADE          
	@echo =================================	

%.o:%.c $(HEADERS)
	@$(CC) $(INCLUDES) -c $< -o $@
	@echo $<

test:
	@echo "test"

gcov_report:
	@echo "gcov_report"

		
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all

.PHONY: lib clean fclean all re multi