NAME = push_swap
CC = cc
CFLAGS = -Werror -Wall -Wextra
SRC = push_swap.c
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:
	$(RM) $(NAME)
fclean: clean

re: fclean all
