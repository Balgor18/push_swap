/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:47:47 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/06 13:47:02 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_nb_num(char *s)
{
	int	i;
	int	num;

	num = 0;
	i = 1;
	if ((ft_isdigit(s[0])))
		num++;
	while (s[i])
	{
		if ((ft_isdigit(s[i]) && (!ft_isdigit(s[i - 1]) || s[i - 1] == '-')))
			num++;
		i++;
	}
	return (num);
}

int	verif_table_ok(int *s, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (s[i - 1] > s[i])
			return (0);
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}

int	verif_size_int(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_atoi(&s[i]) > INT_MAX || ft_atoi(&s[i]) < INT_MIN)
			return (1);
		if (s[i] == '-' || s[i] == '+')
			i++;
		while (ft_isdigit(s[i]))
			i++;
		while (s[i] == ' ')
			i++;
	}
	return (0);
}

int	verif_isnot_char(char c)
{
	if (c != '-' && c != '+' && (c < '0' || c > '9'))
		return (0);
	return (1);
}

int	verif_digit(char *s, int len, t_swap *swap)
{
	int	space;

	space = 0;
	while (len > 0)
	{
		if (s[len - 1] == ' ')
			space++;
		if (space > 1)
			return (0);
		if ((s[len] == '-' && s[len - 1] == '-') \
		|| (s[len] == '+' && s[len - 1] == '+'))
			return (0);
		if (!verif_isnot_char(s[len - 1]))
			return (0);
		if (ft_isdigit(s[len - 1]) && !ft_isdigit(s[len - 2]))
		{
			space = 0;
			swap->count.len_a++;
			while (ft_isdigit(s[len - 1]) && len > 0)
				len--;
		}
		len--;
	}
	return (1);
}
