NAME = push_swap

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC =	printa.c ft_rr.c\
		ft_rrr.c\
		ft_ss.c\
		init_struct.c\
		pa.c\
		pb.c\
		push_swap.c\
		solver.c\
		verif.c

OBJ = $(SRC:.c=.o)

$(NAME): libft $(OBJ)
			@$(CC) $(CFLAGS) -o $@ $(OBJ) -Llibft -lft
# -fsanitize=address
			./push_swap 4 3 10 11 9 2
#			valgrind ./push_swap 2 1 3 6 5 8
#			valgrind --leak-check=full --show-leak-kinds=all ./push_swap 2 1 3 6 5 8
#			./push_swap 2 one 3 6 5 8
#			./push_swap "4 67 3 87 23"
#			./push_swap "4 one 3 87 23"

libft :
		make -C libft/

%.o: %.c
				$(CC) $(CFLAGS) -I. -Imlx -o $@ -c $?

all: $(NAME)

norme :
#		@make -C libft/ norme
		norminette -R CheckForbiddenSourceHeader $(SRC)
		norminette -R CheckDefine push_swap.h

clean:
				$(RM) $(OBJ)
				@make -C libft/ clean

fclean: clean
				$(RM) $(NAME)
				@make -C libft/ fclean

re: fclean all

.PHONY: clean all fclean re libft
