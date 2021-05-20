/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:54:45 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/20 17:15:36 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	ft_ra(t_swap *s)
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
	ft_putstr_fd("ft_ra\n",1);
}

// verif ft_ra avant de copier pour ft_rb
void	ft_rb(t_swap *s)
{
	(void)s;
	ft_putstr_fd("ft_ra\n",1);
}

void	ft_rr(t_swap *s)
{
	ft_ra(s);
	ft_rb(s);
}
