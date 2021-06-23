/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:09:30 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/23 16:17:19 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	while_min_max(char c, int *pos, t_swap *s)
{
	if (c == 'A' || c == 'B')
	{
		while (*pos != 0)
		{
			ft_ra(s);
			*pos -= 1;
		}
		ft_pb(s);
	}
	else if (c == 'C' || c == 'D')
	{
		while (*pos != s->count.len_a - 1)
		{
			ft_rra(s);
			*pos += 1;
		}
		ft_rra(s);
		ft_pb(s);
	}
}

void	find_min_max(t_swap *s, t_chunk *c)
{
	int	i;
	int	res;

	res = min_or_max(c->minpos, c->maxpos, s->count.len_a);
	i = 0;
	if (res == 'A'|| res == 'C')
		while_min_max(res, &c->minpos, s);
	else if (res == 'B'|| res == 'D')
		while_min_max(res, &c->maxpos, s);
}

void	find_new_min_or_max(t_swap *s, t_chunk *c, int size)
{
	int	tmp;
	int	i;
	int	tmp_value;
	int	res;
	int	pos_max;

	pos_max = size - c->nb;
	i = -1;
	tmp = s->b[0];
	tmp_value = s->a[0];
	res = pos_max - 1;
	c->min_value = min_value_chunk(s->a, s->count.len_a, 0);
	while (++i < s->count.len_a)
		if (c->min_value == s->a[i])
			c->minpos = i;
	i = -1;
	c->max_value = max_value_chunk(s->a, s->count.len_a, res);
	while (++i < s->count.len_a)
		if (c->max_value == s->a[i])
			c->maxpos = i;
}

void	sort_list(t_chunk *chunk, t_swap *s, int size)
{
	int	i;

	i = -1;
	chunk->max_size = size;
	while (chunk->nb < chunk->max_size && chunk->nb < (s->count.len_a + s->count.len_b))
	{
		find_new_min_or_max(s, chunk, size);
		find_min_max(s, chunk);
		chunk->nb++;
	}
	if (chunk->nb == s->count.len_a + s->count.len_b)
	{
		while (s->count.len_b > 0)
			find_max(s);
			ft_pa(s);
	}
}

void	sort_100(t_swap *s){
	t_chunk	chunk;
	int		size;

	chunk.nb = 0;
	size = 0;
	while (!verif_table_ok(s->a, s->count.len_a + s->count.len_b))// && size < s->count.len_a)
	{
		size += SIZE_100;
		sort_list(&chunk, s, size);
	}
	//ft_print(s->a, 'A', s->count.len_a);
	//ft_print(s->b, 'B', s->count.len_b);
}
