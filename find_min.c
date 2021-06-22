/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:43:33 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/22 16:03:17 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_swap *s)
{
	int	i;
	int	pos;
	int	mid;

	mid = s->count.len_a / 2;
	i = 0;
	pos = i;
	while (i < s->count.len_a)
	{
		if (s->a[pos] > s->a[i])
			pos = i;
		i++;
	}
	if (pos <= mid && pos != 0)
	{
		ft_ra(s);
		pos--;
	}
	else if (pos > mid)
	{
		ft_rra(s);
		pos++;
		if (pos == s->count.len_a)
			pos = 0;
	}
	if (s->a[0] == s->a[pos])
		ft_pb(s);
}

void	find_max(t_swap *s)
{
	int	i;
	int	pos;
	int	mid;

	mid = s->count.len_b / 2;
	i = 0;
	pos = i;
	while (i < s->count.len_b)
	{
		if (s->b[pos] < s->b[i])
			pos = i;
		i++;
	}
	//printf("-----------------------------------------------------------------------------------------\n");
	//ft_print(s->a, 'A', s->count.len_a);
	//ft_print(s->b, 'B', s->count.len_b);
	//printf("-----------------------------------------------------------------------------------------\n");
	while (pos <= mid && pos != 0)
	{
		ft_rb(s);
		pos--;
	}
	while (pos > mid)
	{
		//ft_print(s->b, 'B', s->count.len_b);
		ft_rrb(s);
		//ft_print(s->b, 'B', s->count.len_b);
		pos++;
		if (pos == s->count.len_b)
			pos = 0;
	}
	if (s->b[0] == s->b[pos])
		ft_pa(s);
}

// VOIR CAS OU MIN = 50 ET MAX = 49

// IF DOIS REGARDE LEQUEL EST LE PLUS PROCHE DE ZERO OU 99

// POUR CA

// FAIRE FONCTION QUE RETURN 'I' OU 'A' EN FONCTION DE QUI EST LE PLUS PROCHE

/*
char	min_or_max(int minpos, int maxpos)
{
	int	tmpmin;
	int	tmpmax;

	tmpmin = minpos - 50;
	tmpmax = maxpos - 50;

	// VERIF POSSIBILTY CLOSE OF 0 OR 99

	// CASE MINPOS = 50
	// CASE MAXPOS = 49

	// TMPMIN = 0
	// TMPMAX = -1

	if (tmpmax < tmpmin)
		return ('A');
	else if (tmpmax > tmpmin)
		return ('I');
	tmpmin = minpos + 50;
	tmpmax = maxpos + 50;
	if (tmpmin > tmpmax)
		return ('I');
	else if (tmpmax > tmpmin)
		return ('A');
	return ('R');
}
void	find_min_max(t_swap *s)
{
	int	i;
	int	minpos;
	int	maxpos;
	int	mid;

	mid = s->count.len_a / 2;
	i = 0;
	minpos = 0;
	maxpos = 0;
	while (i < s->count.len_a)
	{
		if (s->a[minpos] > s->a[i])
			minpos = i;
		else if (s->a[maxpos] < s->a[i])
			maxpos = i;
		i++;
	}
	if (min_or_max(minpos, maxpos) == 'I')
	{
		while (minpos != 99 && minpos != 0)
		{
			if (minpos > 50)
			{
				ft_rra(s);
				minpos++;
			}
			else if (minpos < 50)
			{
				ft_ra(s);
				minpos--;
			}
		}
		if (minpos == 99)
			ft_rra(s);
		ft_pb(s);
	}
	else if (min_or_max(minpos, maxpos) == 'A')
	{
		while (maxpos != 99 && maxpos != 0)
		{
			if (maxpos > 50)
			{
				ft_rra(s);
				maxpos++;
			}
			else if (maxpos < 50)
			{
				ft_ra(s);
				maxpos--;
			}
		}
		if (maxpos == 99)
			ft_rra(s);
		ft_pb(s);
	}
	ft_print(s->a,'A', s->count.len_a);
	ft_print(s->b,'B', s->count.len_b);
}*/
