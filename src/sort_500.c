/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:33:50 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/24 18:14:35 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_500(t_swap *s)
{
	t_chunk	chunk;
	int		size;

	chunk.nb = 0;
	size = 0;
	while (!verif_table_ok(s->a, s->count.len_a + s->count.len_b))
	{
		size += SIZE_500;
		sort_list(&chunk, s, size);
	}
}
