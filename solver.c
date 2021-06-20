/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:12:42 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/20 17:17:03 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solver(t_swap *swap) // voir solver a mettre en type void
{
	if (verif_table_ok(swap->a, swap->count.len_a))
		return (1);
	else if (swap->a[0] > swap->a[1] && swap->count.len_a == 2)
		ft_sa(swap);
	else if (swap->count.len_a == 3)
		sort_3(swap);
	else if (swap->count.len_a <= 49)
		sort_49(swap);
	else if (swap->count.len_a <= 100)
		sort_100(swap);
	return (1);
}
