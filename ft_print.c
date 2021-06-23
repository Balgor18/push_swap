/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:31:14 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/23 15:48:08 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	blue()
{
	ft_putstr_fd("\033[0;34m", 1);
}

void	cyan()
{
	ft_putstr_fd("\033[0;36m", 1);
}

void	red()
{
	ft_putstr_fd("\033[0;31m", 1);
}

void	white()
{
	ft_putstr_fd("\033[0;37m", 1);
}

void	green()
{
	ft_putstr_fd("\033[0;32m", 1);
}

void	yellow()
{
	ft_putstr_fd("\033[0;33m", 1);
}


void	ft_print(int *s, char c, int len)
{
	int	i;

	i = 0;
	if (len == 0)
		return ;
	white();
	ft_putstr_fd("------ ", 1);
	ft_putchar_fd(c, 1);
	ft_putstr_fd(" ------\n", 1);
	while (i < len)
	{
		if (i < 20)
			green();
		else if (i < 40)
			red();
		else if (i < 60)
			cyan();
		else if (i < 80)
			blue();
		else if (i < 100)
			yellow();
		ft_putstr_fd("pos ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(" | val ", 1);
		ft_putnbr_fd(s[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	white();
	ft_putstr_fd("---------------\n", 1);
}
