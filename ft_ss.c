/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:18:26 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/26 10:14:18 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_swap *s)
{
	int	tmp;

	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_swap *s) // ca va pas 
{
	int	tmp;

	tmp = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_swap *s)
{
	ft_sa(s);
	ft_sb(s);
}
