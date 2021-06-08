/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:47:47 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/08 14:50:29 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verif_two_first(t_swap *s)
{
	if (s->count.len_b > 1)
	{
		if ((s->a[0] > s->a[1]) && (s->b[0] < s->b[1]))
			ft_ss(s);
		else if (s->b[0] < s->b[1])
			ft_sb(s);
	}
	if (s->a[0] > s->a[1])
		ft_sa(s);
	return ;
}

/*
** printf("%d < %d && %d > %d \n",s->a[0], s->a[s->count.len_a - 1],
** s->b[0], s->b[s->count.len_b - 1]);
** printf("rrr = %d < %d && %d < %d \n",s->a[0], s->a[s->count.len_a - 1],
** s->b[0], s->b[s->count.len_b - 1]);
** printf("rrb = %d > %d \n",s->b[0], s->b[s->count.len_b - 1]);
** printf("rb = %d < %d \n",s->b[0], s->b[s->count.len_b - 1]);
*/

void	verif_for_rr(t_swap *s)
{
	if (s->count.len_b >= 3)
	{
		if ((s->a[0] > s->a[s->count.len_a - 1])
			&& (s->b[0] < s->b[s->count.len_b - 1]))
			ft_rr(s);
		if (s->b[0] < s->b[s->count.len_b - 1])
			ft_rb(s);
	}
	if (s->a[0] > s->a[s->count.len_a - 1])
		ft_ra(s);
	return ;
}

void	verif_for_rrr(t_swap *s)
{
	if (s->count.len_b >= 3)
	{
		if ((s->a[0] > s->a[s->count.len_a - 1])
			&& (s->b[0] < s->b[s->count.len_b - 1]))
			ft_rrr(s);
		if (s->b[0] < s->b[s->count.len_b - 1])
			ft_rrb(s);
	}
	if (s->a[0] > s->a[s->count.len_a - 1])
		ft_rra(s);
	return ;
}

void	verif_swap_list(t_swap *s)
{
	if (s->count.len_b == 0)
		pa(s);
	if (verif_table_ok(s->a, s->count.len_a) && s->count.len_b > 0)
		pb(s);
}

int	verif_table_ok(int *s, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		//printf("1 %d\n2 %d\n3 %d\n",s[0],s[1], s[2]);
		//printf("%d > %d \n",s[i - 1], s[i]);
		if (s[i - 1] > s[i])
			return (0);
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}
