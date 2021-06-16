/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:07:15 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/16 10:02:32 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_digit(char *s, int len, t_swap *swap)
{
	while (len > 0)
	{
		if (!ft_isdigit(s[len - 1]) && s[len - 1] != ' ')
			return (0);
		if (ft_isdigit(s[len - 1]) && !ft_isdigit(s[len - 2]))
			swap->count.len_a++;
		len--;
	}
	return (1);
}
