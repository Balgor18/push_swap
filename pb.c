/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 23:52:21 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/25 11:39:23 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list_b(t_swap *s)
{
	int	*tmp;
	t_copylist	list_b;

	tmp = NULL;
	tmp = malloc(sizeof(int *) * s->count.len_b);
	init_struct_for_copy(s->b, &list_b, tmp, s->count.len_b);
	list_b.start = 1;
	copy_list(&list_b, 'A');
	s->count.len_b--;
	free(s->b);
	s->b = malloc(sizeof(int *) * s->count.len_b);
	init_struct_for_copy(tmp, &list_b, s->b, s->count.len_b);
	list_b.start = 0;
	copy_list(&list_b, 'A');
	free(tmp);
}

void	pb_bis(t_swap *s, t_copylist *list_a, int *tmp)
{
	tmp = malloc(sizeof(int *) * (s->count.len_a));
	if (!tmp)
		return;
	init_struct_for_copy(s->a, list_a, tmp, s->count.len_a);
	list_a->start = 0;
	copy_list(list_a, 'A');
	s->count.len_a++;
	s->a = malloc(sizeof(int *) * (s->count.len_a));
	if (!s->a)
		return;
	init_struct_for_copy(tmp, list_a, s->a, s->count.len_a);
	list_a->start = 1;
	copy_list(list_a, 'B');
	free(tmp);
}

void	pb(t_swap *s, int len)
{
	int	*tmp;
	t_copylist	list_a;

	tmp = NULL;
//	printf("bien le bj \n");
	if (len == 0)
		return;
	if (s->count.len_b > 0)
		pb_bis(s, &list_a, tmp);
	else
	{
		s->count.len_a++;
		s->a = malloc(sizeof(int *) * (s->count.len_a));
		if (!s->a)
			return;
	}
	s->a[0] = s->b[0];
	init_list_b(s);
//	ft_print(s->a, 'A', s->count.len_a);
//	ft_print(s->b, 'B', s->count.len_b);
	ft_putstr_fd("pb\n", 1);
	if (len != 0)
		pb(s, len - 1);
}

/*
void	pb(t_swap *s, int len)
{
		int	*tmp;
	t_copylist	list_b;

	tmp = NULL;
	if (s->count.len_b > 0)
		pa_bis(s, &list_b, tmp);
	else
	{
		s->count.len_a++;
		s->a = malloc(sizeof(int *) * (s->count.len_a));
		if (!s->a)
			return;
	}

//	s->b[0] = s->a[0];
//	init_list_a(s);

	s->a = malloc(sizeof(int *) * (s->count.len_a + 1));
	if (!s->a)
		return;
	ft_print(s->a, 'A', s->count.len_a);
	ft_print(s->b, 'B', s->count.len_b);
	ft_putstr_fd("pb\n", 1);
	if (len != 0)
		pa(s, len - 1);
}
*/
