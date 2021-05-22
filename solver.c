/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:12:42 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/22 23:45:55 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solver(t_swap *swap)
{
	//int	ret;

//	printf("je rentre dans two_first \n");
	verif_two_first(swap);

	verif_swap_list(swap);
//	verif_top_and_bot(swap);
//	if (!verif_table_ok(swap, swap->len))
//		solver(swap);
	return (1);
}
