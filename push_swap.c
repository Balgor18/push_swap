/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:26:50 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/20 17:15:38 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(t_swap *swap, char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < swap->count.len_a)
	{
		swap->a[i] = ft_atoi(s[j]);
		i++;
		j++;
	}
}

int	prepare_A(t_swap *swap, char **s)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	swap->a = malloc(sizeof(int *) * swap->count.len_a);
	swap->b = malloc(sizeof(int *) * swap->count.len_a);
	if (!swap->a || !swap->b)
		return (0);
	if (swap->type == 'S')
	{
		while (s[1][i] && pos <= swap->count.len_a)
		{
			swap->a[pos] = ft_atoi(&s[1][i]);
			while (ft_isdigit(s[1][i]))
				i++;
			while (!ft_isdigit(s[1][i]))
				i++;
			pos++;
		}
	}
	else
		parse(swap, s);
	return (1);
}

int	ft_same_int(int j, char **av)
{
	int	i;

	i = 1;
	while (av[j])
	{
		while (av[i])
		{
			if (ft_strcmp(av[i], av[j]) == 0 && i != j)
				return (1);
			i++;
		}
		j++;
		i = 1;
	}
	return (0);
}

/*
int	verif_size_int(char *s)
{
	ft_strncmp(s, "2147483647", ft_strlen(s));
	ft_strncmp(s, "-2147483648", ft_strlen(s));
}
*/

int	main(int argc, char **argv)
{
	int		tmp;
	t_swap	swap;

	tmp = argc;
	init_struct(&swap);
	if (argc < 2)
		return (0);
	while (--tmp >= 1)
	{
		if (!verif_digit(argv[tmp], ft_strlen(argv[tmp]), &swap) || ft_same_int(1, argv))// || verif_size_int(argv[tmp]))
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
	}
	if (argc < swap.count.len_a)
		swap.type = 'S';
	if (!prepare_A(&swap, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	solver(&swap);
	if (verif_table_ok(swap.a, swap.count.len_a))
	{
		printf("\033[0;32m");// vert
		printf("OK\n");
		//ft_print(swap.a, 'A', swap.count.len_a);
		printf("\033[0;37m");// blanc
	}
	else
	{
		printf("\033[0;31m");// rouge
		printf("KO\n");
		printf("\033[0;37m");// blanc
		ft_print(swap.a, 'A', swap.count.len_a);
		if (swap.count.len_b > 0)
			ft_print(swap.b, 'B', swap.count.len_b);
	}
	free(swap.a);
	free(swap.b);
	return (0);
}
