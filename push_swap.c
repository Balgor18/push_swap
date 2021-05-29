/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:26:50 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/29 17:31:00 by fcatinau         ###   ########.fr       */
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
	if (!swap->a)
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
		if (!verif_digit(argv[tmp], ft_strlen(argv[tmp]), &swap))
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
	if (solver(&swap))
		return (0);
	ft_print(swap.a, 'A', swap.count.len_a);
	return (0);
}
