#color
GREEN = \e[32m
RED = \e[31m
WHITE = \e[39m
YELLOW = \e[33m
HIDDEN = \e[8m
RESET = \e[0m
#push_swap
NAME = push_swap
ifeq ($(shell uname),Darwin)
	CHECKER = checker_Mac
else
	CHECKER = checker_linux
endif
CC = gcc
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
	  algo.c\
	  quick_sort.c

RM = rm -f
LIBFT_DIR = ./libft/
INCLUDE = -I$(LIBFT_DIR)
LIB = -lft -L$(LIBFT_DIR)
ARG =`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
# ARG =`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re libft v1 v2 test run wc checker lldb

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) all -sC $(LIBFT_DIR)
	@$(CC) $(OBJ) $(LIB) $(INCLUDE) $(CFLAGS) -o $(NAME)
	@printf "\r$(GREEN)🚀 Creating $(NAME)$(RESET)\n"
	@sleep 0.5
	@printf "\r$(HIDDEN)🚀 Creating $(NAME)$(RESET)\r"

clean:
	@$(RM) $(NAME)
	@$(RM) $(OBJ)
	@printf "\r$(YELLOW)♻️  Clean $(NAME)$(RESET)\n"
	@sleep 0.5
	@printf "\r$(HIDDEN)♻️  Clean $(NAME)$(RESET)\r"
	@$(MAKE) clean -sC $(LIBFT_DIR)

fclean: clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@printf "\r$(RED)🗑️  Remove $(NAME)$(RESET)\n"
	@sleep 0.5
	@printf "\r$(HIDDEN)🗑️  Remove $(NAME)$(RESET)\r"

re: fclean all

v1: all
	./pyviz.py $(ARG)

v2: all
	./push_swap_visualizer2.py --min 1 --max 10000 --size 500

test: all
	cp $(NAME) ../push_swap_tester/.
	bash ../push_swap_tester/tester.sh

run: all
	./$(NAME) $(ARG)

wc: all
	./$(NAME) $(ARG) | wc -l

checker: all
	./$(NAME) $(ARG) | ./$(CHECKER) $(ARG)

lldb: all
	lldb $(NAME) $(ARG)
