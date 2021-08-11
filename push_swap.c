/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:26:50 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/11 11:54:17 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(t_swap *swap, char **s)
{
	int		i;
	int		h;
	char	**ret;

	i = 0;
	s++;
	while (i < swap->count.len_a)
	{
		h = verif_nb_num(*s);
		if (h > 1)
		{
			ret = ft_split(*s, ' ');
			while (h-- > 0)
			{
				swap->a[i++] = ft_atoi(*ret);
				ret++;
				//free(*ret);
			}
			printf("l'erreur est dans le split COMME DHAB\n");
			//free(ret);
			printf("AH BAH NON \n");
			printf("je free ret\n");
		}
		if (i < swap->count.len_a)
		{
			swap->a[i++] = ft_atoi(*s);
			s++;
		}
	}
}

int	prepare_a(t_swap *swap, char **s)
{
	printf("count = %d \n", swap->count.len_a);
	if (swap->count.len_a <= 3)
	{
		printf("je malloc que a \n");
		swap->a = malloc(sizeof(int *) * swap->count.len_a);
		if (!swap->a)
			return (0);
	}
	else
	{
		printf("je malloc a et b\n");
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

void	call_solver_and_free(t_swap *s)
{
	solver(s);
	//printf("je free a");
	free(s->a);
	printf("je free a");
	if (s->count.len_a > 3)
	{
		printf(" et b");
		free(s->b);
	}
	printf("\n");
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
	printf("malloc error 0\n");
	call_solver_and_free(&swap);
	return (0);
}
