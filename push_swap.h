/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:46:36 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/25 11:50:42 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_copylist
{
	int			start;
	int			stop;
	int			*dest;
	int			*src;
	int			len;
}				t_copylist;

typedef struct	s_count
{
	int		len_a;
	int		len_b;
}				t_count;

typedef struct	s_swap
{
	int		*a;
	int		*b;
	int		len;
	t_count	count;
}				t_swap;

// a degager
void	ft_print(int *s, char c, int len);

# include <stdio.h>

/*
** Init
*/
void	init_struct(t_swap *s);
void	init_struct_for_copy(int *src, t_copylist *c, int *dest, int len);


/*
** Verif
*/
void	verif_two_first(t_swap *s);
int		verif_digit(char *s, int len, t_swap *swap);
int		verif_table_ok(t_swap *s, int len);
void	verif_swap_list(t_swap *s);
void	verif_top_and_bot(t_swap *s);

/*
** Len
*/
void	ft_len_table(t_swap *s);
void	ft_len(int *list, int *a);

/*
** Solver
*/
int		solver(t_swap *swap);

/*
** Rotate
*/
void	ft_ra(t_swap *s);
void	ft_rb(t_swap *s);
void	ft_rr(t_swap *s);

/*
** Swap
*/
void	ft_sa(t_swap *s);
void	ft_sb(t_swap *s);
void	ft_ss(t_swap *s);

/*
** Push list
*/
void	pa(t_swap *s, int len);
void	pb(t_swap *s, int len);

void	copy_list(t_copylist *c, char ch);

#endif
// pa = prends le 1er elem de b pour allez le mettre sur a SAUF SI B < 1
// pb = prends le 1er elem de a pour allez le mettre sur b SAUF SI A < 1

// --------------------------------------------------

// ft_ra = decale d'une postion vers le haut de tous les elements de la liste a + first passe last
// ft_rb = decale d'une postion vers le haut de tous les elements de la liste b + first passe last
// ft_rr = ft_ra + ft_rb;

// --------------------------------------------------

// rra = decale d'une position vers le bas tout les elements de la liste a, le dernier devient le premier;
// rrb = decale d'une position vers le bas tout les elements de la liste b, le dernier devient le premier;
// rrr = rra + rrb;
