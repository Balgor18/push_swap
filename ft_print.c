/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:31:14 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/24 15:59:14 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	blue(void)
{
	ft_putstr_fd("\033[0;34m", 1);
}

void	cyan(void)
{
	ft_putstr_fd("\033[0;36m", 1);
}

void	red(void)
{
	ft_putstr_fd("\033[0;31m", 1);
}

void	white(void)
{
	ft_putstr_fd("\033[0;37m", 1);
}

void	green(void)
{
	ft_putstr_fd("\033[0;32m", 1);
}

void	yellow(void)
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
		if (i < 50)
			green();
		else if (i < 100)
			red();
		else if (i < 150)
			cyan();
		else if (i < 200)
			blue();
		else if (i < 250)
			yellow();
		else if (i < 300)
			green();
		else if (i < 350)
			red();
		else if (i < 400)
			cyan();
		else if (i < 450)
			blue();
		else if (i < 500)
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
