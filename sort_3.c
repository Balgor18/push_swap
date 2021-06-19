/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:31:05 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/19 17:21:10 by fcatinau         ###   ########.fr       */
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
	if (minpos == maxpos)
	{
		if (min_len < min_0)
			return ('C');
		return ('A');
	}
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

	pos_max = size- c->nb;
	printf("find_new_min_or_max pos = %d = %d - %d\n", pos_max, size, c->nb);
	i = -1;
	tmp = s->b[0];
	tmp_value = s->a[0];
	res = (c->max_size - 20) + pos_max - 1;
	if ((c->max_size - 20) > res)
		res += 1;
	printf("avant res = %d \n", res);
	if (res == -1)
		res = 1;
	if (res == -2)
		res = 0;
	printf("after res = %d \n", res);
	//res = (c->max_size - c->nb) - 1;// + 1; // MARCHE PAS VOIR POURQUOI
	//printf("%d = (%d - %d) - 1\n", res, c->nb, c->max_size);
	//printf("c->nb %d | c->max_size %d \n", c->nb, c->max_size);
	/*if (res == 0)
		res = 1;
	else if (res < 0)
		res = 0;*/
	/*if (res < 0 && c->nb < c->max_size)
	{
		//res *= -1;
		res = (c->max_size - c->nb);// + 1;
		//res = (c->max_size - s->count.len_b) - 1;
		//
		//printf("%d = (%d - %d) - 1\n", res, c->max_size, s->count.len_b);
		printf("%d = (%d - %d)\n", res, c->max_size, c->nb);
		//printf("res = %d \n",res);
	}*/
	c->min_value = min_value_chunk(s->a, s->count.len_a, size - 20);
	while (++i < s->count.len_a)
		if (c->min_value == s->a[i])
			c->minpos = i;
	i = -1;
	//printf("%d - %d \n", c->nb, c->max_size);
	//printf("res = %d \n", res);
	c->max_value = max_value_chunk(s->a, s->count.len_a, res);
	//printf("max_value %d\n", c->max_value);
	while (++i < s->count.len_a)
		if (c->max_value == s->a[i])
			c->maxpos = i;
}

void	sort_3_b(t_swap *s)
{
	if (s->b[0] > s->b[1] && s->b[1] < s->b[2])
	{
		ft_sb(s);
		ft_rrb(s);
	}
	else if (s->b[0] > s->b[1] && s->b[1] < s->b[2] && s->b[0] > s->b[2])
	{
		ft_sb(s);
		ft_rb(s);
	}
	else if (s->b[0] < s->b[2] && s->b[0] < s->b[1] && s->b[1] > s->b[2])
		ft_rb(s);
	else if (s->b[0] > s->b[1] && s->b[2] > s->b[1] && s->b[2] > s->b[0])
		ft_rrb(s);
	else if (s->b[0] < s->b[1] && s->b[0] > s->b[2])
		ft_sb(s);
}

int	get_max_value_sort(t_chunk *c, t_swap *s)
{
	int	*tmp;
	int	val;

	tmp = copy_list(s->a, s->count.len_a);
	ft_sort_int_tab(tmp, s->count.len_a);

	ft_print(tmp, 'T', s->count.len_a);
	printf("max_size %d \n",c->max_size - 20 - 1);
	val = tmp[c->max_size - 20 - 1];
	free(tmp);
	return (val);
}

void	sort_list(t_chunk *chunk, t_swap *s, int size)
{
	int	i;
	int	val;

	i = -1;
	chunk->max_size = size;
	init_chunk(chunk, s, size);
	while (chunk->nb <= chunk->max_size)
	{
		find_min_max(s, chunk);
		chunk->nb++;
		find_new_min_or_max(s, chunk, size);
	}
	//ft_print(s->a,'A', s->count.len_a);
	//ft_print(s->b,'B', s->count.len_b);
	//printf("FINIS VOILA LES VALEUR DANS B\n");
	//ft_print(s->b,'B', s->count.len_b);
	//printf("-----------------------------\n");
	if (chunk->max_size != 20 && chunk->max_size != 100)
	{
		val = get_max_value_sort(chunk, s);
		while (s->a[s->count.len_a - 1] != val)
			ft_rra(s);
	}
	while (s->count.len_b > 3)
		find_max(s);
	sort_3_b(s);
	while (s->count.len_b > 0)
		ft_pa(s);
	ft_print(s->a,'A', s->count.len_a);
	ft_print(s->b,'B', s->count.len_b);
}

void	sort_100(t_swap *s)
{
	t_chunk chunk;
	int size;

	chunk.nb = 0;
	size = 0;
	while (!verif_table_ok(s->a, s->count.len_a + s->count.len_b))
	{
		size += 20;
		sort_list(&chunk, s, size);
		printf("chunk.nb = %d \n", chunk.nb);
		//ft_print(s->a,'A', s->count.len_a);
		//ft_print(s->b,'B', s->count.len_b);
		//if (size > 89)
		//	break;
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
