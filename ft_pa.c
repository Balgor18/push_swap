/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:44:34 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/03 15:10:59 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_swap *s)
{
	int	i;

	i = s->count.len_b + 1;
	while (--i > 0)
		s->b[i] = s->b[i - 1];
	s->count.len_b++;
	s->b[0] = s->a[0];
	i = -1;
	s->count.len_a--;
	while (++i < s->count.len_a)
		s->a[i] = s->a[i + 1];
	ft_putstr_fd("pa\n", 1);
}
