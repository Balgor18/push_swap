/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:48:23 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/13 11:14:51 by fcatinau         ###   ########.fr       */
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
