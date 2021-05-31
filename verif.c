/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:47:47 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/31 15:07:36 by fcatinau         ###   ########.fr       */
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
			swap->count.len_a++;
		len--;
	}
	return (1);
}

void	verif_two_first(t_swap *s)
{
	if (s->count.len_b > 0)
	{
		if ((s->a[0] > s->a[1]) && (s->b[0] < s->b[1]))
			ft_ss(s);
		else if (s->b[0] < s->b[1])
			ft_sb(s);
	}
	if (s->a[0] > s->a[1])
		ft_sa(s);
	return ;
}

/*
** printf("%d < %d && %d > %d \n",s->a[0], s->a[s->count.len_a - 1],
** s->b[0], s->b[s->count.len_b - 1]);
** printf("rrr = %d < %d && %d < %d \n",s->a[0], s->a[s->count.len_a - 1],
** s->b[0], s->b[s->count.len_b - 1]);
** printf("rrb = %d > %d \n",s->b[0], s->b[s->count.len_b - 1]);
** printf("rb = %d < %d \n",s->b[0], s->b[s->count.len_b - 1]);
*/

void	verif_top_and_bot(t_swap *s)
{
	if (s->count.len_b > 3)
	{
		if ((s->a[0] > s->a[s->count.len_a - 1])
			&& (s->b[0] < s->b[s->count.len_b - 1]))
			ft_rr(s);
		else if ((s->a[0] < s->a[s->count.len_a - 1])
			&& (s->b[0] < s->b[s->count.len_b - 1]))
			ft_rrr(s);
		else if (s->b[0] < s->b[s->count.len_b - 1])
			ft_rb(s);
		else if (s->b[0] < s->b[s->count.len_b - 1])
			ft_rrb(s);
	}
	if (s->a[0] > s->a[s->count.len_a - 1])
		ft_ra(s);
	else if (s->a[0] < s->a[s->count.len_a - 1])
		ft_rra(s);
	return ;
}

void	verif_swap_list(t_swap *s)
{
	int	mid;

	mid = s->count.len_a / 2;
	printf("problem here \n");
	if (s->count.len_b == 0)
		pa(s, mid - 1);
	if (verif_table_ok(s, s->count.len_a) && s->count.len_b > 0)
		pb(s, s->count.len_b);
}

int	verif_table_ok(t_swap *s, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (s->a[i - 1] > s->a[i])
			return (0);
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}
