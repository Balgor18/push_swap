/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:19:39 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/25 16:26:39 by fcatinau         ###   ########.fr       */
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

void	init_struct_for_copy(int *src, t_copylist *c, int *dest, int len)
{
	c->src = src;
	c->dest = dest;
	c->len = len;
	c->stop = len;
}
