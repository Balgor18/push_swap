/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:44:34 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/21 17:47:29 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_list(int *src, int *dst, int len)
{
	int i;

	i = 0;
	
	while (i < len)
	{
	//	printf("%d | %d \n", dst[i], src[i]);
		dst[i] = src[i];
		i++;
	}
	//printf("%d|%d\n",i,len);
}

void	pa(t_swap *s, int len)
{
	int *tmp;
	int len_tmp;

	len_tmp = s->count.len_b;
	tmp = NULL;
	if (s->count.len_b > 0)
	{
		free(s->b);
		tmp = malloc(sizeof(int *) * (s->count.len_b));
		if (!tmp)
			return;
		copy_list(s->b, tmp, s->count.len_b);
	}
	else
	{
		s->count.len_b++;
		s->b = malloc(sizeof(int *) * (s->count.len_b));
		if (!s->b)
			return;
		copy_list(s->a, s->b, s->count.len_b);
		
	}

	//	free(tmp);
	//	ft_len_table(s);
	//ft_print(tmp, 'T', len_tmp);
	printf("len a %d \n",s->len);
	ft_print(s->a, 'A', s->len);
	ft_print(s->b, 'B', s->count.len_b);
	ft_putstr_fd("pa\n", 1);
	if (len != 0)
		pa(s, len - 1);
}

void	pb(t_swap *s)
{
	s->a = malloc(sizeof(int *) * (s->count.len_a + 1));
	if (!s->a)
		return;
	ft_len_table(s);
	ft_putstr_fd("pb\n", 1);
}
