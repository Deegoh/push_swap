NAME = push_swap
ifeq (uname,Linux)
	CHECKER = checker_linux
else
	CHECKER = checker_Mac
endif
CC = cc
CFLAGS = -Werror -Wall -Wextra -g #make-fsanitize=address
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
ARG1= 1 0 2 -1 3 
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
lldb: all
	lldb $(NAME) $(ARG)
