/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:12:42 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/04 15:17:21 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_len_two(t_swap *s)
{
	if (s->count.len_a == 2)
		if (s->a[0] > s->a[1])
			ft_sa(s);
	if (s->count.len_b == 2)
		if (s->b[0] < s->b[1])
			ft_sb(s);
}

int	solver(t_swap *swap)
{
	static int i;

	if (!i)
		i = 1;
	printf("tour %d \n", i);
	ft_print(swap->a, 'A', swap->count.len_a);
	i++;
	if (swap->count.len_a == 2 || swap->count.len_b == 2)
	{
		resolve_len_two(swap);
		if (verif_table_ok(swap, swap->count.len_a + swap->count.len_b))
			return (1);
	}
	if (!verif_table_ok(swap, swap->count.len_a + swap->count.len_b))
		verif_two_first(swap);
	if (!verif_table_ok(swap, swap->count.len_a + swap->count.len_b))
		verif_swap_list(swap);
	if (!verif_table_ok(swap, swap->count.len_a + swap->count.len_b))
		verif_for_rr(swap);
	if (!verif_table_ok(swap, swap->count.len_a + swap->count.len_b))
		verif_for_rrr(swap);
	while (verif_pb_is_need(swap))
		pb(swap);
	if (!verif_table_ok(swap, swap->count.len_a + swap->count.len_b))
		solver(swap);
	ft_print(swap->a, 'A', swap->count.len_a);
	//ft_print(swap->b, 'B', swap->count.len_b);
	return (1);
}
