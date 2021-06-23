/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:46:36 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/23 16:17:01 by fcatinau         ###   ########.fr       */
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
	int	max_size;
}				t_chunk;

typedef struct s_swap
{
	char	type;
	int		*a;
	int		*b;
	t_count	count;
}				t_swap;

// a degager
# include <stdio.h>

# define SIZE_100 20


// test
void	sort_100(t_swap *s);
void	find_min_max(t_swap *s, t_chunk *c);
void	find_max(t_swap *s);
void	init_chunk(t_chunk *c, t_swap *s, int size);
void	find_min_max_in_chunck(t_swap *s);
int		max_value_chunk(int *t, int len, int pos);
int		min_value_chunk(int *t, int len, int pos);
int		*copy_list(int *t, int len);
char	min_or_max(int minpos, int maxpos, int len);

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
