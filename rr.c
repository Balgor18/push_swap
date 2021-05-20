/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:54:45 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/20 16:05:09 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	ra(t_swap *s)
{
	printf("Avant \n");
	print_a(s);
	printf("--------------------");
	int	tmp;
	int	i;

	i = 0;
	tmp = s->a[i];
	while (i < s->count.len_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[i] = tmp;
	printf("Apres \n");
	print_a(s);
	ft_putstr_fd("ra\n",1);
}

// verif ra avant de copier pour rb
void	rb(t_swap *s)
{
	ft_putstr_fd("ra\n",1);
}

void	rr(t_swap *s)
{
	ra(s);
	rb(s);
}
