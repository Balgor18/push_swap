/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:12:42 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/25 11:53:13 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solver(t_swap *swap)
{
	verif_two_first(swap);
	verif_swap_list(swap);
	verif_top_and_bot(swap);
	printf("je boucle 1\n");
	printf("virf_table de tes mort \n");
	printf("return %d \n", verif_table_ok(swap, swap->len));
	return (0);
	if (!verif_table_ok(swap, swap->len))
		solver(swap);
	return (1);
}
