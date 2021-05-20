/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:03:09 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/20 17:10:48 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// si len marche pas je dois faire len b = a la moitie de len a
void	ft_len_table(t_swap *s)
{
	ft_len(s->a, &s->count.len_a);
	ft_len(s->b, &s->count.len_b);

	printf("len a %d \n",s->count.len_a);
	printf("len b %d \n",s->count.len_b);
}

void	ft_len(int *list, int *a)
{
	int i;

	i = 0;
	while (list[i])
		i++;
	*a = i;
}
