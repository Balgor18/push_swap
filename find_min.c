/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:43:33 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/10 11:19:10 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_swap *s)
{
	int	i;
	int	tmp;
	int	pos;
	int	mid;

	mid = s->count.len_a / 2;
	i = 0;
	tmp = s->a[0];
	while (i < s->count.len_a)
	{
		if (tmp > s->a[i])
		{
			tmp = s->a[i];
			pos = i;
		}
		i++;
	}
	//printf("je boucle \n");
	//ft_print(s->a, 'a', s->count.len_a);
	if (pos <= mid)
		ft_ra(s);
	else if (pos > mid)
		ft_rra(s);
	//printf("%d == %d \n", s->a[0], tmp);
	if (s->a[0] == tmp)
		ft_pb(s);
}
