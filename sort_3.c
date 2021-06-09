/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:31:05 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/09 16:45:15 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_first(t_swap *s)
{
	if (s->a[1] > s->a[4])
	{
		ft_sa(s);
		ft_ra(s);
	}
	if (s->a[0] < s->a[4] && s->a[0] > s->a[3])
	{
		ft_rra(s);
		ft_sa(s);
		ft_ra(s);
		ft_ra(s);
	}
}

void	sort_b_for_a(t_swap *s)
{
	if (s->b[0] > s->a[0])
	{
		pb(s);
		ft_sa(s);
	}
}

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
	//ft_print(s->b, 'B', s->count.len_b);
	//ft_print(s->a, 'A', s->count.len_a);
	sort_b_for_a(s);
	//ft_print(s->b, 'B', s->count.len_b);
	//ft_print(s->a, 'A', s->count.len_a);
	//printf("%d < %d || %d \n", s->b[0], s->b[1], verif_table_ok(s->a, s->count.len_a));
	if (s->b[0] < s->b[1] && verif_table_ok(s->a, s->count.len_a))
		ft_sb(s);
	while (s->count.len_b > 0)
		pb(s);
	two_first(s);
}