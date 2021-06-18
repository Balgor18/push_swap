/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:19:39 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/18 19:04:40 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_struct(t_swap *s)
{
	s->a = 0;
	s->b = 0;
	s->type = '0';
	s->count.len_a = 0;
	s->count.len_b = 0;
}

int	max_value(int *t, int len)
{
	int	i;
	int	max;

	max = 0;
	i = -1;
	while (++i < len)
		if (max < t[i])
			max = t[i];
	return (max);
}

int	*copy_list(int *t, int len)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = malloc(sizeof(int *) * len);
	while (++i < len)
		tmp[i] = t[i];
	return (tmp);
}

int	max_value_chunk(int *t, int len, int pos)
{
	int	*tmp;
	int	val;

	tmp = copy_list(t, len);
	ft_sort_int_tab(tmp, len);

	printf("pos = %d \n", pos);
	ft_print(tmp, 'T', len);
	val = tmp[pos];
	free(tmp);
	return (val);
}

int	min_value_chunk(int *t, int len, int pos)
{
	int	*tmp;
	int	val;

	tmp = copy_list(t, len);
	ft_sort_int_tab(tmp, len);

	//printf("pos = %d \n", pos);
	//ft_print(tmp, 'T', len);
	val = tmp[pos];
	free(tmp);
	return (val);
}

void	init_chunk(t_chunk *c, t_swap *s, int size)
{
	int	i;
	int	nb_max;

	nb_max = 1;
	i = -1;
	if (!c->nb)
		c->nb = 0;
	//c->min_value = s->a[0];
	/*while (++i < s->count.len_a)
	{
		if (c->min_value > s->a[i])
		{
			c->min_value = s->a[i];
			c->minpos = i;
		}
	}*/
	c->max_value = max_value_chunk(s->a, s->count.len_a, c->max_size - 1);
	c->min_value = min_value_chunk(s->a, s->count.len_a, size - 20);
	i = -1;
	while (++i < s->count.len_a)
		if (c->max_value == s->a[i])
			c->maxpos = i;
	i = -1;
	while (++i < s->count.len_a)
		if (c->min_value == s->a[i])
			c->minpos = i;
}
