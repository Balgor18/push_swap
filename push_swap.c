/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:26:50 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/20 18:17:44 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prepare_A(t_swap *swap, char **s)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	swap->a = malloc(sizeof(int *) * swap->len);
	if (!swap->a)
		return(0);
	while(i < swap->len)
	{
		swap->a[i] = ft_atoi(s[j]);
		i++;
		j++;
	}

	return (1);
}

int	main(int argc, char **argv)
{
	t_swap	swap;

	init_struct(&swap);
	while (--argc >= 1)
	{
		if (!verif_digit(argv[argc], ft_strlen(argv[argc]), &swap))
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
	}
	if (!prepare_A(&swap, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
//	print_a(&swap);
	solver(&swap);
//	ft_len_table(&swap);
	//print_a(&swap);
	printf("Done \n");
	return (0);
}
