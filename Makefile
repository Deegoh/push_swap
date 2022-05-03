NAME = push_swap
ifeq ($(shell uname),Darwin)
	CHECKER = checker_Mac
else
	CHECKER = checker_linux
endif
CC = cc
CFLAGS = -Werror -Wall -Wextra -g -fsanitize=address
SRC = push_swap.c\
	  print_utils.c\
	  init_utils.c\
	  parse_arg.c\
	  dll_utils.c\
	  nodes_utils.c\
	  rules_node.c\
	  op_utils.c\
	  simple_sort.c\
	  algo.c

RM = rm -f
LIBFT_DIR = ./libft/
INCLUDE = -I$(LIBFT_DIR)
LIB = -lft -L$(LIBFT_DIR)
ARG =`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re libft v1 v2 test run wc checker lldb

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
	./push_swap_visualizer2.py --min 0 --max 500 --size 500

test: all
	cp $(NAME) ../push_swap_tester/.
	bash ../push_swap_tester/tester.sh

run: all
	./$(NAME) $(ARG)

wc: all
	./$(NAME) $(ARG) | wc -l >> wc.txt

checker: all
	./$(NAME) $(ARG) | ./$(CHECKER) $(ARG)

lldb: all
	lldb $(NAME) $(ARG)
