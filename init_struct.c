/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:19:39 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/23 17:42:32 by fcatinau         ###   ########.fr       */
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
	val = tmp[pos];
	free(tmp);
	return (val);
}
