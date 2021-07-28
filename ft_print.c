/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:31:14 by fcatinau          #+#    #+#             */
/*   Updated: 2021/07/28 17:58:40 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	yellow(void)
{
	ft_putstr_fd("\033[0;33m", 1);
}

void	color(int i)
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
		white();
		ft_putstr_fd("pos ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(" | val ", 1);
		if (s[i] < s[i + 1] || s[i - 1] < s[i])
			green();
		else
			red();
		ft_putnbr_fd(s[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	white();
	ft_putstr_fd("---------------\n", 1);
}
