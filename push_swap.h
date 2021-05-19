/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:46:36 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/19 18:49:37 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_swap
{
	int		*a;
	int		*b;
	int		len;
}				t_swap;

/*
** Init
*/
void	init_struct(t_swap *s);

// sa = move pos 1 et pos 2 de pile a SAUF SI POS < 1
// sb = move pos 1 et pos 2 de pile b SAUF SI POS < 1
// ss = sa + sb

// --------------------------------------------------

// pa = prends le 1er elem de b pour allez le mettre sur a SAUF SI B < 1
// pb = prends le 1er elem de a pour allez le mettre sur b SAUF SI A < 1

// --------------------------------------------------

// ra = decale d'une postion vers le haut de tous les elements de la liste a + first passe last
// rb = decale d'une postion vers le haut de tous les elements de la liste b + first passe last
// rr = ra + rb;

// --------------------------------------------------

// rra = decale d'une position vers le bas tout les elements de la liste a, le dernier devient le premier;
// rrb = decale d'une position vers le bas tout les elements de la liste b, le dernier devient le premier;
// rrr = rra + rrb;

#endif
