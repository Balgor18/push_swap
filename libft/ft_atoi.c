/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:32:53 by fcatinau          #+#    #+#             */
/*   Updated: 2021/07/14 17:00:38 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(char *c)
{
	long	i;
	long	sign;
	long	total;

	total = 0;
	i = 0;
	sign = 1;
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i] == '-')
			sign *= -1;
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		total = total * 10;
		total = total + (c[i] - 48);
		i++;
	}
	return (total * sign);
}
