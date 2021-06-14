NAME = push_swap

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC =	ft_print.c find_min.c \
		ft_pa.c\
		ft_pb.c\
		ft_rr.c\
		ft_rrr.c\
		ft_ss.c\
		init_struct.c\
		push_swap.c\
		solver.c\
		sort_3.c\
		verif.c\
		verif2.c

OBJ = $(SRC:.c=.o)

$(NAME): libft $(OBJ)
			@$(CC) $(CFLAGS) -o $@ $(OBJ) -Llibft -lft
# -fsanitize=address

#			COMMANDE ARG=`ruby -e "puts (1..49).to_a.shuffle.join(' ')"`; ./push_swap $ARG

#			test 49
#			./push_swap 36 10 21 26 19 18 1 24 48 46 41 23 17 30 9 13 3 38 4 39 6 7 28 20 14 35 42 25 44 29 2 15 5 22 32 12 16 34 31 43 33 27 49 37 11 45 8 40 47

#			test 50
#			./push_swap 13 46 28 34 48 35 22 23 32 41 14 39 24 33 47 25 15 44 37 16 21 11 26 6 27 36 7 1 19 2 29 3 20 40 10 43 8 49 38 50 31 30 17 5 18 9 12 42 4 45

#			test 100
			./push_swap 36 19 59 84 26 53 18 31 55 63 43 25 73 6 74 92 98 77 30 7 76 28 13 96 40 5 37 100 38 16 29 70 80 79 52 12 4 64 41 51 42 85 27 86 49 75 17 1 47 35 9 54 44 88 15 72 83 67 71 93 21 94 81 11 58 8 3 33 57 14 32 95 24 99 22 78 90 68 69 46 91 56 50 97 61 39 45 34 87 82 89 10 65 2 48 23 20 62 60 66
# | wc -l

#			./push_swap 1 4 2 3 5 | wc -l
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
