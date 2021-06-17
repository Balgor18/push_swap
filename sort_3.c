/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:31:05 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/17 11:10:35 by fcatinau         ###   ########.fr       */
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

char	min_or_max(int minpos, int maxpos)
{
	int	tmpmin;
	int	tmpmax;

	tmpmin = minpos - 50;
	tmpmax = maxpos - 50;

	// VERIF POSSIBILTY CLOSE OF 0 OR 99

	// CASE MINPOS = 50
	// CASE MAXPOS = 49

	// TMPMIN = 0
	// TMPMAX = -1

	if (tmpmax < tmpmin)
		return ('I');
	else if (tmpmax > tmpmin)
		return ('A');
	tmpmin = minpos + 50;
	tmpmax = maxpos + 50;
	if (tmpmin > tmpmax)
		return ('I');
	else if (tmpmax > tmpmin)
		return ('A');
	return ('R');
}

void	find_min_max(t_swap *s, t_chunk *c)
{
	int	i;
	int	mid;

	mid = s->count.len_a / 2;
	i = 0;
	if (min_or_max(c->minpos, c->maxpos) == 'I')
	{
		if (c->minpos < c->maxpos)
		{
			while (c->minpos != 99 && c->minpos != 0)
			{
				if (c->minpos > 50)
				{
					ft_rra(s);
					c->minpos++;
				}
				else if (c->minpos < 50)
				{
					ft_ra(s);
					c->minpos--;
				}
			}
			if (c->minpos == 99)
				ft_rra(s);
		}
		else if (c->minpos > c->maxpos)
		{
			while (c->maxpos != 99 && c->maxpos != 0)
			{
				if (c->maxpos > 50)
				{
					ft_rra(s);
					c->maxpos++;
				}
				else if (c->maxpos < 50)
				{
					ft_ra(s);
					c->maxpos--;
				}
			}
			if (c->maxpos == 99)
				ft_rra(s);
		}
		ft_pb(s);
	}
	else if (min_or_max(c->minpos, c->maxpos) == 'A')
	{
		while (c->maxpos != 99 && c->maxpos != 0)
		{
			if (c->maxpos > 50)
			{
				ft_rra(s);
				c->maxpos++;
			}
			else if (c->maxpos < 50)
			{
				ft_ra(s);
				c->maxpos--;
			}
		}
		if (c->maxpos == 99)
			ft_rra(s);
		ft_pb(s);
	}
	//ft_print(s->a,'A', s->count.len_a);
	//ft_print(s->b,'B', s->count.len_b);
}

void	find_new_min_or_max(t_swap *s, t_chunk *c)
{
	int	tmp;
	int	i;
	int	tmp_value;

	i = -1;
	tmp = s->b[0];
	tmp_value = s->a[0];
	if (tmp == c->min_value)
	{
		while (++i < s->count.len_a)
		{
			if (s->a[i] < tmp_value)
			{
				c->min_value = s->a[i];
				c->minpos = s->a[i];
			}
		}
	}
	else if (tmp == c->max_value)
	{
		c->max_value = max_value_chunk(s->a, s->count.len_a, (c->max_size - c->nb) - 1);
		i = -1;
		while (++i < s->count.len_a)
			if (c->max_value == s->a[i])
				c->maxpos = i;
		printf("");
	}
	//printf("max_value %d && maxpos %d \n", c->max_value, c->maxpos);
}

void	sort_list(t_swap *s, int size)
{
	t_chunk chunk;
	int i;

	i = -1;
	chunk.max_size = size;
	init_chunk(&chunk, s);
	while (chunk.nb < chunk.max_size)
	{
		find_min_max(s, &chunk);
		chunk.nb++;
		find_new_min_or_max(s, &chunk);
		printf("c->max-value %d | c->maxpos %d\n", chunk.max_value, chunk.maxpos);
		printf("c->min_value %d | c->minpos %d\n", chunk.min_value, chunk.minpos);
		ft_print(s->a,'A', s->count.len_a);
		ft_print(s->b,'B', s->count.len_b);
		if (chunk.nb == 6)
			break ;
	}
	//max_or_min(&chunk);
	//printf("minpos %d \n", chunk.minpos);
	//printf("maxpos %d \n", chunk.maxpos);
}

void	sort_100(t_swap *s)
{
	//int mid;
	int size;

	size = 0;
	//mid = s->count.len_a / 2;
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

/*
char	min_or_max(int minpos, int maxpos)
{
	int	tmpmin;
	int	tmpmax;

	tmpmin = minpos - 50;
	tmpmax = maxpos - 50;

	// VERIF POSSIBILTY CLOSE OF 0 OR 99

	// CASE MINPOS = 50
	// CASE MAXPOS = 49

	// TMPMIN = 0
	// TMPMAX = -1

	if (tmpmax < tmpmin)
		return ('A');
	else if (tmpmax > tmpmin)
		return ('I');
	tmpmin = minpos + 50;
	tmpmax = maxpos + 50;
	if (tmpmin > tmpmax)
		return ('I');
	else if (tmpmax > tmpmin)
		return ('A');
	return ('R');
}
void	find_min_max(t_swap *s)
{
	int	i;
	int	minpos;
	int	maxpos;
	int	mid;

	mid = s->count.len_a / 2;
	i = 0;
	minpos = 0;
	maxpos = 0;
	while (i < s->count.len_a)
	{
		if (s->a[minpos] > s->a[i])
			minpos = i;
		else if (s->a[maxpos] < s->a[i])
			maxpos = i;
		i++;
	}
	if (min_or_max(minpos, maxpos) == 'I')
	{
		while (minpos != 99 && minpos != 0)
		{
			if (minpos > 50)
			{
				ft_rra(s);
				minpos++;
			}
			else if (minpos < 50)
			{
				ft_ra(s);
				minpos--;
			}
		}
		if (minpos == 99)
			ft_rra(s);
		ft_pb(s);
	}
	else if (min_or_max(minpos, maxpos) == 'A')
	{
		while (maxpos != 99 && maxpos != 0)
		{
			if (maxpos > 50)
			{
				ft_rra(s);
				maxpos++;
			}
			else if (maxpos < 50)
			{
				ft_ra(s);
				maxpos--;
			}
		}
		if (maxpos == 99)
			ft_rra(s);
		ft_pb(s);
	}
	ft_print(s->a,'A', s->count.len_a);
	ft_print(s->b,'B', s->count.len_b);
}*/
