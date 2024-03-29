/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:09:30 by fcatinau          #+#    #+#             */
/*   Updated: 2021/07/14 16:37:52 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_max(t_swap *s, t_chunk *c)
{
	int	max;
	int	i;

	i = -1;
	while (++i < s->count.len_a)
	{
		if (s->a[i] <= c->max_value)
		{
			c->minpos = i;
			break ;
		}
	}
	i = s->count.len_a;
	while (--i > 0)
	{
		if (s->a[i] <= c->max_value)
		{
			c->maxpos = i;
			break ;
		}
	}
	max = s->count.len_a - c->maxpos;
	while_pb(s, c, max);
}

void	find_new_min_or_max(t_swap *s, t_chunk *c, int size)
{
	int	res;
	int	pos_max;

	pos_max = size - c->nb;
	res = pos_max - 1;
	c->max_value = max_value_chunk(s, s->a, s->count.len_a, res);
}

void	sort_list(t_chunk *chunk, t_swap *s, int size)
{
	chunk->max_size = size;
	find_new_min_or_max(s, chunk, size);
	while (chunk->nb < chunk->max_size && s->count.len_a != 0)
	{
		find_min_max(s, chunk);
		chunk->nb++;
	}
	if (chunk->nb >= s->count.len_a + s->count.len_b)
	{
		while (s->count.len_b > 0)
			find_max(s);
	}
}

void	sort_100(t_swap *s)
{
	t_chunk	chunk;
	int		size;

	chunk.nb = 0;
	size = 0;
	while (!verif_table_ok(s->a, s->count.len_a + s->count.len_b))
	{
		size += SIZE_100;
		sort_list(&chunk, s, size);
	}
}
