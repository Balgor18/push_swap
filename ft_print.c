/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:31:14 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/16 10:06:06 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(int *s, char c, int len)
{
	int	i;

	i = 0;
	if (len == 0)
		return ;
	ft_putstr_fd("------ ", 1);
	ft_putchar_fd(c, 1);
	ft_putstr_fd(" ------\n", 1);
	while (i < len)
	{
		ft_putstr_fd("pos ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(" | val ", 1);
		ft_putnbr_fd(s[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putstr_fd("---------------\n", 1);
}
