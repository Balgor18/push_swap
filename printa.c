/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:31:14 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/20 18:17:36 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TMP
void	print_a(t_swap *s)
{
	int	i;

	i = 0;
	// print inside a
	while(i < s->len)
	{
		printf("%d|%d \n", i, s->a[i]);
		i++;
	}
}
