/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:12:42 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/31 22:13:35 by fcatinau         ###   ########.fr       */
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
	int j;

	j = 0;
	if (!i)
		i = 0;
	printf("tour %d \n", i);
	i++;
	while (j < 10000000)
		j++;
	if (swap->count.len_a == 2 || swap->count.len_b == 2)
	{
		resolve_len_two(swap);
		return (0);
	}
	//printf("Je seg fault \n");
	verif_two_first(swap);
	if (!verif_table_ok(swap, swap->count.len_a))
		verif_swap_list(swap);
	//if (!verif_table_ok(swap, swap->count.len_a))
	//	verif_top_and_bot(swap);
	// ---------------------------
	//ft_print(swap->a, 'A', swap->count.len_a);
	//ft_print(swap->b, 'B', swap->count.len_b);
	//printf("verif table ok %d \n", verif_table_ok(swap, swap->count.len_a));
	if (!verif_table_ok(swap, swap->count.len_a))
		solver(swap);
	free(swap->a);
	return (1);
}
