/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:11:44 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/25 16:11:52 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	while_pb(t_swap *s, t_chunk *c, int max)
{
	while (c->minpos < max && c->minpos != 0)
	{
		ft_ra(s);
		c->minpos--;
	}
	while (max < c->minpos && c->maxpos != s->count.len_a)
	{
		ft_rra(s);
		c->maxpos++;
	}
	ft_pb(s);
}
