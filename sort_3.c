/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:31:05 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/08 16:58:07 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_swap *s)
{
	if (s->a[0] > s->a[1] && s->a[1] > s->a[2])
	{
		ft_sa(s);
		ft_rra(s);
	}
	else if (s->a[0] < s->a[1] && s->a[1] > s->a[2] && s->a[0] < s->a[2])
	{
		ft_sa(s);
		ft_ra(s);
	}
	else if (s->a[0] > s->a[2] && s->a[0] > s->a[1] && s->a[1] < s->a[2])
		ft_ra(s);
	else if (s->a[0] < s->a[1] && s->a[2] < s->a[1] && s->a[2] < s->a[0])
		ft_rra(s);
	else if (s->a[0] > s->a[1] && s->a[0] < s->a[2])
		ft_sa(s);
}

void	sort_5(t_swap *s)
{
	int i;

	i = -1;
	while (++i < 2)
		pa(s);
	sort_3(s);
	if (s->b[0] < s->b[1])
		ft_sb(s);
	while (s->count.len_b > 0)
		pb(s);
}
