/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:54:45 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/25 15:17:22 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_swap *s)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->a[0];
	while (i < s->count.len_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[i - 1] = tmp;
	ft_putstr_fd("ft_ra\n", 1);
}

void	ft_rb(t_swap *s)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->b[0];
	while (i < s->count.len_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[i - 1] = tmp;
	ft_putstr_fd("ft_rb\n", 1);
}

void	ft_rr(t_swap *s)
{
	ft_ra(s);
	ft_rb(s);
}
