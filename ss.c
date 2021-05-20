/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:18:26 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/20 16:01:47 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_swap *s)
{
	sa(s);
	sb(s);
}

void	sb(t_swap *s)
{
	int tmp;

	tmp = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = tmp;
	ft_putstr_fd("sb\n",1);
}

void	sa(t_swap *s)
{
	int tmp;

	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
	ft_putstr_fd("sa\n",1);
}
