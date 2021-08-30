/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:47:47 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/30 10:53:54 by fcatinau         ###   ########.fr       */
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
		if (ft_strlen_int(&s[i], ft_isdigit) > 11)
			return (1);
		if (ft_atoi(&s[i]) > INT_MAX || ft_atoi(&s[i]) < INT_MIN)
			return (1);
		if (s[i] == '-' || s[i] == '+')
			i++;
		while (ft_isdigit(s[i]))
			i++;
		if (s[i] == ' ')
			i++;
	}
	return (0);
}

int	verif_operation(int len, char *s)
{
	if (s[len] == '-')
		if (ft_isdigit(s[len + 1]))
			return (1);
	if (s[len] == '+')
		if (ft_isdigit(s[len + 1]))
			return (1);
	return (0);
}

int	verif_all(char *s, int i)
{
	if (s[i] == '\0')
		return (1);
	if (s[i] == ' ')
		if (!ft_isdigit(s[i + 1]))
			return (0);
	if (s[i] == '-' || s[i] == '+')
		if (!verif_operation(i, s))
			return (0);
	if (!verif_isnot_char(s[i]))
		return (0);
	return (1);
}
