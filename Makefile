NAME = push_swap

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC =	color.c\
		error.c\
		find_min.c \
		ft_pa.c\
		ft_pb.c\
		ft_print.c\
		ft_rr.c\
		ft_rrr.c\
		ft_ss.c\
		ft_strlen_int.c\
		init_struct.c\
		parser_bis.c\
		push_swap.c\
		solver.c\
		sort_3.c\
		sort_100.c\
		sort_500.c\
		sort_tab.c\
		verif.c\
		verif2.c\
		while_pb.c

OBJ = $(SRC:.c=.o)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -Lincludes/libft -lft
#	ARG=`ruby -e "puts (1..49).to_a.shuffle.join(' ')"`; ./push_swap $ARG

libft :
	make -C includes/libft/

%.o: %.c
	$(CC) $(CFLAGS) -I. -o $@ -c $?

all: $(NAME)

norme :
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckDefine push_swap.h

clean:
	$(RM) $(OBJ)
	@make -C includes/libft/ clean

fclean: clean
	$(RM) $(NAME)
	@make -C includes/libft/ fclean

re: fclean all

.PHONY: clean fclean re
