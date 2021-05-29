/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:02:04 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/29 17:27:04 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_swap *s)
{
	int	tmp;
	int	i;

	i = s->count.len_a - 1;
	tmp = s->a[i];
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[i] = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_swap *s)
{
	int	tmp;
	int	i;

	i = s->count.len_b - 1;
	tmp = s->b[i];
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[i] = tmp;
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_swap *s)
{
	ft_rra(s);
	ft_rrb(s);
}
