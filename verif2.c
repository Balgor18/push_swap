/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:58:36 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/12 16:58:47 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_isnot_char(char c)
{
	if (c != '-' && c != '+' && (c < '0' || c > '9') && c != ' ')
		return (0);
	return (1);
}
