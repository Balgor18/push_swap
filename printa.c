/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:31:14 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/21 17:18:19 by fcatinau         ###   ########.fr       */
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
	printf("------ %c ------\n",c);
	while(i < len)
	{
		printf("pos %d|%d \n", i, s[i]);
		i++;
	}
	printf("---------------\n");
}
