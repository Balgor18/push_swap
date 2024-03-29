/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 23:52:21 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/10 10:34:27 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_swap *s)
{
	int	i;

	i = s->count.len_a + 1;
	while (--i > 0)
		s->a[i] = s->a[i - 1];
	s->count.len_a++;
	s->a[0] = s->b[0];
	i = -1;
	s->count.len_b--;
	while (++i < s->count.len_b)
		s->b[i] = s->b[i + 1];
	ft_putstr_fd("pa\n", 1);
}
