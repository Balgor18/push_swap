/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:48:23 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/30 12:07:37 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parser_bis(int h, int *i, char **s, t_swap *swap)
{
	int		j;
	char	**ret;

	j = 0;
	ret = ft_split(*s, ' ');
	while (j < h || ret[j])
	{
		swap->a[*i] = ft_atoi(ret[j]);
		free(ret[j]);
		j++;
		*i += 1;
	}
	free(ret);
}

void	parse_same_int_2(char *s, int *i, int *bis)
{
	*bis = ft_atoi(&s[*i]);
	while (ft_isdigit(s[*i]))
		*i += 1;
	if (s[*i] == ' ')
		*i += 1;
}

int	parse_same_int(char *s)
{
	int	a;
	int	b;
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		parse_same_int_2(s, &i, &a);
		j = i;
		while (s[j])
		{
			parse_same_int_2(s, &j, &b);
			if (a == b)
				return (1);
		}
	}
	return (0);
}

int	ft_same_int2(char *s1, char *s2, int *i, int *j)
{
	while (s1[*j])
	{
		while (s2[*i])
		{
			if ((ft_strcmp(&s2[*i], &s1[*j]) == 0 && *i != *j) \
				|| verif_same_zero(&s2[*i], &s1[*j]))
				return (1);
			*i += 1;
		}
		*j += 1;
		*i = 1;
	}
	return (0);
}
