/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:31:05 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/18 11:41:29 by fcatinau         ###   ########.fr       */
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
	while (s->count.len_b > 0)
		ft_pa(s);
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

char	min_or_max(int minpos, int maxpos, int len)
{
	int	min_0;
	int	max_0;
	int	min_len;
	int	max_len;
	int	i;

	i = -1;
	min_0 = minpos;
	max_0 = maxpos;
	min_len = minpos - len;
	max_len = maxpos - len;
	if (min_len < 0)
		min_len *= -1;
	if (max_len < 0)
		max_len *= -1;
	if (min_0 < max_0 && min_0 < max_len && min_0 < min_len)
		return ('A');
	if (max_0 < min_0 && max_0 < min_len && max_0 < max_len)
		return ('B');
	if (min_len < max_len && min_len < max_0 && min_len < min_0)
		return ('C');
	if (max_len < min_len && max_len < min_0 && max_len < max_0)
		return ('D');
	return (0);
}

void	find_min_max(t_swap *s, t_chunk *c)
{
	int	i;
	int	res;

	res = min_or_max(c->minpos, c->maxpos, s->count.len_a);
	i = 0;
	if (res == 'A')
	{
		while (c->minpos != 0)
		{
			ft_ra(s);
			c->minpos--;
		}
		ft_pb(s);
	}
	else if (res == 'B')
	{
		while (c->maxpos != 0)
		{
			ft_ra(s);
			c->maxpos--;
		}
		ft_pb(s);
	}
	else if (res == 'C')
	{
		while (c->maxpos != s->count.len_a - 1)
		{
			ft_rra(s);
			c->maxpos++;
		}
		ft_rra(s);
		ft_pb(s);
	}
	else if (res == 'D')
	{
		while (c->maxpos != s->count.len_a - 1)
		{
			ft_rra(s);
			c->maxpos++;
		}
		ft_rra(s);
		ft_pb(s);
	}
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
	}
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
		printf("avant \n------------\nmin_value %d\nminpos %d\n------------\nmax_value %d\nmaxpos %d \n------------\n------------\n\n", chunk.min_value, chunk.minpos, chunk.max_value, chunk.maxpos);
		chunk.nb++;
		find_new_min_or_max(s, &chunk);
		printf("apres \n------------\nmin_value %d\nminpos %d\n------------\nmax_value %d\nmaxpos %d \n------------\n------------\n\n", chunk.min_value, chunk.minpos, chunk.max_value, chunk.maxpos);
		//printf("nb turn %d \n", chunk.nb);
		//printf("c->max-value %d | c->maxpos %d\n", chunk.max_value, chunk.maxpos);
		//printf("c->min_value %d | c->minpos %d\n", chunk.min_value, chunk.minpos);
		ft_print(s->a,'A', s->count.len_a);
		ft_print(s->b,'B', s->count.len_b);
		printf("je boucle %d < %d\n",chunk.nb, chunk.max_size);
		if (chunk.nb == 50)
			break ;
	}
	while (s->count.len_b > 0)
	{
		ft_pa(s);
		ft_ra(s);
	}
	//ft_print(s->a,'A', s->count.len_a);
	//ft_print(s->b,'B', s->count.len_b);
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
	while (!verif_table_ok(s->a, s->count.len_a + s->count.len_b))
	{
		size += 20;
		sort_list(s, size);
		//ft_print(s->a,'A', s->count.len_a);
		//ft_print(s->b,'B', s->count.len_b);
		if (size > 59)
			break;
	}
	//ft_print(s->a,'A', s->count.len_a);
	//ft_print(s->b,'B', s->count.len_b);
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
