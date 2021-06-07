/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:07:15 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/07 11:33:19 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_pb_is_need(t_swap *s)
{
	int i;

	i = 1;
	while (i < s->count.len_a)
	{
		/*ft_putstr_fd("boucle verif pb \n s->a[", 1);
		ft_putnbr_fd(i - 1, 1);
		ft_putchar_fd(']', 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(s->a[i - 1] , 1);
		ft_putstr_fd(" > s->a[", 1);
		ft_putnbr_fd(i , 1);
		ft_putchar_fd(']', 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(s->a[i] , 1);
		ft_putchar_fd('\n', 1);*/

		if (((s->a[i - 1] > s->a[i]) && (s->a[i] < s->b[0])) || !verif_table_ok(s, s->count.len_a))
			return (0);
		i++;
	}

	if (s->count.len_b > 0)
		if (s->b[0] < s->a[0] || !verif_table_ok(s, s->count.len_a))
			return (1);
	return (0);
}


int	verif_pa_is_need(t_swap *s)
{
	int i;

	i = 1;
	if (s->a[0] > s->b[0] && s->count.len_b > 0)
		return (1);
	/*while (i < s->count.len_b)
	{
		if ((s->b[i - 1] > s->b[i]) && (s->b[i] < s->a[0]))
			return (0);
		i++;
	}*/

	/*if (s->count.len_a > 0)
		if (s->a[0] < s->b[0] || !verif_table_ok(s, s->count.len_a))
			return (1);*/
	return (0);
}

int	verif_digit(char *s, int len, t_swap *swap)
{
	while (len > 0)
	{
		if (!ft_isdigit(s[len - 1]) && s[len - 1] != ' ')
			return (0);
		if (ft_isdigit(s[len - 1]) && !ft_isdigit(s[len - 2]))
			swap->count.len_a++;
		len--;
	}
	return (1);
}
