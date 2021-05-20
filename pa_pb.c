/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:44:34 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/20 17:02:46 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_swap *s)
{
	s->b = malloc(sizeof(int *) * (s->count.len_b + 1));
	if (!s->b)
		return;
	ft_len_table(s);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_swap *s)
{
	s->a = malloc(sizeof(int *) * (s->count.len_a + 1));
	if (!s->a)
		return;
	ft_len_table(s);
	ft_putstr_fd("pb\n", 1);
}
