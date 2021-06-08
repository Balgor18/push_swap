NAME = push_swap

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC =	ft_print.c ft_pa.c\
		ft_pb.c\
		ft_rr.c\
		ft_rrr.c\
		ft_ss.c\
		init_struct.c\
		operation.c\
		push_swap.c\
		solver.c\
		sort_3.c\
		verif.c\
		verif2.c

OBJ = $(SRC:.c=.o)

$(NAME): libft $(OBJ)
			@$(CC) $(CFLAGS) -o $@ $(OBJ) -Llibft -lft
# -fsanitize=address

#			./push_swap 2 1 3

#			./push_swap 3 2 1

#			./push_swap 3 1 2

#			./push_swap 1 3 2

#			./push_swap 2 3 1


			./push_swap 3 4 10
			./push_swap 4 3 10
			./push_swap 10 4 3
			./push_swap 10 3 4
			./push_swap 4 10 3
			./push_swap 3 10 4

#			./push_swap 8 5 1 3 4
#			./push_swap 5 8 1 3 4
#			./push_swap 5 8 1 4 3

#			./push_swap 4 3 10 11 9 2
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
