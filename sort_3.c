/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:31:05 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/16 09:51:40 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_first(t_swap *s)
{
	if (s->a[1] > s->a[4])
	{
		ft_sa(s);
		ft_ra(s);
	}
	if (s->a[0] < s->a[4] && s->a[0] > s->a[3])
	{
		ft_rra(s);
		ft_sa(s);
		ft_ra(s);
		ft_ra(s);
	}
}

void	sort_b_for_a(t_swap *s)
{
	if (s->b[0] > s->a[0] && s->b[0] < s->a[s->count.len_a - 1])
	{
		ft_pa(s);
		ft_rra(s);
		ft_sa(s);
		ft_ra(s);
		ft_ra(s);
	}
	if (s->b[0] > s->a[0])
	{
		ft_pa(s);
		ft_sa(s);
	}
}

void	sort_3(t_swap *s)
{
	if (s->a[0] > s->a[1] && s->a[1] > s->a[2])
	{
		ft_sa(s);
		ft_rra(s);
	}
	else if (s->a[0] < s->a[1] && s->a[1] > s->a[2] && s->a[0] < s->a[2])
	{
		ft_sa(s);
		ft_ra(s);
	}
	else if (s->a[0] > s->a[2] && s->a[0] > s->a[1] && s->a[1] < s->a[2])
		ft_ra(s);
	else if (s->a[0] < s->a[1] && s->a[2] < s->a[1] && s->a[2] < s->a[0])
		ft_rra(s);
	else if (s->a[0] > s->a[1] && s->a[0] < s->a[2])
		ft_sa(s);
}

void	sort_49(t_swap *s)
{
	while (s->count.len_a > 3)
		find_min(s);
	sort_3(s);
	//ft_print(s->a, 'A',s->count.len_a);
	//ft_print(s->b, 'B',s->count.len_b);
	//sort_b_for_a(s);
	if (s->b[0] < s->b[1] && verif_table_ok(s->a, s->count.len_a))
		ft_sb(s);
	while (s->count.len_b > 0)
		ft_pa(s);
	//two_first(s);
}

/*
** faire une struct pour le min max
** s_chunk
** int	nb;
** int	minpos;
** int	maxpos;
** int	nb_int;
** s_chunk *next;
** t_chunk
*/

// Voir si je fais cet fonction pour les 2 listes ou que 1
/*void	find_min_max_in_chunck(int *lst, int len)
{
	int	minpos;
	int	maxpos;
	int	i;

	i = 0;
	minpos = 0;
	maxpos = 0;
	while (i < len)
	{
		if (lst[minpos] > lst[i])
			minpos = i;
		if (lst[maxpos] < lst[i])
			maxpos = i;
		i++;
	}
	printf("minpos %d\nmaxpos %d \n", minpos, maxpos);
}*/

//void	//

void	find_min_max_in_chunck(t_swap *s)
{
	int	minpos;
	int	maxpos;
	int	i;

	i = 0;
	minpos = 0;
	maxpos = 0;
	while (i < s->count.len_a)
	{
		if (s->a[minpos] > s->a[i])
			minpos = i;
		if (s->a[maxpos] < s->a[i])
			maxpos = i;
		i++;
	}
	ft_print(s->a, 'A', s->count.len_a);
	ft_print(s->b, 'B', s->count.len_b);
	if (maxpos > minpos)
	{
		ft_rra(s);
	}
	else if (minpos > maxpos)
	{
		ft_ra(s);
	}
	ft_print(s->a, 'A', s->count.len_a);
	ft_print(s->b, 'B', s->count.len_b);
	printf("minpos %d\nmaxpos %d \n", minpos, maxpos);
}

//void	sort_list(int *lst, int len)
void	sort_list(t_swap *s)
{
	find_min_max_in_chunck(s);
	//find_min_max_in_chunck(lst, len);



}

void	sort_100(t_swap *s)
{
	int mid;

	mid = s->count.len_a / 2;
	while (mid != s->count.len_a)
		ft_pb(s);
	sort_list(s);
	//sort_list(s->a, s->count.len_a);

	//while (s->count.len_b > 0)
	//	ft_pa(s);

	//ft_print(s->a,'A', s->count.len_a);
	//ft_print(s->b,'B', s->count.len_b);
}
