NAME = push_swap
CHECKER = checker_Mac
CC = cc
CFLAGS = -Werror -Wall -Wextra -g
SRC = push_swap.c\
	  rules_single.c\
	  rules_double.c\
	  parse_arg.c
RM = rm -f
LIBFT_DIR = ./libft/
INCLUDE = -I$(LIBFT_DIR)
LIB = -lft -L $(LIBFT_DIR)
ARG=`ruby -e "puts (-10..10).to_a.shuffle.join(' ')"`

.PHONY: all clean fclean re libft

all: $(NAME)

$(NAME): libft
	$(CC) $(INCLUDE) $(LIB) $(CFLAGS) $(SRC) -o $(NAME)
libft:
	@$(MAKE) -sC $(LIBFT_DIR)
clean:
	$(RM) $(NAME)
	@$(MAKE) clean -sC $(LIBFT_DIR)
fclean: clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
re: fclean all

visu: re
	./pyviz.py $(ARG)
checker: re
	./$(NAME) $(ARG) | ./$(CHECKER) $(ARG)