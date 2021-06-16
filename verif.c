/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:47:47 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/16 10:02:44 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_table_ok(int *s, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (s[i - 1] > s[i])
			return (0);
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}
