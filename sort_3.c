/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:31:05 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/16 19:27:15 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_first(t_swap *s)
{
	if (s->a[1] > s->a[4])
	{
		ft_sa(s);
		ft_ra(s);
	}
	if (s->a[0] < s->a[4] && s->a[0] > s->a[3])
	{
		ft_rra(s);
		ft_sa(s);
		ft_ra(s);
		ft_ra(s);
	}
}

void	sort_b_for_a(t_swap *s)
{
	if (s->b[0] > s->a[0] && s->b[0] < s->a[s->count.len_a - 1])
	{
		ft_pa(s);
		ft_rra(s);
		ft_sa(s);
		ft_ra(s);
		ft_ra(s);
	}
	if (s->b[0] > s->a[0])
	{
		ft_pa(s);
		ft_sa(s);
	}
}

void	sort_3(t_swap *s)
{
	if (s->a[0] > s->a[1] && s->a[1] > s->a[2])
	{
		ft_sa(s);
		ft_rra(s);
	}
	else if (s->a[0] < s->a[1] && s->a[1] > s->a[2] && s->a[0] < s->a[2])
	{
		ft_sa(s);
		ft_ra(s);
	}
	else if (s->a[0] > s->a[2] && s->a[0] > s->a[1] && s->a[1] < s->a[2])
		ft_ra(s);
	else if (s->a[0] < s->a[1] && s->a[2] < s->a[1] && s->a[2] < s->a[0])
		ft_rra(s);
	else if (s->a[0] > s->a[1] && s->a[0] < s->a[2])
		ft_sa(s);
}

void	sort_49(t_swap *s)
{
	while (s->count.len_a > 3)
		find_min(s);
	sort_3(s);
	//ft_print(s->a, 'A',s->count.len_a);
	//ft_print(s->b, 'B',s->count.len_b);
	//sort_b_for_a(s);
	//if (s->b[0] < s->b[1] && verif_table_ok(s->a, s->count.len_a))
	//	ft_sb(s);
	while (s->count.len_b > 0)
		ft_pa(s);
	//two_first(s);
}

/*
** faire une struct pour le min max
** s_chunk
** int	nb;
** int	min_value;
** int	max_value;
** int	nb_int;
** int	taille max;
** //s_chunk *next;
** t_chunk
*/


void	sort_list(t_swap *s, int size)
{
	t_chunk chunk;
	int i;

	i = -1;
	chunk.max_size = size;
	init_chunk(&chunk, s);
}

void	sort_100(t_swap *s)
{
	int mid;
	int size;

	size = 0;
	mid = s->count.len_a / 2;
	//while (mid != s->count.len_a)
	//	ft_pb(s);
	//while ()
		size += 20;
		sort_list(s, size);
	//sort_list(s->a, s->count.len_a);

	//while (s->count.len_b > 0)
	//	ft_pa(s);

	//ft_print(s->a,'A', s->count.len_a);
	//ft_print(s->b,'B', s->count.len_b);
}
