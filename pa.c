/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:44:34 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/25 10:41:23 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_list(t_copylist *c, char ch)
{
	int	i;

	i = 0;
	if (ch == 'A')
	{
		while (c->start < c->len)
		{
			c->dest[i] = c->src[c->start];
			c->start++;
			i++;
		}
	}
	else
	{
		while (c->start < c->len)
		{
			c->dest[c->start] = c->src[i];
			c->start++;
			i++;
		}
	}
}

void	init_list_a(t_swap *s)
{
	int	*tmp;
	t_copylist	list_a;

	tmp = NULL;
	tmp = malloc(sizeof(int *) * s->count.len_a);
	init_struct_for_copy(s->a, &list_a, tmp, s->count.len_a);
	list_a.start = 1;
	copy_list(&list_a, 'A');
	s->count.len_a--;
	free(s->a);
	s->a = malloc(sizeof(int *) * s->count.len_a);
	init_struct_for_copy(tmp, &list_a, s->a, s->count.len_a);
	list_a.start = 0;
	copy_list(&list_a, 'A');
	free(tmp);
}

void	pa_bis(t_swap *s, t_copylist *list_b, int *tmp)
{
	tmp = malloc(sizeof(int *) * (s->count.len_b));
	if (!tmp)
		return;
	init_struct_for_copy(s->b, list_b, tmp, s->count.len_b);
	list_b->start = 0;
	copy_list(list_b, 'A');
	s->count.len_b++;
	s->b = malloc(sizeof(int *) * (s->count.len_b));
	if (!s->b)
		return;
	init_struct_for_copy(tmp, list_b, s->b, s->count.len_b);
	list_b->start = 1;
	copy_list(list_b, 'B');
	free(tmp);
}

void	pa(t_swap *s, int len)
{
	int	*tmp;
	t_copylist	list_b;

	tmp = NULL;
	if (s->count.len_b > 0)
		pa_bis(s, &list_b, tmp);
	else
	{
		s->count.len_b++;
		s->b = malloc(sizeof(int *) * (s->count.len_b));
		if (!s->b)
			return;
	}
	s->b[0] = s->a[0];
	init_list_a(s);
//	ft_print(s->a, 'A', s->count.len_a);
//	ft_print(s->b, 'B', s->count.len_b);
	ft_putstr_fd("pa\n", 1);
	if (len != 0)
		pa(s, len - 1);
}
