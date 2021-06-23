/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_or_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:14:42 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/23 16:14:58 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	min_or_max(int minpos, int maxpos, int len)
{
	int	min_0;
	int	max_0;
	int	min_len;
	int	max_len;
	int	i;

	i = -1;
	min_0 = minpos;
	max_0 = maxpos;
	min_len = minpos - len;
	max_len = maxpos - len;
	if (min_len < 0)
		min_len *= -1;
	if (max_len < 0)
		max_len *= -1;
	if (minpos == maxpos)
	{
		if (min_len < min_0)
			return ('C');
		return ('A');
	}
	if (min_0 < max_0 && min_0 <= max_len && min_0 < min_len)
		return ('A');
	if (max_0 < min_0 && max_0 <= min_len && max_0 < max_len)
		return ('B');
	if (min_len < max_len && min_len < max_0 && min_len < min_0)
		return ('C');
	if (max_len < min_len && max_len < min_0 && max_len < max_0)
		return ('D');
	return (0);
}
