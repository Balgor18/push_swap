/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:46:36 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/20 16:44:22 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

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

/*
** Init
*/
void	init_struct(t_swap *s);


/*
** Verif
*/
int	verif_two_first(t_swap *s);
int	verif_digit(char *s, int len, t_swap *swap);
int	verif_table_ok(t_swap *s);

/*
** Len
*/
void	ft_len_table(t_swap *s);
void	ft_len(int *list, int *a);

/*
** Solver
*/
int	solver(t_swap *swap);

/*
** Rotate
*/
void	ra(t_swap *s);
void	rb(t_swap *s);
void	rr(t_swap *s);

/*
** Swap
*/
void	sa(t_swap *s);
void	sb(t_swap *s);
void	ss(t_swap *s);

// pa = prends le 1er elem de b pour allez le mettre sur a SAUF SI B < 1
// pb = prends le 1er elem de a pour allez le mettre sur b SAUF SI A < 1

// --------------------------------------------------

// ra = decale d'une postion vers le haut de tous les elements de la liste a + first passe last
// rb = decale d'une postion vers le haut de tous les elements de la liste b + first passe last
// rr = ra + rb;

// --------------------------------------------------

// rra = decale d'une position vers le bas tout les elements de la liste a, le dernier devient le premier;
// rrb = decale d'une position vers le bas tout les elements de la liste b, le dernier devient le premier;
// rrr = rra + rrb;

#endif
