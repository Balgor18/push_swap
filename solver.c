/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:12:42 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/16 10:00:27 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solver(t_swap *swap) // voir solver a mettre en type void
{
	if (verif_table_ok(swap->a, swap->count.len_a))
		return (1);
	else if (swap->a[0] > swap->a[1])
		ft_sa(swap);
	else if (swap->count.len_a == 3)
		sort_3(swap);
	else if (swap->count.len_a <= 49)
		sort_49(swap);
	else if (swap->count.len_a <= 100)
		sort_100(swap);

	//if (!verif_table_ok(swap->a, swap->count.len_a))
	//	solver(swap);

	//ft_print(swap->a, 'A', swap->count.len_a);

	//ft_print(swap->a, 'A', swap->count.len_a);

	/*if (i > 3 && !verif_table_ok(swap->a, swap->count.len_a))
	{
		ft_putstr_fd("Error to much turn \n", 1);
		return (0);
	}*/

	//ft_print(swap->a, 'A', swap->count.len_a);
	return (1);
}
