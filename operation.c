/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:41:43 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/07 17:23:46 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_low_int(t_operation *ope, t_swap *s)
{
	int	i;
	int	tmp;

	tmp = 2147483647;
	i = 0;
	while (i < s->count.len_a)
	{
		if (s->a[i] <= tmp)
		{
			tmp = s->a[i];
			ope->low_int = i;
		}
		i++;
	}
}

void	verif_operation(t_swap *s)
{
	t_operation	ope;
	int			i;

	i = 0;
	ope.mid = s->count.len_a / 2;
	find_low_int(&ope, s);
	if (ope.low_int >= ope.mid)
	{
		while (i < ope.mid && s->a[i] > s->a[ope.mid])
		{
			i++;
		}
	}
	if (i == ope.mid)
		while (i > 0)
		{
			ft_ra(s);
			--i;
		}
	/*else
	{
		i =
		while (i < ope.mid && s->a[i] )
		{
			i--;
		}
	}*/
}
