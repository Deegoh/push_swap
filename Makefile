NAME = push_swap
CHECKER = checker_Mac
CHECKER = checker_linux
CC = cc
CFLAGS = -Werror -Wall -Wextra -g
SRC = push_swap.c\
	  rules_single.c\
	  rules_double.c\
	  parse_arg.c
RM = rm -f
LIBFT_DIR = ./libft/
INCLUDE = -I$(LIBFT_DIR)
LIB = -lft -L$(LIBFT_DIR)
ARG=`ruby -e "puts (1..10).to_a.shuffle.join(' ')"`
OBJ = $(SRC:.c=.o)
ARG1= 90 68 14 34 99 72 15 11 66 37 46 31 55 3 28 100 8 61 24 19

.PHONY: all clean fclean re libft

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) all -sC $(LIBFT_DIR)
	$(CC) $(OBJ) $(LIB) $(INCLUDE) $(CFLAGS) -o $(NAME)
clean:
	$(RM) $(NAME)
	$(RM) $(OBJ)
	@$(MAKE) clean -sC $(LIBFT_DIR)
fclean: clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
re: fclean all

v1: all
	./pyviz.py $(ARG)
v2: all
	./push_swap_visualizer2.py $(ARG)
checker: all
	./$(NAME) $(ARG1)
	./$(NAME) $(ARG1) | ./$(CHECKER) $(ARG1)