/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:12:42 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/25 12:22:25 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solver(t_swap *swap)
{
//	ft_ra(swap);
	verif_two_first(swap);
	verif_swap_list(swap);
	verif_top_and_bot(swap);
	if (!verif_table_ok(swap, swap->count.len_a))
		solver(swap);
	return (1);
}
