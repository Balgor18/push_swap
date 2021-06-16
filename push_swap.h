/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:46:36 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/16 19:27:03 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct	s_count
{
	int		len_a;
	int		len_b;
}				t_count;

typedef struct	s_chunk
{
	int	nb;
	int	min_value;
	int	minpos;
	int	max_value;
	int	maxpos;
//	int	nb_int;
	int	max_size;
	//s_chunk *next;
}				t_chunk;

typedef struct s_swap
{
	char	type;
	int		*a;
	int		*b;
//	int		len;
	t_count	count;
}				t_swap;

// a degager
# include <stdio.h>



// test
void	sort_100(t_swap *s);
void	find_min_max(t_swap *s);
void	init_chunk(t_chunk *c, t_swap *s);
void	find_min_max_in_chunck(t_swap *s);

void	ft_sort_int_tab(int *tab, int size);
/*
** Init
*/
void	init_struct(t_swap *s);

/*
** print
*/
void	ft_print(int *s, char c, int len);

/*
** Verif
*/
int		verif_table_ok(int *s, int len);
int		verif_digit(char *s, int len, t_swap *swap);

/*
** Sort
*/
void	sort_3(t_swap *s);
void	sort_49(t_swap *s);

/*
** Find min
*/
void	find_min(t_swap *s);

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

void	ft_rra(t_swap *s);
void	ft_rrb(t_swap *s);
void	ft_rrr(t_swap *s);

/*
** Swap
*/
void	ft_sa(t_swap *s);
void	ft_sb(t_swap *s);
void	ft_ss(t_swap *s);

/*
** Push list
*/
void	ft_pb(t_swap *s);
void	ft_pa(t_swap *s);


#endif
