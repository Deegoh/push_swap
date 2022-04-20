NAME = push_swap
CHECKER = checker_Mac
# CHECKER = checkermake_linux
CC = cc
CFLAGS = -Werror -Wall -Wextra #-g -fsanitize=address
SRC = push_swap.c\
	  rules_single.c\
	  rules_double.c\
	  parse_arg.c\
	  simple_sort.c\
	  rules_utils.c\
	  quick_sort.c\
	  sort_stack.c\
	  print_utils.c\
	  nodes_utils.c
RM = rm -f
LIBFT_DIR = ./libft/
INCLUDE = -I$(LIBFT_DIR)
LIB = -lft -L$(LIBFT_DIR)
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
OBJ = $(SRC:.c=.o)
ARG1= 90 68 14 34 99

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
checker: all
	./$(NAME) $(ARG)
	./$(NAME) $(ARG) | ./$(CHECKER) $(ARG)