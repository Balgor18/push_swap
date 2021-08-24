/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:58:36 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/24 14:24:28 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_isnot_char(char c)
{
	if (c != '-' && c != '+' && (c < '0' || c > '9') && c != ' ')
		return (0);
	return (1);
}

int	verif_digit(char *s, int len, t_swap *swap)
{
	int	i;

	i = -1;
	while (len > ++i)
	{
		if (!verif_all(s, i))
			return (0);
		if (ft_isdigit(s[i]) || s[i] == '-' || s[i] == '+')
		{
			swap->count.len_a++;
			while ((ft_isdigit(s[i]) || s[i] == '-' || s[i] == '+') && len > i)
				++i;
		}
		if (!verif_all(s, i))
			return (0);
	}
	return (1);
}
