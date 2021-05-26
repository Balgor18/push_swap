/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:12:42 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/26 13:00:56 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solver(t_swap *swap)
{
	static int i;
	int j;

	j = 0;
	if (!i)
		i = 0;
//	printf("tour %d \n", i);
	i++;
//	while (j < 10000000)
//		j++;
	verif_two_first(swap);
	verif_swap_list(swap);
	verif_top_and_bot(swap);
//	ft_print(swap->a, 'A', swap->count.len_a);
//	ft_print(swap->b, 'B', swap->count.len_b);
	//printf("verif table ok %d \n", verif_table_ok(swap, swap->count.len_a));
	if (!verif_table_ok(swap, swap->count.len_a))
		solver(swap);
	free(swap->a);
	return (1);
}
