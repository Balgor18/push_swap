/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 23:52:21 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/22 23:52:31 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_swap *s)
{
	s->a = malloc(sizeof(int *) * (s->count.len_a + 1));
	if (!s->a)
		return;
	ft_len_table(s);
	ft_putstr_fd("pb\n", 1);
}
