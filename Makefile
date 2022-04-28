NAME = push_swap
ifeq ($(shell uname),Darwin)
	CHECKER = checker_Mac
else
	CHECKER = checker_linux
endif
CC = cc
CFLAGS = -Werror -Wall -Wextra -g #-fsanitize=address
SRC = push_swap.c\
	  parse_arg.c\
	  simple_sort.c\
	  rules_utils.c\
	  print_utils.c\
	  nodes_utils.c\
	  nodes_ultils2.c\
	  rules_node.c\
	  # \
	  rules_single.c\
	  rules_double.c
RM = rm -f
LIBFT_DIR = ./libft/
INCLUDE = -I$(LIBFT_DIR)
LIB = -lft -L$(LIBFT_DIR)
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
ARG1= -42 -22 22 -7 18 -49 -30 6 5 8 33 50 48 10 0 9 15 -16 -18 16 -33 11 23 37 -44 -37 40 -38 43 -8 4 -15 -21 -1 -40 -17 -13 29 26 32 -4 49 -45 -27 38 -20 -46 19 42 -32 -12 -2 -11 12 -3 31 44 -10 -41 -6 -19 3 28 7 17 -29 25 13 46 27 -26 -48 2 -35 -31 14 39 -14 -5 -25 20 30 -28 36 -9 -24 21 -39 -36 45 1 24 34 41 47 -23 -47 -34 35 -43 
OBJ = $(SRC:.c=.o)
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
	./pyviz.py $(ARG1)
v2: all
	./push_swap_visualizer2.py $(ARG)
test: all
	cp $(NAME) ../push_swap_tester/.
	bash ../push_swap_tester/tester.sh
run: all
	./$(NAME) $(ARG1)
checker: all
	./$(NAME) $(ARG) | ./$(CHECKER) $(ARG)
lldb: all
	lldb $(NAME) $(ARG)
