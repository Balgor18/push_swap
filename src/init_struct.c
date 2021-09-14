/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:19:39 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/14 19:07:47 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_struct(t_swap *s)
{
	s->a = 0;
	s->b = 0;
	s->count.len_a = 0;
	s->count.len_b = 0;
}

int	*copy_list(int *t, int len)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = malloc(sizeof(int *) * len);
	if (!tmp)
		exit (1);
	while (++i < len)
		tmp[i] = t[i];
	return (tmp);
}

int	max_value_chunk(t_swap *s, int *t, int len, int pos)
{
	int	*tmp;
	int	val;

	tmp = copy_list(t, len);
	ft_sort_int_tab(tmp, len);
	if (s->count.len_a <= pos)
		val = tmp[s->count.len_a - 1];
	else
		val = tmp[pos];
	free(tmp);
	return (val);
}
