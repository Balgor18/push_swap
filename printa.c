/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:31:14 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/25 15:15:21 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TMP

void	ft_print(int *s, char c, int len)
{
	int	i;

	i = 0;
	if (len == 0)
		return ;
	printf("------ %c ------\n", c);
	while (i < len)
	{
		printf("pos %d| val %d \n", i, s[i]);
		i++;
	}
	printf("---------------\n");
}
