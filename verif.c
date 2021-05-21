/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:47:47 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/21 16:50:21 by fcatinau         ###   ########.fr       */
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
			ft_ss(s);
		else if (s->b[0] > s->b[1])
			ft_sb(s);
	}
	if (s->a[0] > s->a[1])
		ft_sa(s);
	return;
}

void	verif_top_and_bot(t_swap *s)
{
	if (s->count.len_b > 0)
	{
		if ((s->a[0] > s->a[s->count.len_a - 1]) && (s->b[0] > s->b[s->count.len_b - 1]))
			ft_rr(s);
		else if (s->b[0] > s->b[s->count.len_b - 1])
			ft_rb(s);
	}
	if (s->a[0] > s->a[s->count.len_a - 1])
		ft_ra(s);
	return;
}

void	verif_swap_list(t_swap *s)
{
	int	mid;
	int	i;

	i = 0;
	mid = s->len / 2; // si 0.5 va vers le plus bas ex : 7 / 2 = 3
	printf("return %d \n",verif_table_ok(s, mid));
	if (verif_table_ok(s, mid))
		pa(s, mid - 1);
	//creer malloc b pour push b
}

int	verif_table_ok(t_swap *s, int len)
{
	int	i;

	i = 0;
	//printf("Debut de bloucle \n");
	while (i < len)
	{
		//printf("%d < %d\n", i, len);
		//printf("%d |>| %d \n",s->a[i], s->a[i + 1]);
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}
