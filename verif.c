/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:47:47 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/20 16:44:04 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_digit(char *s, int len, t_swap *swap)
{
	while (len > 0)
	{
		if (!ft_isdigit(s[len - 1]) && s[len - 1] != ' ')
			return (0);
		if (ft_isdigit(s[len - 1]) && !ft_isdigit(s[len - 2]))
			swap->len++;
		len--;
	}
	return (1);
}

void	verif_two_first(t_swap *s)
{
	if (s->count.len_b > 0)
	{
		if ((s->a[0] > s->a[1]) && (s->b[0] > s->b[1]))
			ss(s);
		else if (s->b[0] > s->b[1])
			sb(s);
	}
	if (s->a[0] > s->a[1])
		sa(s);
	return;
}

void	verif_top_and_bot(t_swap *s)
{
	if (s->count.len_b > 0)
	{
		if ((s->a[0] > s->a[len_a - 1]) && (s->b[0] > s->b[len_b - 1]))
			rr(s);
		else if (s->b[0] > s->b[len_b - 1])
			rb(s);
	}
	if (s->a[0] > s->a[len_a - 1])
		ra(s);
}

void	verif_swap_list(t_swap *s)
{
	int	mid;
	int	i;

	mid = swap->len / 2; // si 0.5 va vers le plus bas ex : 7 / 2 = 3
	if (!verif_table_ok(s, mid))
		return;

}

int	verif_table_ok(t_swap *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}
