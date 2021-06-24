/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:43:33 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/24 14:53:25 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_swap *s)
{
	int	i;
	int	pos;
	int	mid;

	mid = s->count.len_a / 2;
	i = 0;
	pos = i;
	while (i < s->count.len_a)
	{
		if (s->a[pos] > s->a[i])
			pos = i;
		i++;
	}
	if (pos <= mid && pos != 0)
	{
		ft_ra(s);
		pos--;
	}
	else if (pos > mid)
	{
		ft_rra(s);
		pos++;
		if (pos == s->count.len_a)
			pos = 0;
	}
	if (s->a[0] == s->a[pos])
		ft_pb(s);
}

void	find_max(t_swap *s)
{
	int	i;
	int	pos;
	int	mid;

	mid = s->count.len_b / 2;
	i = 0;
	pos = i;
	while (i < s->count.len_b)
	{
		if (s->b[pos] < s->b[i])
			pos = i;
		i++;
	}
	while (pos <= mid && pos != 0)
	{
		ft_rb(s);
		pos--;
	}
	while (pos > mid)
	{
		ft_rrb(s);
		pos++;
		if (pos == s->count.len_b)
			pos = 0;
	}
	if (s->b[0] == s->b[pos])
		ft_pa(s);
}
