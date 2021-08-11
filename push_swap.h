/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:46:36 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/11 18:51:57 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_count
{
	int	len_a;
	int	len_b;
}				t_count;

typedef struct s_chunk
{
	int	nb;
	int	max_value;
	int	max_size;
	int	minpos;
	int	maxpos;
}				t_chunk;

typedef struct s_swap
{
	int		*a;
	int		*b;
	t_count	count;
}				t_swap;

/*
** Defines
** ------------------------------------------------
** Define chunk size
*/
# define SIZE_100 20
# define SIZE_500 50

/*
** Define limits INT
*/
# define INT_MIN -2147483648
# define INT_MAX 2147483647

/*
** Functions
** -------------------------------------------------
** Init
*/
void	init_struct(t_swap *s);
void	init_chunk(t_chunk *c, t_swap *s, int size);

/*
** Includes
*/
void	ft_sort_int_tab(int *tab, int size);
int		*copy_list(int *t, int len);

/*
** Print
*/
void	ft_print(int *s, char c, int len);

/*
** Error
*/
int		ft_error(void);

/*
** Parser
*/
void	parser_bis(int h, int *i, char **s, t_swap *swap);
/*
** Verif
*/
int		verif_table_ok(int *s, int len);
int		verif_digit(char *s, int len, t_swap *swap);
int		verif_size_int(char *s);
int		verif_nb_num(char *s);
/*
** While_pb
*/
void	while_pb(t_swap *s, t_chunk *c, int max);

/*
** Sort
*/
void	sort_3(t_swap *s);
void	sort_49(t_swap *s);
void	sort_100(t_swap *s);
void	sort_500(t_swap *s);
void	sort_list(t_chunk *chunk, t_swap *s, int size);

/*
** Find
*/
void	find_min(t_swap *s);
void	find_max(t_swap *s);
void	find_min_max(t_swap *s, t_chunk *c);
void	find_new_min_or_max(t_swap *s, t_chunk *c, int size);

/*
** Min Max
*/
int		max_value_chunk(t_swap *s, int *t, int len, int pos);

/*
** Solver
*/
void	solver(t_swap *swap);

/*
** Color
*/
void	yellow(void);
void	blue(void);
void	cyan(void);
void	red(void);
void	white(void);
void	green(void);

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
