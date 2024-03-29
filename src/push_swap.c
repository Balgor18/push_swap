/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:26:50 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/31 14:36:18 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(t_swap *swap, char **s)
{
	int		i;
	int		h;

	i = 0;
	s++;
	while (i < swap->count.len_a)
	{
		h = verif_nb_num(*s);
		if (h > 1)
			parser_bis(h, &i, s, swap);
		if (i < swap->count.len_a)
		{
			swap->a[i++] = ft_atoi(*s);
			s++;
		}
	}
}

int	prepare_a(t_swap *swap, char **s)
{
	if (swap->count.len_a <= 3)
	{
		swap->a = malloc(sizeof(int *) * swap->count.len_a);
		if (!swap->a)
			return (0);
	}
	else
	{
		swap->a = malloc(sizeof(int *) * swap->count.len_a);
		swap->b = malloc(sizeof(int *) * swap->count.len_a);
		if (!swap->a || !swap->b)
			return (0);
	}
	parse(swap, s);
	return (1);
}

int	ft_same_int(int j, char **av)
{
	int	i;
	int	h;

	i = 1;
	h = verif_nb_num(av[j]);
	if (h > 1)
		return (parse_same_int(av[j]));
	else
		if (ft_same_int2(av, &j, &i))
			return (1);
	return (0);
}

void	call_solver_and_free(t_swap *s)
{
	solver(s);
	free(s->a);
	if (s->count.len_a > 3)
		free(s->b);
}

int	main(int argc, char **argv)
{
	int		tmp;
	t_swap	swap;

	tmp = argc - 1;
	init_struct(&swap);
	if (argc < 2)
		return (0);
	if (argv[tmp] == NULL)
		--tmp;
	while (tmp >= 1)
	{
		if (!verif_digit(argv[tmp], ft_strlen(argv[tmp]), &swap)
			|| ft_same_int(1, argv) || verif_size_int(argv[tmp])
			|| !argv[tmp][0])
			return (ft_error());
		--tmp;
	}
	if (!prepare_a(&swap, argv))
		return (0);
	call_solver_and_free(&swap);
	return (0);
}
