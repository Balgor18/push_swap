/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:26:50 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/19 15:46:57 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// delete the main

int		verif_digit(char *s, int len)
{
	while (len > 0)
	{
		if (ft_isdigit(s[len - 1]))
			return(1);
		len--;
	}
	return (0);
}

int		main( int argc, char **argv)
{
	t_swap list;
	int i ;

	i = 0;
	list.len = argc - 1;
	while (--argc > 1)
		if (!verif_digit(argv[argc], ft_strlen(argv[argc])))
			return(ft_putstr("Error\n"));
	// si droit au truct go en faire une
	// sinon faire une len du nombre de valeur
	while (argc > i)
	{
		printf("argv[%d] = %s \n",i,argv[i]);
		i++;
	}
// use atoi
// malloc the table for the int;
// get the size of the table
	return(0);
}
