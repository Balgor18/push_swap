# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/09 15:35:09 by fcatinau          #+#    #+#              #
#    Updated: 2021/06/01 15:11:39 by fcatinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC = ft_split.c ft_strjoin.c ft_bzero.c ft_memmove.c ft_memset.c ft_memcpy.c \
ft_memccpy.c ft_memchr.c ft_atoi.c ft_calloc.c ft_isprint.c ft_isdigit.c \
ft_isascii.c ft_isalnum.c ft_isalpha.c ft_memcmp.c ft_strcmp.c ft_strchr.c ft_strlen.c \
ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
ft_toupper.c ft_tolower.c ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_strmapi.c ft_strtrim.c ft_substr.c

SRC_BONUS = bonus/ft_lstnew.c bonus/ft_lstadd_front.c bonus/ft_lstlast.c bonus/ft_lstsize.c\
bonus/ft_lstdelone.c bonus/ft_lstclear.c bonus/ft_lstiter.c bonus/ft_lstmap.c bonus/ft_lstadd_back.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
		$(CC) -I. -o $@ -c $? $(CFLAGS)

all: $(NAME)

norme :
		norminette -R CheckForbiddenSourceHeader $(SRC)
		norminette -R CheckDefine libft.h

clean:
		$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

bonus : $(OBJ_BONUS) $(OBJ)
		ar rc $(NAME) $(OBJ) $(OBJ_BONUS)
		ranlib $(NAME)

.PHONY: clean
