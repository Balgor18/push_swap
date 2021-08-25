/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:48:23 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/25 10:48:41 by fcatinau         ###   ########.fr       */
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
	int	pos;
	int	i;
	int	j;

	i = 0;
	pos = 1;
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
