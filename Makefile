# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Source and object files
SRC = push_swap.c ft_split.c  ft_atoi.c ft_strlcpy.c ft_push.c ft_lstadd_back.c hardsort.c ft_swap.c ft_rotate.c ft_putendl_fd.c ft_lstlast.c listutils.c errman.c ft_rrotate.c sortingalgs.c ft_extra.c argprocess.c checks.c
OBJ = $(SRC:.c=.o)
# Executable name
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "\033[31m	------------------***༺ (\033[31m\033[32mPush_Swap Compiled!\033[31m)༻***------------------\n\033[0m"
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	@echo "\033[31m	------------------***༺ (\033[31m\033[32mPushSwap cleaned!\033[31m)༻***------------------\n\033[0m"

re: fclean all



.PHONY: all clean fclean re
