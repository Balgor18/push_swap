NAME = push_swap

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC =

OBJ = $(SRC:.c=.o)

$(NAME): libft $(OBJ)
			@$(CC) $(CFLAGS) -o $@ $(OBJ) -Llibft -lft
			./push_swap

libft :
		make -C libft/

%.o: %.c
				$(CC) $(CFLAGS) -I. -Imlx -o $@ -c $?

all: $(NAME)

norme :
		norminette -R CheckForbiddenSourceHeader $(SRC)
		norminette -R CheckDefine cub3D.h

clean:
				$(RM) $(OBJ)
				@make -C libft/ clean

fclean: clean
				$(RM) $(NAME)
				@make -C libft/ fclean

re: fclean all

.PHONY: clean all fclean re libft
