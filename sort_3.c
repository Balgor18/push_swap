/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:31:05 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/08 11:36:24 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	copy_list(int *src, int *dst, int len)
{

}

int	verif_for_ra(t_swap *s)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = malloc(sizeof(int *) * s->count.len_a);
	if (!tmp)
		return (0);
	while (++i < s->count.len_a)
	{

		tmp[i] = s->a[i];
		printf("%d | %d = %d \n", i, tmp[i], s->a[i]);
	}
	ft_print(tmp, 'T', s->count.len_a);

	ft_print(s->a, 'A', s->count.len_a);
	//printf("verif_table ok %d\n", verif_table_ok(tmp, s->count.len_a));
	//printf("%d > %d && %d \n", s->a[0], s->a[2], verif_table_ok(tmp, s->count.len_a));
/*	if (s->a[0] > s->a[2] && verif_table_ok(tmp, s->count.len_a))
	{
		free(tmp);
		return (1);
	}
	free(tmp);*/
	return (0);
}

void	verif_case(t_swap *s)
{
	//printf("%d > %d && %d < %d && %d \n", s->a[0], s->a[1], s->a[0], s->a[2], !verif_for_ra(s));
	if (!(s->a[0] < s->a[1] && s->a[0] < s->a[2]) && !verif_for_ra(s))
		ft_sa(s);
	if (s->a[2] < s->a[0])
		ft_rra(s);
	if (s->a[0] > s->a[2])
		ft_ra(s);
}

void	sort_3(t_swap *s)
{
	verif_case(s);
}
