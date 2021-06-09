/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:12:42 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/09 10:51:31 by fcatinau         ###   ########.fr       */
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
	//printf("tour j %d \n", i);
	i++;
	if (verif_table_ok(swap->a, swap->count.len_a))
		return (1);
	if (swap->count.len_a == 5)
		sort_5(swap);
	else
		sort_3(swap);
	//ft_print(swap->a, 'A', swap->count.len_a);

//	ft_print(swap->a, 'A', swap->count.len_a);
	if (i > 10 && !verif_table_ok(swap->a, swap->count.len_a))
	{
		ft_putstr_fd("Error to much turn \n", 1);
		return (0);
	}
	if (!verif_table_ok(swap->a, swap->count.len_a))
		solver(swap);
	//ft_print(swap->a, 'A', swap->count.len_a);
	return (1);
}
