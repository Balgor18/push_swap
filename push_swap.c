/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:26:50 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/19 19:08:57 by fcatinau         ###   ########.fr       */
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
			swap->len++;
		len--;
	}
	return (1);
}

int	prepare_A(t_swap *swap, char **s)
{
	int	i;
	int j;
	//printf("%d < %d \n",i , swap->len);
	j = 1;
	i = 0;
	swap->a = malloc(sizeof(int *) * swap->len);
	if (!swap->a)
		return(0);
	while(i < swap->len)
	{

		//printf("%d %s \n", j, s[j]);
		swap->a[i] = ft_atoi(s[j]);
		i++;
		j++;
	}
	return (1);
}
/*
void	solver(t_swap *swap)
{

}*/

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
/*	if (!prepare_A(&swap, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}*/
//	solver(&swap);
	// use atoi
	// malloc the table for the int;
	// get the size of the table
	printf("Done \n");
	return (0);
}
